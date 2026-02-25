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
extern void forward_move(float target, float timeout = 1000, float endsp = 1, float dist = 1, bool headc = true, pidConstants constants = {0.3, 0, 4.5}, pidConstants constants2 = {0.1, 0, 4}, bool slowd = true); //change constants here !!! //0.6, 0, 6.75 // 4.6, 0, 0 10
extern void turnp(float target, float timeout, pidConstants constants = {1, 0, 6.11}, pidConstants constants2 = {6, 0, 0}, double feedforward = 1);//, pidConstants constants2 = {0, 0, 0}, pidConstants consstants3 ={0, 0, 0});
extern void chassis_move(int left, int right);
extern void drive_arcL(double theta, double radius, int timeout, int speed);
extern void drive_arcR(double theta, double radius, int timeout, int speed, bool test);
extern void chassisStop();
extern void turnpl(float target, float timeout, pidConstants constants = {1, 0, 6.11}, pidConstants constants2 = {19.9, 0, 0}, double feedforward = 1);//, pidConstants constants2 = {0, 0, 0}, pidConstants consstants3 ={0, 0, 0});
extern double true_target;
extern void forward_movem(float target, float timeout, float endsp = 1, float dist = 1, bool headc = true, pidConstants constants = {0.3, 0, 4.5}, pidConstants constants2 = {0.1, 0, 4}, bool slowd = true, int pist_down = 200); //change constants here !!! //0.6, 0, 6.75 // 4.6, 0, 0 10
#endif

