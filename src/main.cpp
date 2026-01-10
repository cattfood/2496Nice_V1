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
	desc.set_value(true);
	forward_move(600, 600, 1,1);
	turnp(-51, 600);
	tint.move(127);
	bint.move(-127);
	forward_move(2000, 1500, 0.3,1700);
	pros::delay(250);
	forward_move(-675, 600, 1,1);
	pros::delay(250);
	turnp(-147, 600);
	forward_move(1400, 1300, 0.5,1);
	turnp(180, 400, {1.05, 0, 0}, {19.9, 0, 0});
	tint.move(-127);
	bint.move(-127);
	forward_move(-1600, 1600, 0.3,200);
	matchp.set_value(true);
	pros::delay(1000);
	turnp(181, 200);
	forward_move(1250, 800, 0.7, 1400);
	chassis_move(120, 120);
	pros::delay(600);
	chassis_move(0,0);
	forward_move(-1600, 1700, 0.3,600);
	tint.move(127);
	bint.move(-127);
	pros::delay(500);
	matchp.set_value(false);
	desc.set_value(false);
	forward_move(600, 300, 0.5,250);
	turnp(225, 400);
	forward_move(-600, 800, 0.5,250);
	turnp(180, 300);
	forward_move(-850, 2000, 0.5,250);

	//forward_move(600, 100000000, 1,1);
	//forward_move(2000, 100000000, 1,1, true, {0.15, 0, 0},  {2.5, 0, 0});
	//turnp(180, 10000000, {1, 0, 6.8}, {19.9, 0, 0});
	//turnp(150, 10000000, {1, 0, 6.75}, {19.9, 0, 0});
	//turnp(135, 10000000, {1, 0, 6.22}, {19.9, 0, 0});
	//turnp(120, 10000000, {1, 0, 5.85}, {19.9, 0, 0});
	//turnp(90, 1000000);
	//turnp(60, 10000000, {1, 0, 2.05}, {19.9, 0, 0});
	//turnp(45, 10000000, {1.05, 0, 0}, {19.9, 0, 0});
	//turnp(15, 10000000, {2.5, 0, 0}, {19.9, 0, 0});
	//drive_arcL(90, 600, 3000, 100);
	//turnp(-90, 400);
	//drive_arcL(-90, 600, 3000, 100);
	//turnp(-90, 20);
	//forward_move(1000, 100000000, 1,1, true, {0.13, 0, 0},  {2.5, 0, 0});
	//turnp(-175, 20000);
	//turnp(-180, 20);
	//forward_move(800, 2000, 1, 1);

	//------------------------------ awp
	/*
	turnp(0, 10);
	forward_move(1350, 1300, 1, 1);
	turnp(-90, 1000);
	matchp.set_value(true);
	pros::delay(200);
	bint.move(-127);
	tint.move(127);
	mpist.set_value(true);
	und.set_value(false);
	forward_move(700, 1000, 1, 1);
	turnp(-93, 10);
	forward_move(-400, 400, 1, 600);
	//turnp(-90, 300);
	forward_move(-900, 1000, 1, 600);
	matchp.set_value(false);
	//forward_move(-900, 3000, 1,1);
	tint.move(-127);
	mpist.set_value(true);
	chassis_move(-30, -30); // -50, -50
	//forward_move(-1000, 1000, 0.6,1000);
	//turnp(-90, 400);
	pros::delay(1500);
	tint.move(127);
	mpist.set_value(true);
	turnp(-90, 100);
	forward_move(1000, 1000, 1,1);
	turnp(-225, 1500, {1, 0, 7.6}, {19.9, 0, 0});
	forward_move(1400, 1400, 1, 800);
	turnp(-40, 1500, {1, 0, 8.67}, {19.9, 0, 0});
	bint.move(127);
	tint.move(0);
	pros::delay(75);
	bint.move(0);
	forward_move(-1200, 1200, 1, 400);
	mpist.set_value(false);
	bint.move_velocity(-450);
	tint.move_velocity(550);
	pros::delay(800);
	forward_move(920, 1000, 1, 1);
	mpist.set_value(true);
	turnp(-171, 900, {1, 0, 7.4}, {19.9, 0, 0});
pros::delay(120);
	bint.move(-127);
	tint.move(127);
	//forward_move(1500, 1000, 1,800, true, {0.15, 0, 0},  {2.5, 0, 0});
	//700 0.5 
	forward_move(2000, 1400, 0.5,800);

	turnp(220, 800, {1.1, 0, 0}, {19.9, 0, 0});
	forward_move(1500, 1800, 1,700);
	turnp(-90, 1000,{1, 0, 0}, {19.9, 0, 0});
	forward_move(-700, 800, 1, 600);
	matchp.set_value(false);
	tint.move(-127);
	mpist.set_value(true);
	chassis_move(-50, -50);
	pros::delay(3000);


			//und.set_value(true);
			//mpist.set_value(!true);
	
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
		double chassis_temp  = (lf.get_temperature() + lm.get_temperature() + lb.get_temperature() + rf.get_temperature() + rm.get_temperature() + rb.get_temperature()) / 6;
		double int_temp = (bint.get_temperature() + tint.get_temperature()) / 2;
		//controller.print(0,0, "%f", turn);
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
		
		int y = controller.get_analog(ANALOG_LEFT_Y);
		int power = y;
	    int x = controller.get_analog(ANALOG_RIGHT_X);
		//int turn = (x * abs(x)) / (sqrt(abs(x)) * sqrt(400));
		//int turn = (cbrt(127 * x * x) * x) / abs(x);
		int turn = (sqrt(127*abs(x)) * abs(x)) / x;
		//int turn = cbrt((127*sqrt(abs(x))) * (127*sqrt(abs(x)))) * abs(x) / x;
		int left = power + turn;
		int right = power - turn;

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
			und.set_value(false);
		}
		else if(controller.get_digital(E_CONTROLLER_DIGITAL_R2)) {
			bint.move(-127);
			tint.move(-127);
			mpist.set_value(!false);
			und.set_value(false);
		}
		else if(controller.get_digital(E_CONTROLLER_DIGITAL_L1)) {
			tint.move(127);
			bint.move(-127);
			und.set_value(false);
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
			




