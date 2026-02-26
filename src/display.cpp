#include "main.h" 
#include <string>
#include "pros/misc.h"
#include "pros/motors.h"
#include "display.h"
#include "robot.h"

using namespace std;
using namespace pros;

int atn = 4;
int color = 1;


void color_select() {
  if(controller.get_digital_new_press(E_CONTROLLER_DIGITAL_X)) {
			color = 1;
		}
  if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_Y)) {
      color = 2;
  }
  if (controller.get_digital_new_press (E_CONTROLLER_DIGITAL_A)) {
    color = 3;
  }
}

void color_display() {
  switch (color) {
      case 1: 
      controller.print(2, 0, "%s", "none");
      break;
      case 2:
      controller.print(2, 0, "%s", "red");
      break;
      case 3:
      controller.print(2, 0, "%s", "blue");
      break;
    }
}

void auto_display() {
    string autstr;
		
      if (atn == 1) {
        autstr = " AWP";
        controller.print(0, 0, "Aut 1: %s", autstr);
      }
      else if (atn == 2) {
        autstr = "LEFT";
        controller.print(0, 0, "Aut 2: %s", autstr);
      }
      else if (atn == 3) {
       autstr = "RIGHT";
        controller.print(0, 0, "Aut 3: %s", autstr);
      }
      

		if(lim.get_new_press()) {
            atn++;
            if(atn > 3) {
                atn = 1;
            }
        }
}