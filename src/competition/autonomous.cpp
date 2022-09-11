#include "competition/autonomous.h"
#include "robot-config.h"
/**
 * Contains all the code run during autonomous.
 */ 
void autonomous()
{


  imu.calibrate();
  while (imu.isCalibrating()){
    //vexDelay(20);
  }
  printf("finished calibrating");

  drive_sys.reset_auto();
  odom.set_position({.x=0,.y=0,.rot=90});

  double distance = .5 * 12; //inches
  double speed = 0.75;
  //double turn_speed = 0.1;
  //double angle_to_turn = 90; //degrees
  
  while (!drive_sys.drive_to_point(0,distance, speed, 0, directionType::fwd)){
    vexDelay(20);
  }
  while (!drive_sys.drive_to_point(distance, distance, speed, 0, directionType::fwd)){
    vexDelay(20);
  }
  while (!drive_sys.drive_to_point(distance,0, speed, 0, directionType::fwd)){
    vexDelay(20);
  }
  while (!drive_sys.drive_to_point(0, 0, speed, 0, directionType::fwd)){
    vexDelay(20);
  }
  



  /*
  for (int i=0; i<4; i++){

    while (!drive_sys.drive_forward(distance, speed, 0, directionType::fwd)){
      vexDelay(20);
    }
    //vexDelay(20);
    printf("finished line");

    while(!drive_sys.turn_degrees(angle_to_turn, turn_speed)){
      vexDelay(20);
    }
    printf("finished turn");

  }
  */
}