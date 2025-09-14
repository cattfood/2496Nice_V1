#include "api.h"
#include "auton.h"
#include "main.h"
#include "robot.h"
#include "display.h"
#include "pid.h"

using namespace std;
using namespace pros;

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
    if(atn == 1) {

    }
    if(atn == 2) {
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

    }
    if(atn == 3) {
    //elims type 
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
    }
    if(atn == 4) {
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
    }
}
