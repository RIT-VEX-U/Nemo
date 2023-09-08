#pragma once
#include "vex.h"
#include "core.h"

using namespace vex;

extern brain Brain;

extern controller main_controller;

// ======== OUTPUTS ========

extern motor lftFrnt;
extern motor lftBack;
extern motor rgtFrnt;
extern motor rgtBack;

extern motor_group rightSide;
extern motor_group leftSide;

// ======== INPUTS ========

extern inertial imu;
extern CustomEncoder rgtEnc;
extern CustomEncoder lftEnc;

// ======== SUBSYSTEMS ========

extern robot_specs_t robot_cfg;
extern OdometryTank odom;
extern TankDrive tank;
// ======== UTILS ========

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void);

