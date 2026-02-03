#include "main.h"
#include "robot.h"
#include "pros/misc.h"
#include "pros/motors.h"
#include "display.h"
#include "pid.h"
#include <cmath> 
#include <iostream>
#include <algorithm>

using namespace std;

bool matchptoggle;
bool intptoggle;
bool desct;
bool indext;
bool rampt;




void autonomous() { 
forward_move(1850, 2000, 1,1);
turnp(90, 1000);
bint.move(-127);
tint.move(127);
matchp.set_value(true);
mpist.set_value(true);
pros::delay(1000);
chassis_move(30, 30);
pros::delay(2500);
turnp(90, 1000);
forward_move(-400, 800, 1, 600);
matchp.set_value(false);
turnp(-45, 2000);
forward_move(775, 2000, 1,1);
turnp(-89, 1000);
forward_move(3300, 4000, 1,1, true, {0.45, 0, 8.5});
turnp(-135, 1000);
forward_move(730, 2000, 1,1);
turnp(-90, 2000);
forward_move(-700, 1000, 1,1);
chassis_move(-50, -50);
tint.move(-127);
pros::delay(3000);
turnp(-92, 1000);
bint.move(-127);
tint.move(127);
matchp.set_value(true);
mpist.set_value(true);
pros::delay(1000);
forward_move(700, 1500, 1, 600);
chassis_move(30, 30);
pros::delay(2500);
turnp(-87, 2000);
forward_move(-1200, 2000, 1, 600);
tint.move(-127);
chassis_move(-50, -50);
matchp.set_value(false);
pros::delay(3000);

turnp(-90, 1000);
drive_arcL(88,840, 3000, 100);
turnp(-175, 2000);
forward_move(600, 2000, 1,1);
matchp.set_value(true);
pros::delay(1000);
forward_move(1375, 4000, 1,0.5);
matchp.set_value(false);
forward_move(150, 1500, 1,0.5);
forward_move(-150, 1500, 1,0.5);
bint.move(-127);
tint.move(-127);
chassis_move(50, 50);
pros::delay(900);
turnp(145, 1000);
forward_move(1510, 3000, 1,1);
matchp.set_value(true);
turnp(-90, 2000);
bint.move(-127);
tint.move(127);
pros::delay(1000);
chassis_move(30, 30);
pros::delay(2500);

turnp(-90, 1000);
forward_move(-400, 800, 1, 600);
matchp.set_value(false);
turnp(135, 2000);
forward_move(775, 2000, 1,1);
turnp(91, 1000);
forward_move(3300, 4000, 1,1, true, {0.45, 0, 8.5});
turnp(45, 1000);
forward_move(730, 2000, 1,1);
turnp(90, 2000);
forward_move(-700, 1000, 1,1);
chassis_move(-50, -50);
tint.move(-127);
pros::delay(3000);
turnp(88, 1000);
bint.move(-127);
tint.move(127);
matchp.set_value(true);
mpist.set_value(true);
pros::delay(1000);
forward_move(700, 1500, 1, 600);
chassis_move(30, 30);
pros::delay(2500);
turnp(93, 2000);
forward_move(-1200, 2000, 1, 600);
tint.move(-127);
chassis_move(-50, -50);
matchp.set_value(false);
pros::delay(3000);
}
/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	imu.tare_rotation();
	pros::lcd::initialize();
	// pros::lcd::register_btn0_cb(on_center_button);
	controller.clear();
}
/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {
	while(true){
	}
}
/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {
    while(true) {
	controller.clear();
	}

}
/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
	bool matchptoggle;
	bool desctoggle;
	bool undtoggle;
	

	while (true) {

		int y = controller.get_analog(ANALOG_LEFT_Y);
		int power = y;
	    int x = controller.get_analog(ANALOG_RIGHT_X);
		//int turn = (x * abs(x)) / (sqrt(abs(x)) * sqrt(400));
		//int turn = (cbrt(127 * x * x) * x) / abs(x);
		int turn = (sqrt(127*abs(x)) * abs(x)) / x;
		//int turn = cbrt((127*sqrt(abs(x))) * (127*sqrt(abs(x)))) * abs(x) / x;
		int left = power + turn;
		int right = power - turn;
		
		double chassis_temp  = (lf.get_temperature() + lm.get_temperature() + lb.get_temperature() + rf.get_temperature() + rm.get_temperature() + rb.get_temperature()) / 6;
		double int_temp = (bint.get_temperature() + tint.get_temperature()) / 2;
		//controller.print(1,0, "%i", x);
	  controller.print(1,0, "%f", chassis_temp);
		controller.print(2,0, "%f", int_temp);
/*
		int lavg = (lf.get_actual_velocity() + lm.get_actual_velocity() + lb.get_actual_velocity()) / 3;

		if (lavg > 0) {
			if (lavg < (lavg + ((lf.get_actual_velocity() + lm.get_actual_velocity() + lb.get_actual_velocity()) / 3)) / 2) {
				controller.print(1, 0, "L: %d         ", lavg);
			}
			lavg = (lavg < (lavg + ((lf.get_actual_velocity() + lm.get_actual_velocity() + lb.get_actual_velocity()) / 3)) / 2);
			pros::delay(100);
		}

		int ravg = (rf.get_actual_velocity() + rm.get_actual_velocity() + rb.get_actual_velocity()) / 3;

		if (ravg > 0) {
			if (ravg < (ravg + ((rf.get_actual_velocity() + rm.get_actual_velocity() + rb.get_actual_velocity()) / 3)) / 2) {
				controller.print(2, 0, "L: %d         ", ravg);
			}
			ravg = (ravg + ((rf.get_actual_velocity() + rm.get_actual_velocity() + rb.get_actual_velocity()) / 3)) / 2;
			pros::delay(100);
		}


	*/
		
		

	//	controller.print(2, 0, "analog right x: %d         ", x);
		/*
		 r1 intake 
		 r2 top score  
		 l1 middle score  
		 l2 bottom score  
		 b descore  
		 down match load 
		 */
		 if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_DOWN)) {
			matchptoggle = !matchptoggle;
			matchp.set_value(matchptoggle);
		}

		if(controller.get_digital_new_press(E_CONTROLLER_DIGITAL_B)) {
			desctoggle = !desctoggle;
			desc.set_value(desctoggle);

		}

		if(controller.get_digital(E_CONTROLLER_DIGITAL_R1)) {
			bint.move(-127);
			tint.move(127);
			mpist.set_value(!false);
			//und.set_value(false);
		}
		else if(controller.get_digital(E_CONTROLLER_DIGITAL_R2)) {
			bint.move(-127);
			tint.move(-127);
			mpist.set_value(!false);
			//und.set_value(false);
		}
		else if(controller.get_digital(E_CONTROLLER_DIGITAL_L1)) {
			tint.move_velocity(450);
			bint.move_velocity(-450);
			//und.set_value(false);
			mpist.set_value(!true);

		}
		else if(controller.get_digital(E_CONTROLLER_DIGITAL_L2)) {
			tint.move(127);
			bint.move(127);
			//und.set_value(false);
			mpist.set_value(!true);

		}
		else if(controller.get_digital_new_press(E_CONTROLLER_DIGITAL_LEFT)) {
			undtoggle = !undtoggle;
			und.set_value(undtoggle);
		}
		else {
			bint.move(0);
			tint.move(0);
		}



		if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_A)) {
			autonomous();
		}

	lf.move(left);
	lm.move(left);
	lb.move(left);
	rf.move(right);
	rm.move(right);
	rb.move(right);
	}
}
			




