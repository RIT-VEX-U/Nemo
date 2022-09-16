#include "competition/autonomous.h"
#include "robot-config.h"

/**
 * Contains all the code run during autonomous.
 */ 
void autonomous()
{
  while (drive.drive_to_point(0, 1 ,0.8, 1.0, directionType::fwd) == false ) {vexDelay(50); }
  while (drive.turn_degrees(90, 1.0)==false) { vexDelay(50); }
  while (drive.drive_to_point(-1, 1 ,0.8, 1.0, directionType::fwd) == false ) {vexDelay(50); }
  while (drive.turn_degrees(90, 1.0)==false) { vexDelay(50); }
  while (drive.drive_to_point(-1, 0 ,0.8, 1.0, directionType::fwd) == false ) {vexDelay(50); }
  while (drive.turn_degrees(90, 1.0)==false) { vexDelay(50); }
  while (drive.drive_to_point(0, 0 ,0.8, 1.0, directionType::fwd) == false ) {vexDelay(50); }
  while (drive.turn_degrees(90, 1.0)==false) { vexDelay(50); }
  }



  // if(bumperButton.pressing()){
      //   puts("ouch!");
      // }
      // if(distanceSensor.objectDistance(mm)<=100){
      //   waitUntil(distanceSensor.objectDistance(mm)>100);
      // }