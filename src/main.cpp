/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\ryan                                             */
/*    Created:      Wed Aug 31 2022                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "robot-config.h"
// #include "competition/opcontrol.h"
// #include "competition/autonomous.h"

using namespace vex;

competition comp;


void autonomous() {
  for (int i = 0; i < 1; i++) {
    vex::wait(1, sec);
    while (!drive_system.drive_forward(5, 0.1, 0, vex::forward)) {
      vex::wait(10, msec);
      Brain.Screen.clearScreen();
      Brain.Screen.printAt(20, 20, "%f, %f, %f", odometry.get_position().x, odometry.get_position().y, odometry.get_position().rot);
    }
    // drive_system.turn_degrees(90.0, 0.1);
  }
}

void pressA() {
  Brain.Screen.printAt(20, 20, "%f, %f, %f", odometry.get_position().x, odometry.get_position().y, odometry.get_position().rot);
}

void pressB() {
  Brain.Screen.clearScreen();
}

void opcontrol() {
  main_controller.ButtonA.pressed(pressA);
  while(1) {
    // main_controller.ButtonB.pressed(pressB);
    drive_system.drive_tank(main_controller.Axis3.position() / 100.0, main_controller.Axis2.position() / 100.0);
  }
  vex::wait(10, msec);
}

/**
 * The main method of the robot.
 * Do NOT use for general programming or initialization.
 * Instead use competition/opcontrol.cpp, competition/autonomous.cpp, or robot-config.cpp for programming or configuration.
 */
int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  comp.autonomous(autonomous);
  comp.drivercontrol(opcontrol);
  vexcodeInit();
}
