#pragma once
#include "vex.h"
#include "core.h"

using namespace vex;

extern brain Brain;
extern controller main_controller;

// ======== OUTPUTS ========

extern motor left_front, left_back, right_front, right_back;
extern motor_group left_motors, right_motors;

// ======== INPUTS ========

extern inertial imu;

extern CustomEncoder left_odom_wheel;
extern CustomEncoder right_odom_wheel;

// ======== SUBSYSTEMS ========

extern PID::pid_config_t drive_pid_cfg;
extern PID::pid_config_t turn_pid_cfg;

extern FeedForward::ff_config_t drive_ff_cfg;
extern FeedForward::ff_config_t turn_ff_cfg;

extern MotionController::m_profile_cfg_t drive_profile_cfg;
extern MotionController::m_profile_cfg_t turn_profile_cfg;

extern MotionController motion_controller;

extern robot_specs_t robot_cfg;
extern OdometryTank odometry;

extern TankDrive drive_system;

// ======== UTILS ========

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void);
