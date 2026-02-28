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


   void competition_initialize() {
	while (true) {
		auto_display();
	}
   }


void autonomous() {


//atn = 1;
if (atn == 0) {
	//skills
	
	mpist.set_value(true);
desc.set_value(true);
forward_move(1755, 1650, 1,1);
turnp(90, 500);
bint.move(-127); 
tint.move(127);
matchp.set_value(true);
pros::delay(200);

chassis_move(40, 40);
pros::delay(2200);
turnp(90, 200);
forward_move(-400, 300, 1, 600);
bint.move(0); 
tint.move(0);
matchp.set_value(false);
turnp(-45, 600);
forward_move(775, 700, 1,1);
turnp(-89, 600);
forward_move(3300, 1400, 0.8,3330);

turnp(-135, 500);
forward_move(680, 700, 1,1);

turnp(-90, 600);
forward_move(-750, 650, 1,1);
chassis_move(-40, -40);
tint.move(-127);
bint.move(-127); 
pros::delay(2200);
turnp(-90, 500);
bint.move(-127);
tint.move(127);
matchp.set_value(true);
pros::delay(200);
forward_move(700, 700, 1, 1, true,{0.15, 0, 0}, {0.72, 0, 0},false, 4);
chassis_move(40, 40);
pros::delay(2200);
turnp(-91, 400);
forward_move(-1300, 1250, 1, 600);
tint.move(-127);
chassis_move(-40, -40);
matchp.set_value(false);
pros::delay(2200);
forward_move(500, 700);
forward_move(-600, 700);
//
turnp(-90, 200);
forward_move(400, 350);
turnp(182, 700);
forward_move(4000, 2500, 1,1, true, {0.2, 0, 4.5}, {0.9, 0, 4});

turnp(-90, 500);
turnp(-90, 300);
bint.move(-127);
tint.move(127);
matchp.set_value(true);
mpist.set_value(true);
pros::delay(200);
chassis_move(40, 40);
pros::delay(2200);
turnp(-90, 200);
forward_move(-400, 400, 1, 600);
matchp.set_value(false);
turnp(-45+180, 600);
forward_move(775, 800, 1,1);
turnp(95, 600);
forward_move(3300, 1400, 0.8,3300);

turnp(-135+180, 500);
forward_move(700, 650, 1,1);

turnp(-90+180, 500);
forward_move(-750, 500, 1,1);
chassis_move(-40, -40);
tint.move(-127);
pros::delay(2200);
turnp(90, 800);
bint.move(-127);
tint.move(127);
matchp.set_value(true);
mpist.set_value(true);
pros::delay(200);
forward_move(700, 400, 1, 600);
chassis_move(40, 40);
pros::delay(2200);
turnp(89, 200);
forward_move(-1300, 1000, 1, 600);
tint.move(-127);
chassis_move(-35, -35);
matchp.set_value(false);
pros::delay(2200);
forward_move(500, 700, 0.8, 500);
forward_move(-600, 700, 0.8, 600);


turnp(-12, 600);
bint.move(-127);
tint.move(127);
forward_move(800, 1285, 0.3, 700);
turnp(3, 400);
forward_move(2200, 2200, 0.25, 550);
forward_move(-1550, 1400, 1, 1);
turnp(137, 600);
mpist.set_value(false);
forward_move(-630, 600);
bint.move(127);
tint.move(127);
pros::delay(250);
bint.move(-127);
tint.move(127);
pros::delay(2500);
turnp(115, 400);
forward_move(2575, 1300);
mpist.set_value(true);
bint.move(-127);
tint.move(127);
turnp(19, 600);
forward_move(700, 600);
matchp.set_value(true);
pros::delay(200);
forward_move(1500, 2000);
matchp.set_value(false);

}

if(atn == 1) {
desc.set_value(false);
//sawp 2/6
forward_move(1760, 1175, 1,1);
matchp.set_value(true);
turnp(90, 450);
bint.move(-127);
tint.move(127);

chassis_move(65,65);
pros::delay(900);
turnp(90, 200);
forward_move(-1200, 600, 1,1);
bint.move(-127);
tint.move(-127);
matchp.set_value(false);
chassis_move(-45,-45);
pros::delay(900);

turnp(193, 450);
bint.move(-127);
tint.move(127);
forward_move(775, 450);
turnp(180, 300);
forward_move(2250, 1150);
bint.move(-127);
tint.move(127);
turnp(150, 400);
forward_move(1430, 935); ///

turnp(90, 400);
forward_move(-500, 350);
bint.move(127);
tint.move(127);
pros::delay(160);
bint.move(-127);
tint.move(-127);
matchp.set_value(false);
chassis_move(-45,-45);
pros::delay(1350);

matchp.set_value(true);
turnp(90, 200);
bint.move(-127);
tint.move(127);
forward_move(950, 600);
chassis_move(70,70);
pros::delay(700);
forward_move(-675, 475);
turnp(135, 450);
forward_move(-2275, 1400);
bint.move(127);
tint.move(127);
mpist.set_value(false);
pros::delay(100);
bint.move(-127);
tint.move(127);
pros::delay(1250);
forward_move(1000, 1200);


/*
turnp(90, 500);
forward_move(-600, 300);
chassis_move(-45,-45);
pros::delay(100);
bint.move(-127);
tint.move(-127);
pros::delay(3000);
*/
} 
else if(atn == 2) {
//left side elims
forward_move(1710, 1650, 1,1);
turnp(-93, 600);
bint.move(-127);
tint.move(127);
matchp.set_value(true);
pros::delay(200);
chassis_move(60,60);
pros::delay(610);
turnp(-90, 600);
forward_move(-1200, 850, 1,1);
matchp.set_value(false);
chassis_move(-40,-40);
bint.move(-127);
tint.move(-127);
pros::delay(1000);
turnp(170, 850);
bint.move(-127);
tint.move(127);
forward_move(900, 1400, 0.4,500);
turnp(-44.5, 600);
forward_move(-620, 600, 1,1);
mpist.set_value(false);
bint.move(127);
tint.move(127);
pros::delay(100);
bint.move(-90);
tint.move(127);
pros::delay(1200);
turnp(312, 500);
bint.move(0);
tint.move(0);
turnp(-35, 300);
forward_move(1480, 1450, 1,1);
mpist.set_value(true);
turnp(-91, 450);
lf.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
lm.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
lb.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
rf.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
rm.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
rb.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
forward_move(-1050, 900, 0.6,1100);
turnp(-10, 700);

}
else if(atn == 3) {
//right side
mpist.set_value(true);
turnp(18, 500);
bint.move(-127);
tint.move(127);
//forward_move(1325, 1200, 0.2, 400, true, {0.3, 0, 4.5},{0.1, 0, 4}, true, 3);
forward_move(1325, 1200, 0.3, 400);
turnp(130, 500);
forward_move(1450, 1300);
turnp(180, 500);
matchp.set_value(true);
pros::delay(200);
forward_move(400, 400);
chassis_move(50,50);
pros::delay(900);
turnp(180, 100);
//forward_move(-700, 600, 0.2,400, true);
//turnp(174, 10);
//forward_move(-1290, 1150, 1,1, true, {0.3, 0, 4.5}, {0.1, 0, 4}, true, 4);
forward_move(-1290, 1050);
matchp.set_value(false);
chassis_move(-50,-50);
bint.move(-127);
tint.move(-127);
pros::delay(1850);
turnp(-135, 425);
forward_move(400, 400);
turnp(0, 700);
lf.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
lm.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
lb.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
rf.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
rm.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
rb.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
forward_move(1100, 1050, 0.6,400);
turnp(-50, 700);
bint.move(0);
tint.move(0);
}
else if(atn == 4) {
//right rush
forward_move(1710, 1400, 1,1);
turnp(93, 500);
bint.move(-127);
tint.move(127);
matchp.set_value(true);
pros::delay(200);
chassis_move(55,55);
pros::delay(575);
turnp(90, 600);
forward_move(-1200, 850, 1,1);
matchp.set_value(false);
chassis_move(-40,-40);
bint.move(-127);
tint.move(-127);
pros::delay(875);
turnp(135, 425);
forward_move(400, 400);
turnp(-90, 700);
lf.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
lm.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
lb.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
rf.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
rm.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
rb.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
bint.move(0);
tint.move(0);
forward_move(1275, 10000, 0.6,400);
}

else if(atn == 5) {
//left rush
forward_move(1710, 1400, 1,1);
turnp(-93, 500);
bint.move(-127);
tint.move(127);
matchp.set_value(true);
pros::delay(200);
chassis_move(55,55);
pros::delay(575);
turnp(-90, 600);
forward_move(-1200, 850, 1,1);
matchp.set_value(false);
chassis_move(-40,-40);
bint.move(-127);
tint.move(-127);
pros::delay(900);
turnp(-150, 425);
forward_move(530, 400);
turnp(-95, 400);
lf.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
lm.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
lb.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
rf.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
rm.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
rb.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
bint.move(0);
tint.move(0);
forward_move(-1175, 1000000, 0.6,400);
}

else if(atn == 6) {
//sawp clutch
forward_move(200, 1400, 1,1);

}

else if(atn == 7) {
//sawp clutch

}

//skills 2/6
/*
mpist.set_value(true);
desc.set_value(true);
forward_move(1850, 1300, 1,1);
turnp(90, 600);
bint.move(-127); 
tint.move(127);
matchp.set_value(true);
pros::delay(200);

chassis_move(50, 50);
pros::delay(2000);
turnp(90, 200);
forward_move(-400, 500, 1, 600);
matchp.set_value(false);
turnp(-45, 700);
forward_move(775, 700, 1,1);
turnp(-89, 700);
forward_move(3300, 1750, 0.8,400);

turnp(-135, 500);
forward_move(720, 700, 1,1);

turnp(-90, 600);
forward_move(-750, 500, 1,1);
chassis_move(-40, -40);
tint.move(-127);
pros::delay(2000);
turnp(-92, 500);
bint.move(-127);
tint.move(127);
matchp.set_value(true);
mpist.set_value(true);
pros::delay(1000);
forward_move(700, 500, 1, 600);
chassis_move(50, 50);
pros::delay(2000);
turnp(-92, 300);
forward_move(-1300, 1100, 1, 600);
tint.move(-127);
chassis_move(-40, -40);
matchp.set_value(false);
pros::delay(2000);
//
turnp(-90, 200);
forward_move(400, 350);
turnp(180, 700);
forward_move(4200, 3000, 1,1, true, {0.2, 0, 4.5}, {0.9, 0, 4});
//gggg
turnp(-90, 500);
bint.move(-127);
tint.move(127);
matchp.set_value(true);
mpist.set_value(true);
pros::delay(200);
chassis_move(50, 50);
pros::delay(2000);
turnp(-90, 200);
forward_move(-400, 500, 1, 600);
matchp.set_value(false);
turnp(-45+180, 600);
forward_move(775, 750, 1,1);
turnp(95, 800);
forward_move(3300, 2750, 0.8,400);

turnp(-135+180, 500);
forward_move(800, 750, 1,1);

turnp(-90+180, 500);
forward_move(-750, 500, 1,1);
chassis_move(-40, -40);
tint.move(-127);
pros::delay(2500);
turnp(90, 800);
bint.move(-127);
tint.move(127);
matchp.set_value(true);
mpist.set_value(true);
pros::delay(1000);
forward_move(700, 400, 1, 600);
chassis_move(50, 50);
pros::delay(2500);
forward_move(-1300, 1000, 1, 600);
tint.move(-127);
chassis_move(-50, -50);
matchp.set_value(false);
pros::delay(2500);

turnp(-10, 1500);
bint.move(-127);
tint.move(127);
forward_move(775, 1085);
turnp(1.5, 300);
forward_move(-305, 1850);
turnp(-225, 1000);
forward_move(-850, 800);
mpist.set_value(false);
bint.move(127);
tint.move(127);
pros::delay(100);
bint.move(-85);
tint.move(127);
pros::delay(3000);
mpist.set_value(true);
turnp(105, 600);
forward_move(2575, 1500);
bint.move(-127);
tint.move(127);
turnp(20, 700);
forward_move(600, 500);
matchp.set_value(true);
pros::delay(200);
forward_move(1500, 2000);
matchp.set_value(false);
*/

//right elims 2/7
/*
turnp(18, 500);
bint.move(-127);


tint.move(127);
forward_move(1315, 1200, 0.2, 600);
turnp(130, 600);
forward_move(1500, 1500);
turnp(180, 500);
matchp.set_value(true);
pros::delay(200);
chassis_move(55,55);
pros::delay(750);
turnp(180, 700);
forward_move(-1200, 1100, 1,1);
bint.move(-127);
tint.move(-127);
matchp.set_value(false);
chassis_move(-40,-40);
pros::delay(2300);
turnp(180, 500);
forward_move(800, 800, 1,1);
turnp(-45, 600);
forward_move(760, 800, 1,1);
turnp(0, 600);
lf.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
lm.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
lb.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
lf.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
lm.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
lb.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
forward_move(1200, 1200, 1,1);

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
		pros::screen::erase();
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
			tint.move(127);
			bint.move(-100);
			//und.set_value(false);
			mpist.set_value(false);

		}
		else if(controller.get_digital(E_CONTROLLER_DIGITAL_L2)) {
			tint.move(127);
			bint.move(127);
			//und.set_value(false);
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
			




