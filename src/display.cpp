#include "main.h" 
#include <string>
#include "pros/misc.h"
#include "pros/motors.h"
#include "display.h"
#include "robot.h"

using namespace std;
using namespace pros;

int atn = 1;

void auto_selector() {
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
    
}

void auto_display() {
    string text;
    switch (atn) {
        case 1:
            text = "NONE";
            controller.print(0, 0, "Aut 0: %s", text);
            break;
        case 2:
            text = "test 1";
            controller.print(0, 0, "Aut 1: %s", text);
            break;
        case 3:
            text = "test 2";
            controller.print(0, 0, "Aut 2: %s", text);
            break;
        case 4:
            text = "test 3";
            controller.print(0, 0, "Aut 3: %s", text);
            break;


    }
}