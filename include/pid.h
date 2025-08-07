#include "main.h"
#include "robot.h"
#ifndef PIDH
#define PIDH

struct pidConstants{
    float p;
    float i;
    float d;
};

extern void chassisMove(int left, int right);

extern void setConstants(pidConstants constants);
extern void forwardMove(float target, pidConstants constants = {0.1, 0, 0}, pidConstants constants2 = {0.8, 0, 0}); //change constants here !!!
extern void turnp(float target, pidConstants constants = {10, 0, 110}, pidConstants constants2 = {8, 0, 0});
extern void chassisMove(int left, int right);
extern void chassisStop();


#endif
