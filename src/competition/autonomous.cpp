#include "competition/autonomous.h"
#include "robot-config.h"

/**
 * Contains all the code run during autonomous.
 */ 
void autonomous()
{
    for (int i = 0; i < 4; i++)
    {
        drive_system.drive_forward(12, fwd, 0.2);
        drive_system.turn_degrees(90, 0.2);
    }
    
}