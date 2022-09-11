#include "competition/opcontrol.h"
#include "robot-config.h"

/**
 * Contains the main loop of the robot code while running in the driver-control period.
 */
void opcontrol()
{
  // Initialization
  static bool controlMode = true;
  double left, right;

  // Periodic
  while(true)
  {
    
    // ========== DRIVING CONTROLS ==========
    left = main_controller.Axis3.position() / 100.0;
    right = main_controller.Axis2.position() / 100.0;

    if(controlMode){
      drive_system.drive_tank(left, right);
    }
    else{
      drive_system.drive_arcade(left, right);
    }

    main_controller.ButtonR2.pressed([]() { 
      controlMode = false; 
    });
    main_controller.ButtonL2.pressed([]() { 
      controlMode = true; 
    });
    // ========== MANIPULATING CONTROLS ==========

    // ========== SECONDARY REMOTE ==========

    // ========== AUTOMATION ==========    


    // Wait 20 milliseconds for control loops to calculate time correctly
    vexDelay(20);
  }
}