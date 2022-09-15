#include "competition/autonomous.h"
#include "robot-config.h"

/**
 * Contains all the code run during autonomous.
 */ 
void autonomous()
{
  for(int i=1;i<=4;i++){
    while (drive.drive_forward(48, 0.8, 1.0, directionType::fwd) == false ) { vexDelay(50); }
    while (drive.turn_degrees(90, 1.0)==false) { vexDelay(50); }
  }
}