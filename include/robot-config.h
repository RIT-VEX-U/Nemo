#pragma once
#include "core.h"

using namespace vex;

extern brain Brain;
extern controller main_controller;

extern motor leftFront;
extern motor leftBack;
extern motor rightFront;
extern motor rightBack;
extern motor_group leftWheels;
extern motor_group rightWheels;
extern TankDrive drive_system;

// ======== OUTPUTS ========

// ======== INPUTS ========

// ======== SUBSYSTEMS ========

// ======== UTILS ========

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void);

