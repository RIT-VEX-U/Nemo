#include "competition/opcontrol.h"
#include "robot-config.h"
/**
 * Contains the main loop of the robot code while running in the driver-control period.
 */

void pressA() {
  Brain.Screen.printAt(20, 20, "%f, %f, %f", odometry.get_position().x, odometry.get_position().y, odometry.get_position().rot);
}

void pressB() {
  Brain.Screen.clearScreen();
}

void opcontrol()
{
  // Initialization
  main_controller.ButtonA.pressed(pressA);
  // Periodic
  while(true)
  {
    
    // ========== DRIVING CONTROLS ==========
    drive_system.drive_tank(main_controller.Axis3.position() / 100.0, main_controller.Axis2.position() / 100.0);

    // ========== MANIPULATING CONTROLS ==========

    // ========== SECONDARY REMOTE ==========

    // ========== AUTOMATION ==========    


    // Wait 20 milliseconds for control loops to calculate time correctly
    vexDelay(20);
  }
}