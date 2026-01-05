#include "main.h"
#include "pros/adi.hpp"
#include "pros/imu.hpp"
#include "pros/misc.hpp"
#include "pros/motors.hpp"
#ifndef ROBOTH
#define ROBOTH

extern pros::Controller controller;

extern pros::Motor lf;
extern pros::Motor lm;
extern pros::Motor lb;
extern pros::Motor rf;
extern pros::Motor rm;
extern pros::Motor rb;

extern pros::Motor bint;
extern pros::Motor mint;
extern pros::Motor tint;

extern pros::ADIDigitalOut und;
extern pros::ADIDigitalOut desc;
extern pros::ADIDigitalOut mpist;
extern pros::ADIDigitalOut matchp;

extern pros::Optical opsens;
extern pros::Optical hfill;

extern pros::Imu imu;



#endif