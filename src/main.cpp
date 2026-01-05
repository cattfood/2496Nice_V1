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
	//forward_move(600, 100000000, 1,1);
	//forward_move(2000, 100000000, 1,1, true, {0.15, 0, 0},  {2.5, 0, 0});
	//turnp(180, 10000000, {1, 0, 6.8}, {19.9, 0, 0});
	//turnp(150, 10000000, {1, 0, 6.7}, {19.9, 0, 0});
	//turnp(135, 10000000, {1, 0, 6.22}, {19.9, 0, 0});
	//turnp(120, 10000000, {1, 0, 5.8}, {19.9, 0, 0});
	//turnp(60, 10000000, {1, 0, 1.1}, {19.9, 0, 0});
	//turnp(45, 10000000, {1.12, 0, 0}, {19.9, 0, 0});
	//drive_arcL(90, 600, 3000, 100);
	//turnp(-90, 400);+
	//drive_arcL(-90, 600, 3000, 100);
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


	
		
		int bpower = controller.get_analog(ANALOG_LEFT_Y);
		int power = (bpower*bpower*bpower) / 16129;
	    int bturn = controller.get_analog(ANALOG_RIGHT_X);
        int turn = (bturn*bturn * bturn) / 16129;
		int left = power + turn;
		int right = power - turn;
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
			mpist.set_value(true);
			und.set_value(false);
		}
		else if(controller.get_digital(E_CONTROLLER_DIGITAL_R2)) {
			bint.move(-127);
			tint.move(-127);
			mpist.set_value(true);
			und.set_value(false);
		}
		else if(controller.get_digital(E_CONTROLLER_DIGITAL_L1)) {
			tint.move(127);
			bint.move(-127);
			und.set_value(false);
			mpist.set_value(false);

		}
		else if(controller.get_digital(E_CONTROLLER_DIGITAL_L2)) {
			tint.move(-127);
			bint.move(-127);
			und.set_value(false);
			mpist.set_value(false);

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
			




