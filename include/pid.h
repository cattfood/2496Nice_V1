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
extern void forwardMove(float target, int timeout, pidConstants constants = {0.3, 0.2, 2.8}); //change constants here !!!
extern void turn(float target, int timeout, pidConstants constants);
extern void chassisMove(int left, int right);
extern void chassisStop();


#endif