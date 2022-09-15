#pragma once
#include "vex.h"
#include "core.h"

using namespace vex;

extern brain Brain;
extern controller main_controller;

// ======== OUTPUTS ========
extern motor motorru, motorrb, motorlu, motorlb;
extern motor_group left_motors, right_motors;
// ======== INPUTS ========

extern inertial imu;

// ======== SUBSYSTEMS ========
extern TankDrive drive;

extern robot_specs_t robot_cfg;
extern OdometryTank odom;

// ======== UTILS ========

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void);

