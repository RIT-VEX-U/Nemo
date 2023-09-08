#include "competition/autonomous.h"
#include "robot-config.h"
/**
 * Contains all the code run during autonomous.
 */ 
void autonomous()
{
    while (imu.isCalibrating()) {};

    for (int i = 0; i < 1; i++) {
        vex::wait(1, sec);
        while (!drive_system.drive_forward(5, 0.1, 0, vex::forward)) {
            vex::wait(10, msec);
            Brain.Screen.clearScreen();
            Brain.Screen.printAt(20, 20, "%f, %f, %f", odometry.get_position().x, odometry.get_position().y, odometry.get_position().rot);
        }
        // drive_system.turn_degrees(90.0, 0.1);
    } 
}