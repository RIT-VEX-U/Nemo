#include "competition/opcontrol.h"
#include "robot-config.h"

/**
 * Contains the main loop of the robot code while running in the driver-control period.
 */
void opcontrol()
{
  // Initialization


  // Periodic
  while(true)
  {
    
    // ========== DRIVING CONTROLS ==========
    double left = main_controller.Axis1.position();
    double right = main_controller.Axis2.position();
    drive_system.drive_tank(left, right);
    
    // ========== MANIPULATING CONTROLS ==========

    // ========== SECONDARY REMOTE ==========

    // ========== AUTOMATION ==========    


    // Wait 20 milliseconds for control loops to calculate time correctly
    vexDelay(20);
  }
}