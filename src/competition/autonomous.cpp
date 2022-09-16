#include "competition/autonomous.h"
#include "robot-config.h"
/**
 * Contains all the code run during autonomous.
 */ 
void autonomous()
{
  drive.drive_tank(0.75,0.75,2);
  vexDelay(1400);
  drive.drive_tank(-0.5,0.5,2);
  vexDelay(775);
  drive.drive_tank(0.75,0.75,2);
  vexDelay(600);
  drive.drive_tank(-0.5,0.5,2);
  vexDelay(725);
  drive.drive_tank(0.75,0.75,2);
  vexDelay(1400);
  drive.drive_tank(-0.5,0.5,2);
  vexDelay(725);
  drive.drive_tank(0.75,0.75,2);
  vexDelay(600);
  drive.drive_tank(-0.5,0.5,2);
  vexDelay(725);
  drive.drive_tank(0,0,2);
}