#include "main.h"
#include "robot.h"
#include "pid.h"
#include "timer.hpp"

// clean up this fuckass code 

//


pidConstants t_consts;
int error = 0;
int error2 = 0;
int error3 = 0;
int prevError = 0;
int integral = 0;
int derivative = 0;
float power = 0;
double trueTarget = 0;
int time2;
double STRAIGHT_INTEGRAL_KI = 200;
double STRAIGHT_MAX_INTEGRAL = 20;
float ARC_HEADING_KP = 0;
float ARC_HEADING_KI = 0;
float ARC_HEADING_KD = 0;
double ARC_HEADING_INTEGRAL_KI = 0;
double ARC_HEADING_MAX_INTEGRAL = 0;

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
    prevError = error2;
    error2 = target - input;


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


    derivative = error2 - prevError;


    power = t_consts.p*error2 + t_consts.i*integral + t_consts.d*derivative;


    return power;
}

float calc3 (float target, float input, float integralKI, int maxI) {
    prevError = error3;
    error3 = target - input;


    if(std::abs(error3) < integralKI) {
        integral += error3;            
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


    derivative = error3 - prevError;


    power = t_consts.p*error3 + t_consts.i*integral + t_consts.d*derivative;


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


void forwardMove(float target, float timeout, float endsp, pidConstants constants, pidConstants constants2) {
    error = 0;
    prevError = 0;
    integral = 0;
    derivative = 0;
    setConstants(constants);

    Timer t1;
    float voltage;
    float encoder_avg;
    int count = 0;


    resetEncoders();
       while (t1.time() <= timeout){
        encoder_avg = (lf.get_position() + rf.get_position()) / 2;
        float base_voltage = calc(target, encoder_avg, 200, 20);

    // Scale output based on distance left (slows near target)
    float slowdown = std::min(0.6f, static_cast<float>(fabs(error) / 500.0f));  
       slowdown = std::max(slowdown, 0.8f);
    // 500 = distance over which to slow down, tune this
    voltage = base_voltage * slowdown;




        chassisMove(voltage, voltage);
        if (abs(target - encoder_avg) <= 5) {
            controller.print(1, 0, "%f", 6.76767);
            break;
        }
        if (abs(error) <= 30) setConstants(constants2);
       // if (count >=2) {
      //      controller.print(1, 0, "f", "hello!");
     //       break;
     //   }
                                                       
        pros::delay(10);
        controller.print(1, 0, "%f", target - encoder_avg);
    }
    chassisMove(0,0);
}

void forwardMoveInt(float target, float endsp, pidConstants constants, pidConstants constants2) {
    setConstants(constants);

    Timer t1;
    float voltage;
    float encoder_avg;
    int count = 0;


    resetEncoders();
       while (count <= 2){
        //mint.move(127);
		//bint.move(127);
        encoder_avg = (lf.get_position() + rf.get_position()) / 2;
        if (abs(error) >= 1000) {
            voltage = calc(target, encoder_avg, 200, 20);
        }
        else {
            voltage = endsp * calc(target, encoder_avg, 200, 20);
        }



       // if (abs(error) >= 800) {
            chassisMove(voltage, voltage);
      //  }
       // else {
        //    chassisMove(endsp*voltage, endsp*voltage);
       // }
        if (abs(error) <= 50) count++;
        if (abs(error) <= 30) setConstants(constants2);
        if (count >=2) break;
                                                       
        pros::delay(10);
        //controller.print(1, 0, "%f", error);
    }
    chassisMove(0,0);
    //mint.move(0);
   // bint.move(0);
}


void turnp(float target, pidConstants constants, pidConstants constants2) {

    // error = 0;
    prevError = 0;
    //integral = 0;
   // derivative = 0;

    Timer t1;
    setConstants(constants);

    float voltage;
    float position;
    int count = 0;


    while(true) {
        position = imu.get_rotation();
        voltage = calc(target, position, 5, 100);


        chassisMove(voltage, -voltage);
        if (abs(error) <= 2) count++;
        if (abs(error) <= 3) setConstants(constants2);
       // if (count >=16) break;

        pros::delay(10);
        controller.print(1,1, "%f", (target - position));
    }
    chassisMove(0,0);
}



void driveArcL(double theta, double radius, int timeout, int speed){
    setConstants({0.1, 0, 0}); // straights

    Timer t1;
    

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
    rtarget = double((theta / 360) * 2 * pi * (radius + 500));

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

        
  

        setConstants({ARC_HEADING_KP,ARC_HEADING_KI,ARC_HEADING_KD}); // arc consts
        int fix = calc3((trueTarget + leftcorrect), position, ARC_HEADING_INTEGRAL_KI, ARC_HEADING_MAX_INTEGRAL);
        totalError += error3;
    
        chassisMove((voltageL + fix), (voltageR - fix));
        if ((abs(ltarget - encoderAvgL) <= 4) && (abs(rtarget - encoderAvgR) <= 4)) count++;
        if (count >= 20 || time2 > timeout){
            trueTarget -= theta;
           // break;
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

