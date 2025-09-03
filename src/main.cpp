#include "main.h"
#include "robot.h"
#include "pros/misc.h"
#include "pros/motors.h"
#include "display.h"
#include "pid.h"
#include <cmath> 
#include <iostream>

using namespace std;

bool matchptoggle;
bool intptoggle;

void autonomous() {
	intp.set_value(true);
	mint.move(127);
	bint.move(127);
	forwardMove(1450, 1800, 0.35);
	turnp(45, 600);
	matchp.set_value(true);
	forwardMove(600, 300, 1);
    mint.move_velocity(250);
	tint.move_velocity(250);	
	bint.move(-127);
	pros::delay(500);
	bint.move(0);
	pros::delay(1200);
	mint.move(127);
	tint.move(-127);
	matchp.set_value(false);
	forwardMove(-800, 250, 1);
	intp.set_value(false);
	turnp(90, 800);
	forwardMove(2200, 2200, 0.35);
	forwardMove(-100, 100, 1);
	turnp(-45, 1600);
	forwardMove(600, 300, 1);
	controller.print(0, 1, "%s", "i work!");
	bint.move(-127);
	mint.move(-127);
	tint.move(0);
	//driveArcL(90, 500, 100, 100);
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
	
	controller.clear();
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
		bool fastl = false;
	
		

		double chassis_temp  = (lf.get_temperature() + lm.get_temperature() + lb.get_temperature() + rf.get_temperature() + rm.get_temperature() + rb.get_temperature()) / 6;
		double int_temp = (bint.get_temperature() + mint.get_temperature() + tint.get_temperature()) / 3;
		controller.print(0,1, "%f", chassis_temp);
		controller.print(0,10, "%f", int_temp);

		if (controller.get_digital(E_CONTROLLER_DIGITAL_R1) && controller.get_digital(E_CONTROLLER_DIGITAL_R2)) { //full outtake
			intptoggle = true;
			
			bint.move(-127);
			mint.move(-127);
			tint.move(0);
			stall_pro(mint, true);

		} else if (controller.get_digital(E_CONTROLLER_DIGITAL_L2) && controller.get_digital(E_CONTROLLER_DIGITAL_R1)) {
			intptoggle = false;

			mint.move_velocity(400);
			tint.move_velocity(400);	
			bint.move(-127);
			//stall_pro(bint, true);
			
		} else if (controller.get_digital(E_CONTROLLER_DIGITAL_L2) && controller.get_digital(E_CONTROLLER_DIGITAL_R2)) {
			intptoggle = true;
			
			mint.move(127);
			tint.move(-127);	
			bint.move(-127);
			//stall_pro(bint, true);
			
		} else if (controller.get_digital(E_CONTROLLER_DIGITAL_L1) && controller.get_digital(E_CONTROLLER_DIGITAL_R1)) {
			intptoggle = false;
			
			mint.move(127);
			tint.move(127);	
			bint.move(127);
			stall_pro(mint, false);
			
		} else if (controller.get_digital(E_CONTROLLER_DIGITAL_L1) && controller.get_digital(E_CONTROLLER_DIGITAL_R2)) {
			mint.move(127);
			tint.move(-127);
			bint.move(127);
			stall_pro(mint, false);
			
		} else if (controller.get_digital(E_CONTROLLER_DIGITAL_R1)){
			intptoggle = false;
			
			mint.move(127);
			tint.move(127);	
			bint.move(0);
			
		} else if (controller.get_digital(E_CONTROLLER_DIGITAL_R2)){
			intptoggle = true;
			
			mint.move(127);
			tint.move(-127);
			bint.move(0);
			
		} else if (controller.get_digital(E_CONTROLLER_DIGITAL_L1)){
			if (hfill.get_proximity() < 50) {
				pros::delay(100);
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
				if (color == 'r') {
					color_sort(20);
				}
				else {
					color_sort(214);
				}
				}

		//red is 20 blue is 211, 0, 214
//intake into hoard
			
		} else if (controller.get_digital(E_CONTROLLER_DIGITAL_L2)) {
			intptoggle = true;
			bint.move(-127);
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

		if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_DOWN)) {
			matchptoggle = !matchptoggle;
		}

		matchp.set_value(matchptoggle);

		 if (controller.get_digital(DIGITAL_A)) {
			autonomous();	
		 }
		pros::delay(20);
	}
}


