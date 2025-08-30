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
extern void forwardMove(float target, float timeout, float endsp, pidConstants constants = {0.1, 0, 0}, pidConstants constants2 = {0.8, 0, 0}); //change constants here !!!
extern void forwardMoveInt(float target, float endsp, pidConstants constants = {0.1, 0, 0}, pidConstants constants2 = {0.001, 0, 0}); //change constants here !!! // 0.8
extern void turnp(float target, pidConstants constants = {10, 0, 80}, pidConstants constants2 = {14, 0, 0});
extern void chassisMove(int left, int right);
void driveArcL(double theta, double radius, int timeout, int speed);
extern void chassisStop();


#endif
