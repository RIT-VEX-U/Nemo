#include "competition/autonomous.h"

#include "robot-config.h"

/**
 * Contains all the code run during autonomous.
 */ 
void autonomous()
{
    printf("starting!\n");
    fflush(stdout);

    CommandController command_controller {
        drive_system.DriveForwardCmd(motion_controller, 18.0, directionType::fwd, 1, 30),
        drive_system.DriveForwardCmd(motion_controller, 18.0, directionType::fwd, 1, 30),
        drive_system.DriveForwardCmd(motion_controller, 18.0, directionType::fwd, 1, 15),
        drive_system.DriveForwardCmd(motion_controller, 18.0, directionType::fwd, 1, 30),
        drive_system.DriveForwardCmd(motion_controller, 18.0, directionType::fwd, 1, 0),
        
        drive_system.DriveForwardCmd(motion_controller, -18.0, directionType::rev, 1, -30),
        drive_system.DriveForwardCmd(motion_controller, -18.0, directionType::rev, 1, -30),
        drive_system.DriveForwardCmd(motion_controller, -18.0, directionType::rev, 1, -15),
        drive_system.DriveForwardCmd(motion_controller, -18.0, directionType::rev, 1, -30),
        drive_system.DriveForwardCmd(motion_controller, -18.0, directionType::rev, 1, 0),
    };
    command_controller.run();
}