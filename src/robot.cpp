#include "robot.h"
#include "pros/adi.hpp"
#include "pros/imu.hpp"
#include "pros/misc.h"
#include "pros/misc.hpp"
#include "pros/motors.h"
#include "pros/motors.hpp"

// -------- All electronic definitions -------- //

pros::Controller controller(pros::E_CONTROLLER_MASTER);

pros::Motor lf(18, MOTOR_GEARSET_06, true, MOTOR_ENCODER_DEGREES);
pros::Motor lm(19, MOTOR_GEARSET_06, true, MOTOR_ENCODER_DEGREES); 
pros::Motor lb(20, MOTOR_GEARSET_06, false, MOTOR_ENCODER_DEGREES);

pros::Motor rf(11, MOTOR_GEARSET_06, false, MOTOR_ENCODER_DEGREES); 
pros::Motor rm(12, MOTOR_GEARSET_06, true, MOTOR_ENCODER_DEGREES); 
pros::Motor rb(13, MOTOR_GEARSET_06, false, MOTOR_ENCODER_DEGREES); 

pros::Motor bint(1, MOTOR_GEARSET_06, true, MOTOR_ENCODER_DEGREES);
pros::Motor mint(1, MOTOR_GEARSET_06, false, MOTOR_ENCODER_DEGREES);
pros::Motor tint(1, MOTOR_GEARSET_06, false, MOTOR_ENCODER_DEGREES);
