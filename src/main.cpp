#include "main.h"
#include "robot.h"
#include "pros/misc.h"
#include "pros/motors.h"
#include "display.h"
#include "pid.h"
#include <cmath> 
#include <iostream>

using namespace std;
/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "Hello PROS User!");

	pros::lcd::register_btn1_cb(on_center_button);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

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
		
	}
}


/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */

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

	while (true) {
		/*int lalalala;
		int aaa;
		if (lf.get_actual_velocity() > 0) {
			if (lalalala < (lalalala+lf.get_actual_velocity()) /2) {
				controller.print(1, 0, "I: %d, L: %d         ", lalalala);
			}
			lalalala = (lalalala+lf.get_actual_velocity()) /2;
			pros::delay(100);
		}
*/
	//auto_selector();
	//auto_display();
		// arcade 
		int power = controller.get_analog(ANALOG_LEFT_Y);
		int turn = controller.get_analog(ANALOG_RIGHT_X);
		int left = power + turn;
		int right = power - turn;
		opsens.set_led_pwm(100);
		lf.move(left);
		lm.move(left);
		lb.move(left);
		rf.move(right);
		rm.move(right);
		rb.move(right);

		bool fastm = true;
		bool fastl = true;
		bool intptoggle;
		bool matchptoggle;

		if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_Y)) {
			fastm = !fastm;
			fastl = !fastl;
		}

		if (controller.get_digital(E_CONTROLLER_DIGITAL_R1) && controller.get_digital(E_CONTROLLER_DIGITAL_R2)) { //full outtake
			intptoggle = true;
			bint.move_velocity(-300);
			mint.move(-127);
			tint.move(0);
			//stall_pro(bint, true);
		} else if (controller.get_digital(E_CONTROLLER_DIGITAL_L2) && controller.get_digital(E_CONTROLLER_DIGITAL_R1)) {
			intptoggle = false;
			if (fastm) {
			mint.move(127);
			tint.move(127);	
			bint.move_velocity(-300);
			//stall_pro(bint, true);
			}
			else {
			mint.move_velocity(270);
			tint.move_velocity(270);
			bint.move_velocity(-300);
			//stall_pro(bint, true);
			}
		} else if (controller.get_digital(E_CONTROLLER_DIGITAL_L2) && controller.get_digital(E_CONTROLLER_DIGITAL_R2)) {
			intptoggle = true;
			if (fastl) {
			mint.move(127);
			tint.move(-127);	
			bint.move_velocity(-300);
			//stall_pro(bint, true);
			}
			else {
			mint.move_velocity(270);
			tint.move_velocity(-270);
			bint.move_velocity(-300);
			//stall_pro(bint, true);
			}
		} else if (controller.get_digital(E_CONTROLLER_DIGITAL_L1) && controller.get_digital(E_CONTROLLER_DIGITAL_R1)) {
			intptoggle = false;
			if (fastm) {
			mint.move(127);
			tint.move(127);	
			bint.move_velocity(300);
			//stall_pro(bint, false);
			}
			else {
			mint.move_velocity(270);
			tint.move_velocity(270);
			bint.move_velocity(300);
			//stall_pro(bint, false);
			}
		} else if (controller.get_digital(E_CONTROLLER_DIGITAL_L1) && controller.get_digital(E_CONTROLLER_DIGITAL_R2)) {
			intptoggle = true;
			if (fastl) {
			mint.move(127);
			tint.move(-127);	
			bint.move_velocity(300);
			//stall_pro(bint, true);
			}
			else {
			mint.move_velocity(270);
			tint.move_velocity(-270);
			bint.move_velocity(300);
			stall_pro(bint, false);
			}
		} else if (controller.get_digital(E_CONTROLLER_DIGITAL_R1)){
			intptoggle = false;
			if (fastm) {
			mint.move(127);
			tint.move(127);	
			bint.move(0);
			}
			else {
			mint.move_velocity(270);
			tint.move_velocity(270);
			bint.move(0);
			}
		} else if (controller.get_digital(E_CONTROLLER_DIGITAL_R2)){
			intptoggle = true;
			if (fastl) {
			mint.move(127);
			tint.move(-127);
			bint.move(0);
			}
			else {
			mint.move_velocity(270);
			tint.move_velocity(-270);
			bint.move(0);
			}
		} else if (controller.get_digital(E_CONTROLLER_DIGITAL_L1)){
			if (hfill.get_proximity() < 50) {
				controller.print(1,1, "%f", hfill.get_proximity());
				intptoggle = false;
				mint.move(127);
				tint.move(0);
				bint.move(127);
			} else {
				controller.print(1,1, "%f", hfill.get_hue());
				intptoggle = false;
				mint.move(127);
				tint.move(-127);
				bint.move(0);
				color_sort(20);
				}

		//red is 20 blue is 211, 0, 214
//intake into hoard
			
		} else if (controller.get_digital(E_CONTROLLER_DIGITAL_L2)) {
			intptoggle = true;
			bint.move_velocity(-300);
			//stall_pro(bint, true);
		} else {
			bint.move(0);
			mint.move(0);
			tint.move(0);

		}

		if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_UP)) {
			intptoggle  = !intptoggle;
		}
		
		intp.set_value(intptoggle);

		if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_RIGHT)) {
			matchptoggle = !matchptoggle;
		}

		matchp.set_value(matchptoggle);

				

	

		




		 if (controller.get_digital(DIGITAL_A)) {
		 	//forwardMove(1000);
			//imu.tare_rotation();
			//turnp(160);
			
		 }
		pros::delay(20);
	}
}


