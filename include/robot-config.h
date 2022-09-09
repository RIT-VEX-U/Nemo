#pragma once
#include "core.h"

using namespace vex;

extern brain Brain;
extern controller main_controller;

// ======== OUTPUTS ========
extern motor motorru, motorrb, motorlu, motorlb;
extern motor_group left_motors, right_motors;
// ======== INPUTS ========

// ======== SUBSYSTEMS ========
extern TankDrive drive;
// ======== UTILS ========

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void);

