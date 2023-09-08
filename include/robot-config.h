#pragma once
#include "vex.h"
#include "core.h"

using namespace vex;

extern brain Brain;
extern controller main_controller;

// ======== OUTPUTS ========

// ======== INPUTS ========

extern inertial imu;

// ======== SUBSYSTEMS ========
extern PID::pid_config_t drive_pid_cfg, turn_pid_cfg;
extern robot_specs_t config;
// extern OdometryTank odom;

// ======== UTILS ========
extern motor left_front;
extern motor left_back;
extern motor right_front;
extern motor right_back;
extern motor_group left_drive;
extern motor_group right_drive;
extern CustomEncoder left_odom_wheel;
extern CustomEncoder right_odom_wheel;
extern OdometryTank odometry;
extern TankDrive drive_system;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void);

