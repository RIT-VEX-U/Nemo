#include "competition/autonomous.h"

#include "robot-config.h"

/**
 * Contains all the code run during autonomous.
 */ 
void autonomous()
{
    while ( drive_system.drive_forward(2 * 12, directionType::fwd, 0.25) == false ) { vexDelay(50); }
    while ( drive_system.turn_degrees(90, 0.25) == false ) { vexDelay(50); }
    while ( drive_system.drive_forward(2 * 12, directionType::fwd, 0.25) == false ) { vexDelay(50); }
    while ( drive_system.turn_degrees(90, 0.25) == false ) { vexDelay(50); }
    while ( drive_system.drive_forward(2 * 12, directionType::fwd, 0.25) == false ) { vexDelay(50); }
    while ( drive_system.turn_degrees(90, 0.25) == false ) { vexDelay(50); }
    while ( drive_system.drive_forward(2 * 12, directionType::fwd, 0.25) == false ) { vexDelay(50); }
    while ( drive_system.turn_degrees(90, 0.25) == false ) { vexDelay(50); }
}