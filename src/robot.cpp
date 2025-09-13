#include "robot.h"
#include "pros/adi.hpp"
#include "pros/imu.hpp"
#include "pros/misc.h"
#include "pros/misc.hpp"
#include "pros/motors.h"
#include "pros/motors.hpp"
#include <string>
using namespace std;

pros::Controller controller(pros::E_CONTROLLER_MASTER);

pros::Motor lf(1, MOTOR_GEARSET_06, true, MOTOR_ENCODER_DEGREES);
pros::Motor lm(13, MOTOR_GEARSET_06, true, MOTOR_ENCODER_DEGREES); 
pros::Motor lb(12, MOTOR_GEARSET_06, false, MOTOR_ENCODER_DEGREES);

pros::Motor rf(10, MOTOR_GEARSET_06, false, MOTOR_ENCODER_DEGREES); 
pros::Motor rm(8, MOTOR_GEARSET_06, true, MOTOR_ENCODER_DEGREES); 
pros::Motor rb(16, MOTOR_GEARSET_06, false, MOTOR_ENCODER_DEGREES); 

pros::Motor bint(7, MOTOR_GEARSET_06, true, MOTOR_ENCODER_DEGREES);
pros::Motor mint(5, MOTOR_GEARSET_06, false, MOTOR_ENCODER_DEGREES);
pros::Motor tint(6, MOTOR_GEARSET_06, false, MOTOR_ENCODER_DEGREES);

pros::ADIDigitalOut intp('A', false);
pros::ADIDigitalOut matchp('E', false);

pros::Optical opsens(17);
pros::Optical hfill(3);

pros::Imu imu(11);

void stall_pro(pros::Motor m , bool rev) {
    if (m.get_actual_velocity() == 0) {
        pros::delay(60);
        if (m.get_actual_velocity() == 0) {
            if (rev) {
                m.move(127);
                pros::delay(60);
                m.move(-127);
            }
            else {
                m.move(-127);
                pros::delay(60);
                m.move(127);
            }
        }
    }
}

void color_sort(int hue) {
        if ( hue - 7 < opsens.get_hue() &&  opsens.get_hue() < hue + 7) {
            intp.set_value(true);
            pros::delay(250);
        } 
}

