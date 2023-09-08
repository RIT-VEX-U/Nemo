#include "competition/opcontrol.h"

/**
 * Contains the main loop of the robot code while running in the driver-control period.
 */
void opcontrol()
{
  // Initialization
  int xAxis;
  int yAxis;

  // Periodic
  while(true)
  {
    
    // ========== DRIVING CONTROLS ==========
    tank.drive_arcade(main_controller.Axis3.value()/100.0,main_controller.Axis1.value()/100.0,1);
    // ========== MANIPULATING CONTROLS ==========

    // ========== SECONDARY REMOTE ==========

    // ========== AUTOMATION ==========    


    // Wait 20 milliseconds for control loops to calculate time correctly
    vexDelay(20);
  }
}