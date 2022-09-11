#include "competition/opcontrol.h"
#include "robot-config.h"
/**
 * Contains the main loop of the robot code while running in the driver-control period.
 */
void opcontrol()
{
  // Initialization

  //main_controller.Screen.print("Beginning");

  // Periodic
  while(true)
  {
    float sensitivity = 0.5;
 
    // ========== DRIVING CONTROLS ==========
    double leftJoy = main_controller.Axis3.position();
    double rightJoy = main_controller.Axis2.position();
    drive_sys.drive_tank(leftJoy*sensitivity, rightJoy*sensitivity);



    // ========== MANIPULATING CONTROLS ==========
    // ========== SECONDARY REMOTE ==========
    // ========== AUTOMATION ==========    

    // Wait 20 milliseconds for control loops to calculate time correctly
    vexDelay(20);
  }
}