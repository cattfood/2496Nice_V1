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

pidConstants f_180 {
	p: 10.0,
	i: 0.0,
	d: 80
};

pidConstants s_180 {
	p: 12,
	i: 0.0,
	d: 4
};

pidConstants e_180 {
	p: 10.0,
	i: 0.0,
	d: 80
};



void autonomous() {
	
	//awp
	
	mint.move(127);
	bint.move(127);
	forwardMove(1250, 1200, 0.7, 200); // 0.75
	turnp(40, 750);
	matchp.set_value(true);
	bint.move(-127);
	forwardMove(650, 650, 1, 1);
	//bint.move(-127);s
	mint.move_velocity(600);
	tint.move_velocity(450);
	pros::delay(600);
	bint.move(0);
	mint.move(0);
	intp.set_value(true);
	forwardMove(-670, 670, 1, 1);
	pros::delay(300);
	mint.move(127);
	bint.move(127);
	matchp.set_value(false);
	turnp(90, 1700, f_180, s_180, e_180);
	forwardMove(1700, 1700, 1, 1);
	forwardMove(600, 600, 0.5, 100);
	bint.move(0);
	mint.move(0);
	turnp(-45,1000);
	forwardMove(900, 900, 1,1);
	bint.move_velocity(-300);
	mint.move_velocity(-300);
	pros::delay(800);
	bint.move(0);
	mint.move(0);
	forwardMove(-1850, 1850, 1,1);
	matchp.set_value(false);
	turnp(-180, 1950, f_180, s_180, e_180);
	matchp.set_value(true);
	pros::delay(400); // 500
	forwardMove(1000, 1000, 0.5, 500);
	chassisMove(80, 80);
	bint.move(127);
	mint.move(127);
	chassisMove(-45, -45);
	pros::delay(200);
	chassisMove(45, 45);
	pros::delay(300);
	chassisMove(-45, -45);
	pros::delay(200);
	chassisMove(45, 45);
	pros::delay(300);
	forwardMove(-300, 300, 1, 1);
	matchp.set_value(false);
	pros::delay(100); // 200
	turnp(-0, 1900, f_180, s_180, e_180);
	bint.move(-127);
	mint.move(127);
	tint.move(-127);
	forwardMove(1400, 2100, 0.5, 800); /// 2300
	//chassisMove(30, 30);
	pros::delay(4000);

	
/* //elim scoring
    mint.move(127);
	bint.move(127);
	intp.set_value(true);
	forwardMove(1100, 1200, 0.65, 600); // 0.75
    driveArcL(90, 400, 600, 600); // 510
	turnp(-90, 400);
	forwardMove(900, 900, 0.75, 200);
	pros::delay(300); // 600
	driveArcL(-150, 160, 900, 100);
	turnp(45, 650);
	matchp.set_value(true);
	pros::delay(500); //600
	bint.move(-127);
	forwardMove(325, 600, 1, 1);
	mint.move_velocity(600);
	tint.move_velocity(600);
	bint.move(0);
	pros::delay(650);
	mint.move(0);
	bint.move(0);
	forwardMove(-1875, 1900, 1, 1);
	matchp.set_value(false);
	turnp(180, 1950, f_180, s_180, e_180);
	matchp.set_value(true);
	pros::delay(400); // 500
	forwardMove(1000, 1000, 0.5, 500);
	chassisMove(80, 80);
	bint.move(127);
	mint.move(127);
	pros::delay(400);
	chassisMove(-45, -45);
	pros::delay(200);
	chassisMove(45, 45);
	pros::delay(300);
	chassisMove(-45, -45);
	pros::delay(200);
	chassisMove(45, 45);
	pros::delay(300);
	forwardMove(-300, 300, 1, 1);
	matchp.set_value(false);
	pros::delay(100); // 200
	turnp(0, 1900, f_180, s_180, e_180);
	bint.move(-127);
	mint.move(127);
	tint.move(-127);
	forwardMove(1070, 2100, 0.5, 800); /// 2300
	//chassisMove(30, 30);
	pros::delay(4000);
	*/
 //low
 /*
  mint.move(127);
	bint.move(127);
	intp.set_value(true);
	forwardMove(1100, 1200, 0.65, 600); // 0.75
    driveArcR(90, 400, 600, 600); // 510
	turnp(90, 400);
	forwardMove(900, 900, 0.75, 200);
	pros::delay(300); // 600
	driveArcR(-150, 160, 900, 100);
	turnp(-45, 650);
	matchp.set_value(true);
	pros::delay(500); //600
	forwardMove(325, 600, 1, 1);
	bint.move(-127);
	mint.move(-127);
	pros::delay(800);
	bint.move(0);
	mint.move(0);
	forwardMove(-1875, 1900, 1, 1);
	matchp.set_value(false);
	turnp(-180, 1950, f_180, s_180, e_180);
	matchp.set_value(true);
	pros::delay(400); // 500
	forwardMove(1000, 1000, 0.5, 500);
	chassisMove(80, 80);
	bint.move(127);
	mint.move(-127);
	pros::delay(400);
	chassisMove(-45, -45);
	pros::delay(200);
	chassisMove(45, 45);
	pros::delay(300);
	chassisMove(-45, -45);
	pros::delay(200);
	chassisMove(45, 45);
	pros::delay(300);
	forwardMove(-300, 300, 1, 1);
	matchp.set_value(false);
	pros::delay(100); // 200
	turnp(-0, 1900, f_180, s_180, e_180);
	bint.move(-127);
	mint.move(127);
	tint.move(-127);
	forwardMove(1070, 2100, 0.5, 800); /// 2300
	//chassisMove(30, 30);
	pros::delay(4000);

 */


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
	//color_select();
	
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
		controller.print(0,0, "%f", chassis_temp);
		controller.print(1,0, "%f", int_temp);

		if (controller.get_digital(E_CONTROLLER_DIGITAL_R1) && controller.get_digital(E_CONTROLLER_DIGITAL_R2)) { //full outtake
			intptoggle = true;
			
			bint.move(-127);
			mint.move(-127);
			tint.move(0);
			stall_pro(mint, true);

		} else if (controller.get_digital(E_CONTROLLER_DIGITAL_L2) && controller.get_digital(E_CONTROLLER_DIGITAL_R1)) {
			intptoggle = false;

			mint.move_velocity(350);
			tint.move_velocity(350);	
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
				if (color == 2) {
					color_sort(20);
				}
				if (color == 3){
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

		if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_B)) {
			intptoggle  = !intptoggle;
		}
		
		intp.set_value(intptoggle);

		if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_DOWN)) {
			matchptoggle = !matchptoggle;   
		}
		matchp.set_value(matchptoggle);

		 if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_UP)) {
			autonomous();	
		 }

		pros::delay(20);
	}
}


