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





void autonomous() {
	

		//ramp.set_value(true);
	bint.move(-127); // new elims
	mint.move(127);
	tint.move(-127);
	indexer.set_value(true);
    forwardMove(525, 800, 1,1); //1000
	turnp(47.5, 800, {1.7, 0, 5.5});
	forwardMove(650, 550, 1, 1); //800
	delay(200);
	forwardMove(300, 700, 0.8, 1);
	matchp.set_value(true);
	pros::delay(100);
	ramp.set_value(true);
	bint.move(-127); 
	mint.move(127);
	tint.move(-127);
	delay(100);

	turnp(58, 500, {2.5, 0, 4.5}, {2.5, 0, 4.5}, 3); //800
	matchp.set_value(false);

	forwardMove(1360, 900, 1, 1);
	delay(150);
	forwardMove(-1100, 1000, 1, 1);
	ramp.set_value(false);

	delay(100);
	bint.move(100); // new elims
	mint.move(-100);
	tint.move(100);
	turnp(-47, 800);
	bint.move(0); // new elims
	mint.move(0);
	tint.move(0);
	forwardMove(825, 800, 1, 1);
	matchp.set_value(true);
	
	bint.move(100); // new elims
	mint.move(-100);
	tint.move(100);
	delay(700); //800
	matchp.set_value(false);

	bint.move(-127); // new elims
	mint.move(127);
	tint.move(-127);

	forwardMove(-300, 800, 1, 1);


	turnp(-55, 600, {1.7, 0, 5.5}, {2, 0, 5}, 2); //800


	forwardMove(-1950, 1800, 0.8, 1); // 1500
	delay(10);
	turnp(-171, 1300, {1.7, 0, 5.5}, {2, 0, 5}); //1400

	matchp.set_value(true);

	delay(100);

	forwardMove(950, 800, 1, 1);
	turnp(-174, 100);

	delay(200);

	

	forwardMove(-800, 700, 1, 1);

	matchp.set_value(false);


	turnp(-2, 1000);

	forwardMove(600, 1000, 1, 1);
	forwardMove(-150, 150, 1, 1);
	turnp(-1, 1000);



	indexer.set_value(false);

	delay(4000);





	






	// driveArcR(90, 830, 1800, 80, true);
	// forwardMove(600, 1200, 0.7,200);
	// pros::delay(400);
	// driveArcR(-135, 500, 1400, 100, false); // 1600
	// turnp(-62, 400);
	// ramp.set_value(false);
	// forwardMove(830, 1000,1 ,200);
	// matchp.set_value(true);
	// bint.move_velocity(150);
	// mint.move(-127);
	// tint.move(127);
	// pros::delay(900);
	// matchp.set_value(false);
	// bint.move(-127);
	// mint.move(127);
	// tint.move(-127);
	// delay(100);
	// turnp(-50, 700);
	// forwardMove(-2430, 2100, 1,200); //1900
	// delay(100);
	// turnp(-180, 800);
	// matchp.set_value(true);
	// pros::delay(400);
	// forwardMove(800, 1300, 1,1, false);
	// pros::delay(500);
	// forwardMove(-600, 1100, 1,1);
	// bint.move(0);
	// mint.move(0);
	// tint.move(0);
	// matchp.set_value(false);
	// delay(100);
	// turnp(-1, 900);//0
	// delay(100);
	// forwardMove(750, 1200, 1,1);
	// delay(100);
	// forwardMove(-20, 800, 1,1);
	// turnp(0, 1000);//-1
	// bint.move(-127);
	// mint.move(127);
	// tint.move(-127); // high
	// stall_pro(bint, true);
	// stall_pro(mint, false);
	// stall_pro(tint, true);
	// indexer.set_value(false);
	// pros::delay(4000);

//arc left

	
	

/*
forwardMove(1350, 1400, 1, 1); // new awp
turnp(180, 1200);
bint.move(-127);
mint.move(127);
tint.move(-127);
indexer.set_value(true);
matchp.set_value(true);
pros::delay(400);
forwardMove(750, 800, 1,1);
forwardMove(20, 50, 1,1);
pros::delay(700);
forwardMove(-600, 600, 1,1);
matchp.set_value(false);
pros::delay(100);
turnp(7, 1000);
forwardMove(800, 800, 1,1);
forwardMove(-160, 160, 1,1);
turnp(0, 1000);
bint.move(-127);
mint.move(127);
tint.move(-127); // high
stall_pro(bint, true);
stall_pro(mint, false);
stall_pro(tint, true);
indexer.set_value(false);
pros::delay(3000);
forwardMove(-820, 820, 1,1);
matchp.set_value(true);
pros::delay(200);
matchp.set_value(false);
pros::delay(200);
turnp(-55, 800);
indexer.set_value(true);
forwardMove(2450, 2400, 0.5,500);
matchp.set_value(true);
bint.move_velocity(200);
mint.move(-127);
tint.move(127);
pros::delay(1000);

*/
/*

forwardMove(1320, 1320, 1,1); //skills
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
*/

//forwardMove(1000, 3000000, 1, 1);

//turnp(90, 10000000);

//turnp(270, 100000000000000,{0.83, 0, 4.8},{12, 0, 0});




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
		controller.print(1,0, "%f", chassis_temp);

	
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
			




