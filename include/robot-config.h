#pragma once
#include "core.h"

using namespace vex;

extern brain Brain;
extern controller main_controller;
extern bumper bumper1;
extern distance distance1;

// ======== OUTPUTS ========

// ======== INPUTS ========

// ======== SUBSYSTEMS ========

// ======== UTILS ========

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */


extern TankDrive drive;


void vexcodeInit(void);

