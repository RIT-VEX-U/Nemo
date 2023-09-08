#include "robot-config.h"

using namespace vex;

// A global instance of brain used for printing to the V5 brain screen
brain Brain;
controller main_controller;

// ======== OUTPUTS ========

motor left_front(PORT1, vex::gearSetting::ratio18_1, false), left_back(PORT2, vex::gearSetting::ratio18_1, false);
motor right_front(PORT3, vex::gearSetting::ratio18_1, true), right_back(PORT4, vex::gearSetting::ratio18_1, true);

motor_group left_motors(left_front, left_back), right_motors(right_front, right_back);

// ======== INPUTS ========

inertial imu(PORT1);

// ======== SUBSYSTEMS ========
PID::pid_config_t drive_pid_cfg =
{
  .p = .1,
  .i = .001,
  .d = .008,
  .deadband = 0.3,
  .on_target_time = 0
};

PID::pid_config_t turn_pid_cfg = 
{
  .p = 0.025,
  .i = 0.01,
  .d = 0.0015,
  .deadband = 5,
  .on_target_time = 0.1
};

robot_specs_t robot_cfg = {
  .robot_radius = 12, // inches
  .odom_wheel_diam = 2.84, // inches
  .odom_gear_ratio = 1.03, // inches
  .dist_between_wheels = 9.18, // inches
  .drive_correction_cutoff = 12, //inches
  .drive_feedback = new PID(drive_pid_cfg),
  .turn_feedback = new PID(turn_pid_cfg),
  .correction_pid = (PID::pid_config_t)
  {
    .p = .01,
  }
};

OdometryTank odometry(left_motors, right_motors, robot_cfg, &imu);

TankDrive drive_system(left_motors, right_motors, robot_cfg, &odometry);

// ======== UTILS ========

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void) {
  
}