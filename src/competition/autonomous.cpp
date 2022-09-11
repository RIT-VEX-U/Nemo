#include "competition/autonomous.h"
#include "robot-config.h"

/**
 * Contains all the code run during autonomous.
 */ 

void autonomous()
{
  // drive_system.drive_tank(.25, .25);
  // wait(4, seconds);
  for(int iii = 0; iii < 4; iii++) {
    drive_system.drive_forward(12, .25, 1, fwd);
    drive_system.turn_degrees(90, .25);
  }
  drive_system.stop();
}