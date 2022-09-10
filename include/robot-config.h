#pragma once
#include "core.h"

using namespace vex;

extern brain Brain;
extern controller main_controller;

// ======== OUTPUTS ========

extern motor driveLeftRear,driveLeftFront, driveRightRear, driveRightFront;
extern motor_group leftDrive,rightDrive;

// ======== INPUTS ========

extern CustomEncoder rightEncoder,leftEncoder;

// ======== SUBSYSTEMS ========
extern TankDrive drive;
// ======== UTILS ========

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void);

