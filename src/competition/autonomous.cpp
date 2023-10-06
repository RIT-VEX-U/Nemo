#include "competition/autonomous.h"

#include "robot-config.h"

/**
 * Contains all the code run during autonomous.
 */ 
void autonomous()
{
    printf("starting!\n");
    fflush(stdout);

    CommandController command_controller;
    command_controller.add(new DriveForwardCommand(drive_system, motion_controller, 18.0, directionType::fwd, 1, 30));
    command_controller.add(new DriveForwardCommand(drive_system, motion_controller, 18.0, directionType::fwd, 1, 30));
    command_controller.add(new DriveForwardCommand(drive_system, motion_controller, 18.0, directionType::fwd, 1, 15));
    command_controller.add(new DriveForwardCommand(drive_system, motion_controller, 18.0, directionType::fwd, 1, 30));
    command_controller.add(new DriveForwardCommand(drive_system, motion_controller, 18.0, directionType::fwd, 1, 0));
    
    command_controller.add(new DriveForwardCommand(drive_system, motion_controller, -18.0, directionType::rev, 1, -30));
    command_controller.add(new DriveForwardCommand(drive_system, motion_controller, -18.0, directionType::rev, 1, -30));
    command_controller.add(new DriveForwardCommand(drive_system, motion_controller, -18.0, directionType::rev, 1, -15));
    command_controller.add(new DriveForwardCommand(drive_system, motion_controller, -18.0, directionType::rev, 1, -30));
    command_controller.add(new DriveForwardCommand(drive_system, motion_controller, -18.0, directionType::rev, 1, 0));
    command_controller.run();

    // while ( drive_system.drive_forward(12.0, directionType::fwd, motion_controller) == false ) { vexDelay(50); };
    // while ( drive_system.drive_forward(2 * 12, directionType::fwd, 0.25) == false ) { vexDelay(50); }
    // while ( drive_system.turn_degrees(90, 0.25) == false ) { vexDelay(50); }
    // while ( drive_system.drive_forward(2 * 12, directionType::fwd, 0.25) == false ) { vexDelay(50); }
    // while ( drive_system.turn_degrees(90, 0.25) == false ) { vexDelay(50); }
    // while ( drive_system.drive_forward(2 * 12, directionType::fwd, 0.25) == false ) { vexDelay(50); }
    // while ( drive_system.turn_degrees(90, 0.25) == false ) { vexDelay(50); }
    // while ( drive_system.drive_forward(2 * 12, directionType::fwd, 0.25) == false ) { vexDelay(50); }
    // while ( drive_system.turn_degrees(90, 0.25) == false ) { vexDelay(50); }
}