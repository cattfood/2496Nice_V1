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
double trueTarget = 0;

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

float calc2 (float target, float input, float integralKI, int maxI) {
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

float calc3 (float target, float input, float integralKI, int maxI) {
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


void forwardMove(float target, pidConstants constants, pidConstants constants2) {
    setConstants(constants);

    Timer t1;
    float voltage;
    float encoder_avg;
    int count = 0;


    resetEncoders();
       while (true){
        encoder_avg = (lf.get_position() + rf.get_position()) / 2;
        voltage = calc(target, encoder_avg, 200, 20);




        chassisMove(voltage, voltage);
        if (abs(error) <= 3) count++;
        if (abs(error) <= 30) setConstants(constants2);
        //if (count >=20) break;
                                                       
        pros::delay(10);
        controller.print(1, 0, "I: %d, L: %d         ", error);
    }
    chassisMove(0,0);
}


void turnp(float target, pidConstants constants, pidConstants constants2) {
    Timer t1;
    setConstants(constants);

    float voltage;
    float position;
    int count = 0;


    while(true) {
        position = imu.get_rotation();
        voltage = calc(target, position, 5, 100);


        chassisMove(voltage, -voltage);
        if (abs(error) <= 1) count++;
        if (abs(error) <= 8) setConstants(constants2);
        //if (count >= 16) break;

        pros::delay(10);
        controller.print(1,1, "%f", (target - position));
    }
    chassisMove(0,0);
}

/*

void driveArcL(double theta, double radius, int timeout, int speed){
    setConstants({0.1, 0, 0});
    

    //int timeout = 30000;

    double totalError = 0;

    double ltarget = 0;
    double rtarget = 0;
    double pi = 3.14159265359;
    int count = 0;
    time2 = 0;
    resetEncoders();
    controller.clear();
    //int timeout = 5000;
    ltarget = double((theta / 360) * 2 * pi * radius); 
    rtarget = double((theta / 360) * 2 * pi * (radius + 455));

    while (true){
        double encoderAvgL = (lf.get_position() + lb.get_position()) / 2;
        double encoderAvgR = (rf.get_position() +  rb.get_position()) / 2;
        double leftcorrect = -(encoderAvgL * 360) / (2 * pi * radius);

        if(trueTarget > 180){
            trueTarget = trueTarget - 360;
        }

        double position = imu.get_heading(); //this is where the units are set to be degrees W

        if (position > 180){
            position = position - 360;
        }

        if(((trueTarget + leftcorrect)< 0) && (position > 0)){
            if((position - (trueTarget + leftcorrect)) >= 180){
                leftcorrect = leftcorrect + 360;
                position = imu.get_heading();
            } 
        } else if (((trueTarget + leftcorrect) > 0) && (position < 0)){
            if(((trueTarget + leftcorrect) - position) >= 180){
            position = imu.get_heading();
            }
        } 
    
        setConstants({0.1, 0, 0});
        int voltageL = calc(ltarget, encoderAvgL, STRAIGHT_INTEGRAL_KI, STRAIGHT_MAX_INTEGRAL);

        if(voltageL > 127 * double(speed)/100.0){
            voltageL = 127 * double(speed)/100.0;
        } else if (voltageL < -127 * double(speed)/100.0){
            voltageL = -127 * double(speed)/100.0;
        }


        int voltageR = calc2(rtarget, encoderAvgR, STRAIGHT_INTEGRAL_KI, STRAIGHT_MAX_INTEGRAL);

        if(voltageR > 127 * double(speed)/100.0){
            voltageR = 127 * double(speed)/100.0;
        } else if (voltageR < -127 * double(speed)/100.0){
            voltageR = -127 * double(speed)/100.0;
        }

        
  

        setConstants(ARC_HEADING_KP, ARC_HEADING_KI, ARC_HEADING_KD);
        int fix = calc3((trueTarget + leftcorrect), position, ARC_HEADING_INTEGRAL_KI, ARC_HEADING_MAX_INTEGRAL);
        totalError += error3;
    
        chassisMove((voltageL + fix), (voltageR - fix));
        if ((abs(ltarget - encoderAvgL) <= 4) && (abs(rtarget - encoderAvgR) <= 4)) count++;
        if (count >= 20 || time2 > timeout){
            trueTarget -= theta;
            break;
        } 

        if (time2 % 50 == 0 && time2 % 100 != 0 && time2 % 150 != 0){
            controller.print(0, 0, "ERROR: %f           ", float(error));
        } else if (time2 % 100 == 0 && time2 % 150 != 0){
            controller.print(1, 0, "fix: %f           ", float(fix));
        } else if (time2 % 150 == 0){
            controller.print(2, 0, "truetar: %f        ", float(trueTarget));
        } 

        time2 += 10;
        pros::delay(10);

    }
    
}

*/