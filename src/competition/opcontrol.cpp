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
    drive.drive_tank(main_controller.Axis3.position()/100.0, main_controller.Axis2.position()/100.0);

    // ========== MANIPULATING CONTROLS ==========

    // ========== SECONDARY REMOTE ==========

    // ========== AUTOMATION ==========    


    // Wait 20 milliseconds for control loops to calculate time correctly
    vexDelay(20);
  }
}