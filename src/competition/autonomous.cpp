#include "competition/autonomous.h"
#include "robot-config.h"

/**
 * Contains all the code run during autonomous.
 */ 

const char* SCREAM = "-------";
void autonomous()
{
  // drive_system.drive_tank(.25, .25);
  // wait(4, seconds);
  imu.calibrate();
  main_controller.rumble(SCREAM);
  while(imu.isCalibrating());
  for(int iii = 0; iii < 4; iii++) {
    odom.set_position({.x=0,.y=0,.rot=90});
    while(!drive_system.drive_to_point(0, 6, .5, 0)) {
      vexDelay(20);
    }
    main_controller.Screen.print("AAAAAAAAAAAAAAAAAAAAAA");
    // drive_system.drive_to_point(12, 0, .25, 0);
    // drive_system.drive_forward(12, .25, 0, fwd);

    while(!drive_system.turn_to_heading(180, .5)) {
      vexDelay(20);
    }
  }
  main_controller.rumble(SCREAM);
  drive_system.stop();
}