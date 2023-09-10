#include "competition/autonomous.h"
#include "robot-config.h"

/**
 * Contains all the code run during autonomous.
 */ 
void autonomous()
{
    for (int i = 0; i < 4; i++) {
        while (!drive_system.drive_forward(10, fwd, 0.2)) {
            vexDelay(10);
        }
        while (!drive_system.turn_degrees(90, 0.2)) {
            vexDelay(10);
        }
    }

}