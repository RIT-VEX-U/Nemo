#include "competition/autonomous.h"
#include "robot-config.h"
/**
 * Contains all the code run during autonomous.
 */ 
CommandController drive_square() {

    CommandController ds;
    ds.add(new DriveForwardCommand(drive_system, *config.drive_feedback, 24, vex::forward, 1));
    ds.add(new TurnToHeadingCommand(drive_system, *config.turn_feedback, 180, 1));
    ds.add(new DriveForwardCommand(drive_system, *config.drive_feedback, 24, vex::forward, 1));
    ds.add(new TurnToHeadingCommand(drive_system, *config.turn_feedback, 270, 1));
    ds.add(new DriveForwardCommand(drive_system, *config.drive_feedback, 24, vex::forward, 1));
    ds.add(new TurnToHeadingCommand(drive_system, *config.turn_feedback, 0, 1));
    ds.add(new DriveForwardCommand(drive_system, *config.drive_feedback, 24, vex::forward, 1));
    ds.add(new TurnToHeadingCommand(drive_system, *config.turn_feedback, 90, 1));
    return ds;
}


void autonomous()
{
    CommandController current_auto = drive_square();
    Brain.Screen.print("made it to here");
    current_auto.run();

}