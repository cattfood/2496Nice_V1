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




pros::Motor lf(13, MOTOR_GEARSET_06, true, MOTOR_ENCODER_DEGREES);
pros::Motor lm(12, MOTOR_GEARSET_06, false, MOTOR_ENCODER_DEGREES); 
pros::Motor lb(20, MOTOR_GEARSET_06, true, MOTOR_ENCODER_DEGREES);

pros::Motor rf(2, MOTOR_GEARSET_06, false, MOTOR_ENCODER_DEGREES); 
pros::Motor rm(17, MOTOR_GEARSET_06, true, MOTOR_ENCODER_DEGREES); 
pros::Motor rb(15, MOTOR_GEARSET_06, false, MOTOR_ENCODER_DEGREES); 

pros::Motor bint(6, MOTOR_GEARSET_06, true, MOTOR_ENCODER_DEGREES); 
//pros::Motor mint(13, MOTOR_GEARSET_06, false, MOTOR_ENCODER_DEGREES);
pros::Motor tint(18, MOTOR_GEARSET_06, false, MOTOR_ENCODER_DEGREES); //need port

pros::ADIDigitalOut und('F', false);
pros::ADIDigitalOut desc('B', false);
pros::ADIDigitalOut mpist('C', true);
pros::ADIDigitalOut matchp('H', false);


pros::Imu imu(8);
pros::Optical opsens(17);
pros::Optical hfill(3);



