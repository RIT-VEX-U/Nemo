#include "competition/autonomous.h"

#include "robot-config.h"

/**
 * Contains all the code run during autonomous.
 */ 
void autonomous()
{
    printf("starting!\n");
    fflush(stdout);

    std::vector<point_t> path = {
        {0, 0},
        {15.7, 68},
        {10.4, 86.5},
        {-3.5, 82.3},
        {-15, 77.3},
        {-22.6, 98.6},
        {9.2, 122}
    };

    CommandController command_controller {
        drive_system.PurePursuitCmd(motion_controller, path, directionType::fwd, 1, 0)
        // drive_system.DriveForwardCmd(motion_controller, 18.0, directionType::fwd, 1, 30),
        // drive_system.DriveForwardCmd(motion_controller, 18.0, directionType::fwd, 1, 30),
        // drive_system.DriveForwardCmd(motion_controller, 18.0, directionType::fwd, 1, 15),
        // drive_system.DriveForwardCmd(motion_controller, 18.0, directionType::fwd, 1, 30),
        // drive_system.DriveForwardCmd(motion_controller, 18.0, directionType::fwd, 1, 0),
        
        // drive_system.DriveForwardCmd(motion_controller, -18.0, directionType::rev, 1, -30),
        // drive_system.DriveForwardCmd(motion_controller, -18.0, directionType::rev, 1, -30),
        // drive_system.DriveForwardCmd(motion_controller, -18.0, directionType::rev, 1, -15),
        // drive_system.DriveForwardCmd(motion_controller, -18.0, directionType::rev, 1, -30),
        // drive_system.DriveForwardCmd(motion_controller, -18.0, directionType::rev, 1, 0),
    };
    command_controller.run();
}