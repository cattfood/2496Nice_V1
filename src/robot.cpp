#include "robot.h"
#include "pros/adi.hpp"
#include "pros/imu.hpp"
#include "pros/misc.h"
#include "pros/misc.hpp"
#include "pros/motors.h"
#include "pros/motors.hpp"

// -------- All electronic definitions -------- //

pros::Controller controller(pros::E_CONTROLLER_MASTER);

pros::Motor lf(1, MOTOR_GEARSET_06, true, MOTOR_ENCODER_DEGREES);
pros::Motor lm(2, MOTOR_GEARSET_06, true, MOTOR_ENCODER_DEGREES); 
pros::Motor lb(5, MOTOR_GEARSET_06, false, MOTOR_ENCODER_DEGREES);

pros::Motor rf(10, MOTOR_GEARSET_06, false, MOTOR_ENCODER_DEGREES); 
pros::Motor rm(19, MOTOR_GEARSET_06, true, MOTOR_ENCODER_DEGREES); 
pros::Motor rb(9, MOTOR_GEARSET_06, false, MOTOR_ENCODER_DEGREES); 

pros::Motor bint(7, MOTOR_GEARSET_06, true, MOTOR_ENCODER_DEGREES);
pros::Motor mint(4, MOTOR_GEARSET_06, false, MOTOR_ENCODER_DEGREES);
pros::Motor tint(6, MOTOR_GEARSET_06, false, MOTOR_ENCODER_DEGREES);

pros::ADIDigitalOut intp('A', false);
pros::ADIDigitalOut matchp('B', false);
