#include "competition/autonomous.h"

/**
 * Contains all the code run during autonomous.
 */ 
void autonomous()
{
  left_motors.spin(directionType::fwd, 0.5, pct);
  right_motors.spin(directionType::fwd, 0.5, pct);
  vexDelay(1000);
  left_motors.spin(directionType::fwd, 0, pct);
  right_motors.spin(directionType::fwd, 0.5, pct);
  vexDelay(1000);
  left_motors.spin(directionType::fwd, 0.5, pct);
  right_motors.spin(directionType::fwd, 0.5, pct);
  vexDelay(1000);
  left_motors.spin(directionType::fwd, 0, pct);
  right_motors.spin(directionType::fwd, 0.5, pct);
  vexDelay(1000);
  left_motors.spin(directionType::fwd, 0.5, pct);
  right_motors.spin(directionType::fwd, 0.5, pct);
  vexDelay(1000);
  left_motors.spin(directionType::fwd, 0, pct);
  right_motors.spin(directionType::fwd, 0.5, pct);
  vexDelay(1000);
  left_motors.spin(directionType::fwd, 0.5, pct);
  right_motors.spin(directionType::fwd, 0.5, pct);
  vexDelay(1000);
  left_motors.spin(directionType::fwd, 0, pct);
  right_motors.spin(directionType::fwd, 0.5, pct);
  vexDelay(1000);
}