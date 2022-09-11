#pragma once
#include "vex.h"
#include "core.h"

using namespace vex;

extern brain Brain;
extern controller main_controller;

extern motor leftFront;
extern motor leftBack;
extern motor rightFront;
extern motor rightBack;

extern inertial IMU;

// extern encoder leftEncoder;
// extern encoder rightEncoder;

extern motor_group leftWheels;
extern motor_group rightWheels;

extern TankDrive drive_system;

extern OdometryTank odometry_tank;
extern TankDrive drive_system;

// ======== OUTPUTS ========

// ======== INPUTS ========

extern inertial imu;

// ======== SUBSYSTEMS ========

extern robot_specs_t robot_cfg;
extern OdometryTank odom;

// ======== UTILS ========

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void);

