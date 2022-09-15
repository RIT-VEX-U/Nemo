#include "competition/opcontrol.h"
#include "robot-config.h"
/**
 * Contains the main loop of the robot code while running in the driver-control period.
 */


double mvelocity = 1.0;

void speed_up(){
  if(mvelocity < 1.0){
    mvelocity += 0.25;
  }
}
void slow_down(){
  if(mvelocity > 0){
    mvelocity -= 0.25;
  }
}


void opcontrol()
{
  // Initialization

  // Periodic
  while(true)
  {
    drive.drive_tank(main_controller.Axis3.position() / 100.0, main_controller.Axis2.position() / 100.0, 2);
    // ========== DRIVING CONTROLS ==========
    // if(main_controller.ButtonA.pressing()){
    //   motora.spin(forward, 0.5, pct);
    // }
    // if(main_controller.ButtonB.pressing()){
    //   motorb.spin(forward, 0.5, pct);
    // }
    // if(main_controller.ButtonX.pressing()){
    //   motorx.spin(forward, 0.5, pct);
    // }
    // if(main_controller.ButtonY.pressing()){
    //   motory.spin(forward, 0.5, pct);
    // }
    // if(main_controller.ButtonRight.pressing()){
    //   motorr.spin(forward, 0.5, pct);
    // }
    // if(main_controller.ButtonLeft.pressing()){
    //   motorl.spin(forward, 0.5, pct);
    // }
    // if(main_controller.ButtonUp.pressing()){
    //   motoru.spin(forward, 0.5, pct);
    // }
    // if(main_controller.ButtonDown.pressing()){
    //   motord.spin(forward, 0.5, pct);
    // }
    // ========== MANIPULATING CONTROLS ==========

    // ========== SECONDARY REMOTE ==========

    // ========== AUTOMATION ==========    


    // Wait 20 milliseconds for control loops to calculate time correctly
    vexDelay(20);
  }
}
