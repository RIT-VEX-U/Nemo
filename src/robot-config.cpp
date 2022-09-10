#include "vex.h"

using namespace vex;

// A global instance of brain used for printing to the V5 brain screen
brain Brain;
controller main_controller;

vex::motor leftFront(11);
vex::motor leftBack(12);
vex::motor rightFront(20);
vex::motor rightBack(19);

vex::encoder leftEncoder(triport(int32_t C));
vex::encoder rightEncoder(triport(int32_t E));

robot_specs_t robot_config;

vex::inertial IMU(1, vex::right);

vex::motor_group leftWheels(leftFront, leftBack);
vex::motor_group rightWheels(rightFront, rightBack);

TankDrive drive_system(leftWheels, rightWheels, robot_config);

// ======== OUTPUTS ========

// ======== INPUTS ========

// ======== SUBSYSTEMS ========

// ======== UTILS ========

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void) {

}