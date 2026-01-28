#include "main.h"
#include "robot.h"
#include "pid.h"
#include "timer.hpp"




pidConstants t_consts;
int error = 0;
int prev_error = 0;
int integral = 0;
int derivative = 0;
float power = 0;

int error2 = 0;
int prev_error2 = 0;
int integral2 = 0;
int derivative2 = 0;
float power2 = 0;

int error3 = 0;
int prev_error3 = 0;
int integral3 = 0;
int derivative3 = 0;
float power3 = 0;


double true_target = 0;
int time2;
double STRAIGHT_INTEGRAL_KI = 200;
double STRAIGHT_MAX_INTEGRAL = 20;
float ARC_HEADING_KP = 0;
float ARC_HEADING_KI = 0;
float ARC_HEADING_KD = 0;
double ARC_HEADING_INTEGRAL_KI = 200;
double ARC_HEADING_MAX_INTEGRAL = 20;

float variable_kd(float x) {
    return 0.000000000001732739*pow(x,7)  - 0.000000001263293*pow(x,6) + 0.0000003789243*pow(x, 5) + -0.00006034489*pow(x,4) + 0.00548546*pow(x,3) + -0.2836335*pow(x,2) + 7.764479 * x - 68.31536;
}

float good_vkd(float x) {
    if (0 > variable_kd(x)) {
        return 0;
    }
    else {
        return variable_kd(x);
    }
}

void set_constants(pidConstants constants) {
    t_consts = constants;
}

double get_true_error(double target, double input) {
    double error = target - input;

    while(error > 180) {
        error -= 360;
    }

    while (error < -180) {
        error+=360;
    }

    return error;
}

double get_heading_error(double target, double current, double kp) {
    double error = target - current;

    // Wrap error to [-180, 180] so PID always takes shortest path
    while (error > 180) error -= 360;
    while (error < -180) error += 360;

    return error *kp;
}

float calc (float target, float input, float integralKI, int maxI) {
    prev_error = error;
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


    derivative = error - prev_error;


    power = t_consts.p*error + t_consts.i*integral + t_consts.d*derivative;
   // controller.print(2, 0, "L: %f           ", power);

    return power;
}

float calc2 (float target, float input, float integralKI, int maxI) {
    prev_error2 = error2;
    error2 = target - input;


    if(std::abs(error2) < integralKI) {
        integral2 += error2;            
    }
    else {
        integral2 = 0;
    }
   
    if (integral2 >= 0) {
        integral2 = std::min(integral2, maxI);
    }
    else {
        integral2 = std::max(integral2, -maxI);
    }


    derivative2 = error2 - prev_error2;


    power2 = t_consts.p*error2 + t_consts.i*integral2 + t_consts.d*derivative2;


    return power2;
}

float calc3 (float target, float input, float integralKI, int maxI) {
    prev_error3 = error3;
    error3 = target - input;


    if(std::abs(error3) < integralKI) {
        integral3 += error3;            
    }
    else {
        integral3 = 0;
    }
   
    if (integral3 >= 0) {
        integral3 = std::min(integral3, maxI);
    }
    else {
        integral3 = std::max(integral3, -maxI);
    }


    derivative3 = error3 - prev_error3;


    power3 = t_consts.p*error3 + t_consts.i*integral + t_consts.d*derivative;


    return power3;
}

void reset_encoders() {
   
    lf.tare_position();
    lm.tare_position();
    lb.tare_position();
    rf.tare_position();
    rm.tare_position();
    rb.tare_position();
   
}

void chassis_move(int left, int right) {
    lf.move(left);
    lm.move(left);
    lb.move(left);
    rf.move(right);
    rm.move(right);
    rb.move(right);
}

void forward_move(float target, float timeout, float endsp, float dist, bool headc, pidConstants constants, pidConstants constants2) {
    error = 0;
    prev_error = 0;
    integral = 0;
    derivative = 0;
    set_constants(constants);
   // double position = imu.get_heading(); // degrees
    controller.clear();

    Timer t1;
    float voltage;
    float encoder_avg;
    int count = 0;

  
    reset_encoders();
       while (t1.time() <= timeout){
      //while (true){
        encoder_avg = (lf.get_position() + rf.get_position()) / 2;
        float base_voltage = calc(target, encoder_avg, 200, 20);

    // Scale output based on distance left (slows near target)
    float slowdown = std::min(endsp, static_cast<float>(fabs(error) / dist));  
      // slowdown = std::max(slowdown, 0.4f);
    // 10 = distance over which teo slowS down, tune this
    voltage = base_voltage * slowdown;

    double position = imu.get_heading(); // degrees
double poserror = get_heading_error(true_target, position, 1); // wrapped to [-180,180] //replace position with true target


// If using simple proportional heading correction:
double kH = 4.5; // tune this
double correction = kH * poserror;

// Apply voltage limits
if (voltage > 127) voltage = 127;
if (voltage < -127) voltage = -127;

// Drive with heading correction
chassis_move(voltage + correction, voltage - correction);

controller.print(0, 0, "ERROR: %f           ", float(error));
    
        if (abs(error) <= 10) set_constants(constants2);
       
     
        if (abs(error) < 1) {
            count++;
        }
        
        if(count > 20) {
            break;
        }
            
        pros::delay(10);

        
        controller.print(0, 0, "%.2f", target - encoder_avg);
    }
        
    chassis_move(0,0);
}

void forward_movem(float target, float timeout, float endsp, float dist, bool headc, pidConstants constants, pidConstants constants2) {
    error = 0;
    prev_error = 0;
    integral = 0;
    derivative = 0;
    set_constants(constants);
   // double position = imu.get_heading(); // degrees
    controller.clear();

    Timer t1;
    float voltage;
    float encoder_avg;
    int count = 0;

  
    reset_encoders();
      // while (t1.time() <= timeout){
      while (true){
        encoder_avg = (lf.get_position() + rf.get_position()) / 2;
        float base_voltage = calc(target, encoder_avg, 200, 20);

    // Scale output based on distance left (slows near target)
    float slowdown = std::min(endsp, static_cast<float>(fabs(error) / dist));  
      // slowdown = std::max(slowdown, 0.4f);
    // 10 = distance over which teo slowS down, tune this
    voltage = base_voltage * slowdown;

    double position = imu.get_heading(); // degrees
double poserror = get_heading_error(true_target, position, 1); // wrapped to [-180,180] //replace position with true target


// If using simple proportional heading correction:
double kH = 4.5; // tune this
double correction = kH * poserror;

// Apply voltage limits
if (voltage > 127) voltage = 127;
if (voltage < -127) voltage = -127;

// Drive with heading correction
chassis_move(voltage + correction, voltage - correction);

controller.print(0, 0, "ERROR: %f           ", float(error));
    
        if (abs(error) <= 10) set_constants(constants2);
        if(abs(error) <= 200) matchp.set_value(true);
       
     
        if (abs(error) < 1) {
            count++;
        }
        
        if(count > 20) {
           // break;
        }
            
        pros::delay(10);

        
        controller.print(0, 0, "%.2f", target - encoder_avg);
    }
        
    chassis_move(0,0);
}
void turnp(float target, float timeout, pidConstants constants, pidConstants constants2, double feedforward ) {
    error = 0;
    prev_error = 0;
    integral = 0;
    derivative = 0;
    power = 0;
    double position1 = imu.get_heading();
    pidConstants turnpid = {2.5, 0, good_vkd(abs(get_true_error(target, position1)))};
  // pidConstants turnpid = {2.5, 0, 0};
  // pidConstants turnpid = {2.5, 0, 0.05}; // 15
  // pidConstants turnpid = {2.5, 0, 17}; // 30
  //pidConstants turnpid = {2.5, 0, 19}; // 45
 // pidConstants turnpid = {2.5, 0, 20}; // 60
 //pidConstants turnpid = {2.5, 0, 21}; // 75
  //pidConstants turnpid = {2.5, 0, 21.5}; // 90
 // pidConstants turnpid = {2.5, 0, 22.3}; // 110
  //pidConstants turnpid = {2.5, 0, 22.6}; // 125
//pidConstants turnpid = {2.5, 0, 23.8}; // 150 // i tuned up to here
 //pidConstants turnpid = {2.5, 0, 23.4}; // 165
  //pidConstants turnpid = {2.5, 0, 24.2}; // 180
 //controller.print(0, 0, "%f", get_true_error(target, position1));
   set_constants(turnpid);

    true_target = target;

    int count = 0;
    controller.clear();
    Timer t1;
   // while (true){

    while (t1.time() < timeout) {
    
        double position = imu.get_heading(); // 0–360
        double heading_error = target - position;

        if (heading_error > 180) heading_error -= 360;
        if (heading_error < -180) heading_error += 360;


        double voltage = calc(0, -heading_error, 5, 100); 
        voltage *= feedforward;

        voltage = std::clamp(voltage, -127.0, 127.0);
        chassis_move(voltage, -voltage);

        if (fabs(heading_error) < 2) set_constants(constants2);
        if (fabs(heading_error) < 0.5) count++;
        else count = 0;

        if (count >= 7) break;  

        pros::delay(10);
        controller.print(0, 0, "Err: %.2f", heading_error);
      // controller.print(0, 0, "Err: %.2f", variable_kd(target));
    }
    chassis_move(0, 0);
} 

void turnpl(float target, float timeout, pidConstants constants, pidConstants constants2, double feedforward ) {
    error = 0;
    prev_error = 0;
    integral = 0;
    derivative = 0;
    power = 0;
    pidConstants turnpid = {2.5, 0, variable_kd(target)};
   //pidConstants turnpid = {2.5, 0, 0}; // 15
  // pidConstants turnpid = {2.5, 0, 16}; // 30
  //pidConstants turnpid = {2.5, 0, 17}; // 45
  //pidConstants turnpid = {2.5, 0, 17.8}; // 60
  //pidConstants turnpid = {2.5, 0, 18.5}; // 75
  //pidConstants turnpid = {2.5, 0, 20}; // 90
  //pidConstants turnpid = {2.5, 0, 20.7}; // 110
  //pidConstants turnpid = {2.5, 0, 22}; // 125
 // pidConstants turnpid = {2.5, 0, 23}; // 150
 //pidConstants turnpid = {2.5, 0, 24}; // 165
 // pidConstants turnpid = {2.5, 0, 24.8}; // 180
   set_constants(turnpid);
  
    true_target = target;

    int count = 0;
    controller.clear();
    Timer t1;
   // while (true){

    while (t1.time() < timeout) {
    
        double position = imu.get_heading(); // 0–360
        double heading_error = target - position;

        if (heading_error > 180) heading_error -= 360;
        if (heading_error < -180) heading_error += 360;


        double voltage = calc(0, -heading_error, 5, 100); 
        voltage *= feedforward;

        voltage = std::clamp(voltage, -127.0, 127.0);
        chassis_move(0, -voltage);

        if (fabs(heading_error) < 2) set_constants(constants2);
        if (fabs(heading_error) < 0.5) count++;
        else count = 0;

        if (count >= 7) break;  

        pros::delay(10);
        controller.print(0, 0, "Err: %.2f", heading_error);
      // controller.print(0, 0, "Err: %.2f", variable_kd(target));
    }
    chassis_move(0, 0);
} 

 
void drive_arcL(double theta, double radius, int timeout, int speed){
     //set_constants({10, 0, 0}); // straights

    Timer t1;
    

    //int timeout = 30000;

    double totalError = 0;

    double ltarget = 0;
    double rtarget = 0;
    double pi = 3.14159265359;
    int count = 0;
    time2 = 0;
    reset_encoders();
    controller.clear();
    
    //int timeout = 5000;
    ltarget = double((theta / 360) * 2 * pi * radius); 
    rtarget = double((theta / 360) * 2 * pi * (radius + 500));

    while (true){
        double encoderAvgL = (lf.get_position() + lb.get_position()) / 2;
        double encoderAvgR = (rf.get_position() +  rb.get_position()) / 2;
        double leftcorrect = -(encoderAvgL * 360) / (2 * pi * radius);

        if(true_target > 180){
            true_target = true_target - 360;
        }

        double position = imu.get_heading(); //this is where the units are set to be degrees W

        if (position > 180){
            position = position - 360;
        }

        if(((true_target + leftcorrect)< 0) && (position > 0)){
            if((position - (true_target + leftcorrect)) >= 180){
                leftcorrect = leftcorrect + 360;
                position = imu.get_heading();
            } 
        } else if (((true_target + leftcorrect) > 0) && (position < 0)){
            if(((true_target + leftcorrect) - position) >= 180){
            position = imu.get_heading();
            }
        } 
    
        set_constants({0.5, 0, 0});
        int voltageL = calc(ltarget, encoderAvgL, 200, 20);

        
         if(voltageL > 127 * double(speed)/100.0){
            voltageL = 127 * double(speed)/100.0;
        } else if (voltageL < -127 * double(speed)/100.0){
            voltageL = -127 * double(speed)/100.0;
        }

       // controller.print(0, 0, "L: %i           ", voltageL);



        int voltageR = calc2(rtarget, encoderAvgR, 200, 20);
       // controller.print(0, 0, "L: %f           ", voltageR);

        if(voltageR > 127 * double(speed)/100.0){
            voltageR = 127 * double(speed)/100.0;
        } else if (voltageR < -127 * double(speed)/100.0){
            voltageR = -127 * double(speed)/100.0;
        }

        
  

        set_constants({5, 0, 0}); // arc consts
        int fix = calc3((true_target + leftcorrect), position, ARC_HEADING_INTEGRAL_KI, ARC_HEADING_MAX_INTEGRAL);
        totalError += error3;
    
        chassis_move((voltageL + fix), (voltageR - fix));
        if ((abs(ltarget - encoderAvgL) <= 4) && (abs(rtarget - encoderAvgR) <= 4)) count++;
        if (count >= 20 || time2 > timeout){
            true_target -= theta;
           // break;
        } 
        
        if (time2 % 50 == 0 && time2 % 100 != 0 && time2 % 150 != 0){
            controller.print(0, 0, "ERROR: %f           ", float(error));
        } else if (time2 % 100 == 0 && time2 % 150 != 0){
            controller.print(1, 0, "fix: %f           ", float(fix));
        } else if (time2 % 150 == 0){
            controller.print(2, 0, "truetar: %f        ", float(true_target));
        } 
        
        time2 += 10;
        pros::delay(10);

    }
    
}

void driveArcR(double theta, double radius, int timeout, int speed, bool test){

    //set_constants({0.1, 0, 0}); // straights

    Timer t1;
    

    //int timeout = 30000;

    double total_error = 0;

    double ltarget = 0;
    double rtarget = 0;
    double pi = 3.14159265359;
    int count = 0;
    time2 = 0;
    reset_encoders();
    controller.clear();
    //int timeout = 5000;
    ltarget = double((theta / 360) * 2 * pi* (radius + 500)); 
    rtarget = double((theta / 360) * 2 * pi * radius);

    while (true){
        double encoder_avgL = (lf.get_position() + lb.get_position()) / 2;
        double encoder_avgR = (rf.get_position() +  rb.get_position()) / 2;
        double right_correct = (encoder_avgR * 360) / (2 * pi * radius);

        if(true_target > 180){
            true_target = true_target - 360;
        }

        double position = imu.get_heading(); //this is where the units are set to be degrees W

        if (position > 180){
            position = position - 360;
        }

        if(((true_target + right_correct)< 0) && (position > 0)){
            if((position - (true_target + right_correct)) >= 180){
                right_correct += 360;
                position = imu.get_heading();
            } 
        } else if (((true_target + right_correct) > 0) && (position < 0)){
            if(((true_target + right_correct) - position) >= 180){
            position = imu.get_heading();
            }
        } 
    
        set_constants({0.1, 0, 0});
        
        int voltageL = calc(ltarget, encoder_avgL, STRAIGHT_INTEGRAL_KI, STRAIGHT_MAX_INTEGRAL);

        if(voltageL > 127 * double(speed)/100.0){
            voltageL = 127 * double(speed)/100.0;
        } else if (voltageL < -127 * double(speed)/100.0){
            voltageL = -127 * double(speed)/100.0;
        }


        int voltageR = calc2(rtarget, encoder_avgR, STRAIGHT_INTEGRAL_KI, STRAIGHT_MAX_INTEGRAL);

        if(voltageR > 127 * double(speed)/100.0){
            voltageR = 127 * double(speed)/100.0;
        } else if (voltageR < -127 * double(speed)/100.0){
            voltageR = -127 * double(speed)/100.0;
        }

        
  
        if (test) {
                  set_constants({6, 0, 0}); // arc consts
        }
        else {
            set_constants({6, 0, 0}); // arc consts
        }
        int fix = calc3((true_target + right_correct), position, ARC_HEADING_INTEGRAL_KI, ARC_HEADING_MAX_INTEGRAL);
        total_error += error3;
    
        chassis_move((voltageL + fix), (voltageR - fix));
        if ((abs(ltarget - encoder_avgL) <= 4) && (abs(rtarget - encoder_avgR) <= 4)) count++;
        if (count >= 20 || time2 > timeout){
            true_target += theta;
            break;
        } 

        if (time2 % 50 == 0 && time2 % 100 != 0 && time2 % 150 != 0){
            controller.print(0, 0, "ERROR: %f           ", float(error));
        } else if (time2 % 100 == 0 && time2 % 150 != 0){
            controller.print(1, 0, "fix: %f           ", float(fix));
        } else if (time2 % 150 == 0){
            controller.print(2, 0, "truetar: %f        ", float(true_target));
        } 

        time2 += 10;
        pros::delay(10);

    }
    
}
    
