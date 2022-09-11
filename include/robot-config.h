#pragma once
#include "vex.h"
#include "core.h"

using namespace vex;

extern brain Brain;
extern controller main_controller;

// ======== OUTPUTS ========

// ======== INPUTS ========

extern inertial imu;

// ======== SUBSYSTEMS ========

extern robot_specs_t robot_cfg; 
extern OdometryTank odom;

extern motor leftMotorF;
extern motor rightMotorF;
extern motor leftMotorB;
extern motor rightMotorB;

extern motor_group leftMotors;
extern motor_group rightMotors;

extern TankDrive drive_sys;

// ======== UTILS ========

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void);

