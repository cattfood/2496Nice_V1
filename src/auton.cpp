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

//void autonomous() {
   // if(atn == 1) {

   // }

//}
