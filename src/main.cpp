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
bool desct;
bool indext;
bool rampt;

int auton = 1;

int add(int num1, int num2) {
	return num1+num2;
}




void autonomous() {
	/*
	//forwardMove(2000, 1000000000, 1, 200); // 0.75
	ramp.set_value(true); // awp
	bint.move(-127);
	mint.move(127);
	tint.move(-127);
	indexer.set_value(true);
	forwardMove(1500, 1200, 0.65,200);
	turnp(-45, 900);
	bint.move_velocity(250);
	mint.move(-127);
	tint.move(127);
	forwardMove(870, 670, 1 ,200);
	pros::delay(500);
	bint.move(-127);
	mint.move(127);
	tint.move(-127);
	indexer.set_value(true);
	forwardMove(-870, 670, 1, 1);
	turnp(-100, 800);
	forwardMove(2400, 2400, 0.5,400);
	turnp(43, 900);
	forwardMove(600, 600, 1 ,200);
	bint.move(-127);
	mint.move(127);
	tint.move(-127); //mid
	ramp.set_value(true); // awp
	indexer.set_value(false);
	pros::delay(800);
	bint.move(-127);
	mint.move(127);
	tint.move(-127);
	indexer.set_value(true);
	forwardMove(-1800, 1300, 1, 1);
	turnp(180, 700);
	matchp.set_value(true);
	ramp.set_value(false);
	pros::delay(300);
	forwardMove(1000, 1000, 1, 1);
	pros::delay(100);
	bint.move(0);
	mint.move(0);
	tint.move(0); 
	forwardMove(-400, 400, 1, 1);
	matchp.set_value(false);
	turnp(0, 400);
	turnp(0, 600);
	forwardMove(800, 800, 1, 1);
	ramp.set_value(true);
	bint.move(-127);
	mint.move(127);
	tint.move(-127); // high
	indexer.set_value(false);
	*/

	/*bint.move(-127); // elims
	mint.move(127);
	tint.move(-127);
	indexer.set_value(true);
	forwardMove(1550, 1550, 0.4,200);
	turnp(135, 1000);
	forwardMove(800, 800, 1, 1);
	forwardMove(800, 800, 1, 1);
	turnp(-30, 200);
	turnp(0, 1200, {0.9, 0, 5}, {10, 0, 0});
	forwardMove(700, 700, 1,1);
	bint.move(-127);
	mint.move(127);
	tint.move(-127); // high
	indexer.set_value(false);
	pros::delay(2000);
	forwardMove(-420, 420, 1,1);
	turnp(200, 200);
	turnp(180, 1200, {0.9, 0, 5}, {10, 0, 0});
	forwardMove(450, 450, 1,1);
	bint.move(-127);
	mint.move(127);
	tint.move(-127);
	indexer.set_value(true);
	matchp.set_value(true);
	pros::delay(600);
	forwardMove(700, 700, 1,1);
	pros::delay(800);
	forwardMove(-450, 450, 1,1);
	matchp.set_value(false);
	pros::delay(100);
	turnp(-30, 200);
	turnp(0, 1200, {0.9, 0, 5}, {10, 0, 0});
	forwardMove(950, 950, 1,1);
	bint.move(-127);
	mint.move(127);
	tint.move(-127); // high
	indexer.set_value(false);
	pros::delay(2000);
*/
forwardMove(1320, 1320, 1,1);
turnp(-200, 200);
turnp(-185, 1200, {0.9, 0, 5}, {10, 0, 0});
bint.move(-127);
mint.move(127);
tint.move(-127);
indexer.set_value(true);
matchp.set_value(true);
pros::delay(600);
forwardMove(720, 720, 1,1);
pros::delay(2000);
forwardMove(-450, 450, 1,1);
matchp.set_value(false);
pros::delay(100);
turnp(-30, 200);
turnp(0, 1300, {0.9, 0, 5}, {10, 0, 0});
forwardMove(870, 870, 1,1);
bint.move(-127);
mint.move(127);
tint.move(-127); // high
indexer.set_value(false);
pros::delay(6000);
forwardMove(-450, 450, 1,1);
turnp(90, 1300);
forwardMove(5200, 5100, 0.6,200);
forwardMove(-710, 710, 1,1);
//
turnp(200, 200);
turnp(187, 1200, {0.9, 0, 5}, {10, 0, 0});
bint.move(-127);
mint.move(127);
tint.move(-127);
indexer.set_value(true);
matchp.set_value(true);
pros::delay(600);
forwardMove(710, 710, 1,1);
pros::delay(2000);
forwardMove(-450, 450, 1,1);
matchp.set_value(false);
pros::delay(100);
turnp(30, 200);
turnp(0, 1300, {0.9, 0, 5}, {10, 0, 0});
forwardMove(870, 870, 1,1);
bint.move(-127);
mint.move(127);
tint.move(-127); // high
indexer.set_value(false);
pros::delay(6000);
forwardMove(-900, 900, 1, 1);
turnp(-135, 1000, {0.9, 0, 5}, {10, 0, 0});
forwardMove(600, 600, 1, 1);
turnp(-90, 1000);
forwardMove(2500, 1200, 1, 1);











	//pros::delay(1000);
	//turnp(90, 1000000000);
}

/* void on_center_button() {
  static bool pressed = false;
  pressed = !pressed;
  if (pressed) {
	atn++;
  } else {
    pros::lcd::clear_line(2);
  }
}
*/
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
	auto_selector();
	auto_display();
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
		/*
		if(controller.get_digital_new_press(E_CONTROLLER_DIGITAL_RIGHT)){
        atn++;
      }
      if(controller.get_digital_new_press(E_CONTROLLER_DIGITAL_LEFT)){
        atn--;
      }
      if(atn > 4){
        atn = 1;
      }
      if(atn < 1){
        atn = 4;
      }
	  string text;
    switch (atn) {
        case 1:
            text = "NONE";
            controller.print(0, 0, "Aut 0: %s", text);
            break;
        case 2:
            text = "AWP";
            controller.print(0, 0, "Aut 1: %s", text);
            break;
        case 3:
            text = "elims";
            controller.print(0, 0, "Aut 2: %s", text);
            break;
        case 4:
            text = "low";
            controller.print(0, 0, "Aut 3: %s", text);
            break;


    }
			*/
	controller.clear();
	//auto_selector();
	//auto_display();


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
		int turnf = controller.get_analog(ANALOG_RIGHT_X);
		int turn = (turnf*turnf*turnf) / 16100;
		int left = power + turn;
		int right = power - turn;
		opsens.set_led_pwm(100);
		

		//tank

		int lpower = controller.get_analog(ANALOG_LEFT_Y);
		int rpower = controller.get_analog(ANALOG_RIGHT_Y);

		bool tanktoggle = false;

		if (tanktoggle) {
		lf.move(lpower);
		lm.move(lpower);
		lb.move(lpower);
		rf.move(rpower);
		rm.move(rpower);
		rb.move(rpower);
		} 
		else {
		lf.move(left);
		lm.move(left);
		lb.move(left);
		rf.move(right);
		rm.move(right);
		rb.move(right);
		}

		bool fastm = true;
		bool fastl = false;
	
		

		double chassis_temp  = (lf.get_temperature() + lm.get_temperature() + lb.get_temperature() + rf.get_temperature() + rm.get_temperature() + rb.get_temperature()) / 6;
		double int_temp = (bint.get_temperature() + mint.get_temperature() + tint.get_temperature()) / 3;
		//controller.print(0,0, "%f", turn);
		//controller.print(1,0, "%f", int_temp);

	
	if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_UP)) {
		tanktoggle = !tanktoggle;
	}
	if (controller.get_digital(E_CONTROLLER_DIGITAL_L1)) {
		bint.move(-127);
		mint.move(127);
		tint.move(-127);
		indexer.set_value(true);
	}
	else if (controller.get_digital(E_CONTROLLER_DIGITAL_R1) && controller.get_digital(E_CONTROLLER_DIGITAL_R2)) {
		bint.move(127);
		mint.move(-127);
		tint.move(127); // low
	}
	else if(controller.get_digital(E_CONTROLLER_DIGITAL_R1)) {
		ramp.set_value(false);
		bint.move(-127);
		mint.move(127);
		tint.move(-127); //mid
		indexer.set_value(false);
	}
	else if (controller.get_digital(E_CONTROLLER_DIGITAL_R2)) {
		ramp.set_value(true);
		bint.move(-127);
		mint.move(127);
		tint.move(-127); // high
		indexer.set_value(false);
	}
	else {
		bint.move(0);
		mint.move(0);
		tint.move(0);
	}

	if(controller.get_digital_new_press(E_CONTROLLER_DIGITAL_B)) {
		desct = !desct;
	
	}
	desc.set_value(desct);
	if(controller.get_digital_new_press(E_CONTROLLER_DIGITAL_DOWN)) {
		matchptoggle = !matchptoggle;
	
	}
	matchp.set_value(matchptoggle);

	if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_A)){
		autonomous();
	}
}
}
			




