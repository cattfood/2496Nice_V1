#include "main.h"
#include "robot.h"
#include "pid.h"
#include "timer.hpp"

pidConstants t_consts;
int error = 0;
int prevError = 0;
int integral = 0;
int derivative = 0;
float power = 0;

void setConstants(pidConstants constants) {
    t_consts = constants;
}

float calc (float target, float input, float integralKI, int maxI) {
    prevError = error;
    error = target - input;


    if(std::abs(error) < integralKI) {
        integral += error;            
    }
    else {
        integral = 0;
    }
   
    if (integral >= 0) {
        integral = std::min(integral, maxI);
    }
    else {
        integral = std::max(integral, -maxI);
    }


    derivative = error - prevError;


    power = t_consts.p*error + t_consts.i*integral + t_consts.d*derivative;


    return power;
}


void resetEncoders() {
   
    lf.tare_position();
    lm.tare_position();
    lb.tare_position();
    rf.tare_position();
    rm.tare_position();
    rb.tare_position();
   
}


void chassisMove(int left, int right) {
    lf.move(left);
    lm.move(left);
    lb.move(left);
    rf.move(right);
    rm.move(right);
    rb.move(right);
}


void forwardMove(float target, int timeout, pidConstants constants) {
    setConstants(constants);

    Timer t1;
    float voltage;
    float encoder_avg;
    int count = 0;


    resetEncoders();
       while (t1.time() < timeout){
        encoder_avg = (lf.get_position() + rf.get_position()) / 2;
        voltage = calc(target, encoder_avg, 200, 20);




        chassisMove(voltage, voltage);
        if (abs(target - encoder_avg) <= 3) count++;
        if (count >= 28) break; //breaks out of while loop if about 300 milliseconds within the 3 tick range
                                                       
        pros::delay(10);
    }
    chassisMove(0, 0);
}


void turn(float target, int timeout, pidConstants constants) {
    Timer t1;
    t_consts = constants;

    float voltage;
    float position;
    int count = 0;


    while(t1.time() < timeout) {
        position = imu.get_rotation();
        voltage = calc(target, position, 5, 100);


        chassisMove(voltage, -voltage);
        if (abs(target - position) <= 1) {
            count++;
        }
        // if (count >= 16) break;

        pros::delay(10);
        controller.print(1,1, "%f", (target - position));
    }
    chassisMove(0,0);
}