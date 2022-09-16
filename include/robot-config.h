#pragma once
#include "vex.h"
#include "core.h"

using namespace vex;

extern brain Brain;
extern controller main_controller;

// ======== OUTPUTS ========

extern motor driveLeftRear,driveLeftFront, driveRightRear, driveRightFront;
extern motor_group leftDrive,rightDrive;

// ======== INPUTS ========

extern CustomEncoder rightEncoder,leftEncoder;
extern bumper bumperButton;
extern vex::distance distanceSensor;

// ======== SUBSYSTEMS ========
extern TankDrive drive;
extern inertial imu;
extern robot_specs_t robot_cfg;
extern OdometryTank odom;

// ======== UTILS ========

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void);

