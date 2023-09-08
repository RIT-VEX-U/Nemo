#include "competition/opcontrol.h"

#include "robot-config.h"

/**
 * Contains the main loop of the robot code while running in the driver-control period.
 */
void opcontrol()
{
  // Initialization

  int32_t left_position, right_position;

  // Periodic
  while(true)
  {

    // ========== DRIVING CONTROLS ==========

    left_position = main_controller.Axis3.position();
    right_position = main_controller.Axis2.position();

    Brain.Screen.setCursor(1, 1);
    Brain.Screen.print("left: %ld\tright: %ld   ", left_position, right_position);

    left_motors.spin(fwd, left_position, pct);
    right_motors.spin(fwd, right_position, pct);

    // ========== MANIPULATING CONTROLS ==========

    // ========== SECONDARY REMOTE ==========

    // ========== AUTOMATION ==========    


    // Wait 20 milliseconds for control loops to calculate time correctly
    vexDelay(20);
  }
}