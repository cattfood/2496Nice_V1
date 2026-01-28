#include "main.h"
#include "robot.h"
#ifndef PIDH
#define PIDH



struct pidConstants{
    float p;
    float i;
    float d;
};

extern double variable_kd(double target);
extern void chassis_move(int left, int right); 
extern void set_constants(pidConstants constants);
extern void forward_move(float target, float timeout, float endsp, float dist, bool headc = true, pidConstants constants = {0.45, 0, 4.16}, pidConstants constants2 = {2.5, 0, 0}); //change constants here !!! //0.6, 0, 6.75 // 4.6, 0, 0 10
extern void turnp(float target, float timeout, pidConstants constants = {1, 0, 6.11}, pidConstants constants2 = {19, 0, 0}, double feedforward = 1);//, pidConstants constants2 = {0, 0, 0}, pidConstants consstants3 ={0, 0, 0});
extern void chassis_move(int left, int right);
extern void drive_arcL(double theta, double radius, int timeout, int speed);
extern void drive_arcR(double theta, double radius, int timeout, int speed, bool test);
extern void chassisStop();
extern void turnpl(float target, float timeout, pidConstants constants = {1, 0, 6.11}, pidConstants constants2 = {19.9, 0, 0}, double feedforward = 1);//, pidConstants constants2 = {0, 0, 0}, pidConstants consstants3 ={0, 0, 0});
extern double true_target;
extern void forward_movem(float target, float timeout, float endsp, float dist, bool headc = true, pidConstants constants = {0.45, 0, 4.16}, pidConstants constants2 = {2.5, 0, 0}); //change constants here !!! //0.6, 0, 6.75 // 4.6, 0, 0 10
#endif

