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
extern void forwardMove(float target, float timeout, float endsp, float dist, pidConstants constants = {0.1, 0, 0}, pidConstants constants2 = {10, 0, 72.5}); //change constants here !!!
extern void forwardMoveInt(float target, float timeout, float endsp, pidConstants constants = {0.5, 0, 0}, pidConstants constants2 = {0.001, 0, 0}); //change constants here !!! // 0.8
extern void turnp(float target, float timeout, pidConstants constants = {1, 0, 5}, pidConstants constants2 = {10, 0, 0});//, pidConstants constants2 = {0, 0, 0}, pidConstants consstants3 ={0, 0, 0});
extern void chassisMove(int left, int right);
void driveArcL(double theta, double radius, int timeout, int speed);
void driveArcR(double theta, double radius, int timeout, int speed);
extern void chassisStop();


#endif


