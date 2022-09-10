#include "vex.h"

using namespace vex;

// A global instance of brain used for printing to the V5 brain screen
brain Brain;
controller main_controller;

// ======== OUTPUTS ========
motor driveLeftFront(PORT11,true), driveLeftRear(PORT12,true),
driveRightRear(PORT19),driveRightFront(PORT20);

motor_group leftDrive={driveLeftFront,driveLeftRear};
motor_group rightDrive={driveLeftFront,driveLeftRear};
// ======== INPUTS ========
CustomEncoder leftEncoder(Brain.ThreeWirePort.C, 2048);
CustomEncoder rightEncoder(Brain.ThreeWirePort.E,2048);

// ======== SUBSYSTEMS ========

// ======== UTILS ========

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void) {

}