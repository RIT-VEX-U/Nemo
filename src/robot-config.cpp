#include "robot-config.h"

using namespace vex;

// A global instance of brain used for printing to the V5 brain screen
brain Brain;
controller main_controller;

vex::motor leftFront(11, true);
vex::motor leftBack(12, true);
vex::motor rightFront(20);
vex::motor rightBack(19);

// encoder leftEncoder(triport(int32_t C));
// encoder rightEncoder(triport(int32_t E));

motor_group leftWheels(leftFront, leftBack);
motor_group rightWheels(rightFront, rightBack);

OdometryTank odom(leftWheels, rightWheels, robot_cfg, &imu);
TankDrive drive_system(leftWheels, rightWheels, robot_cfg, &odom);

// ======== OUTPUTS ========

// ======== INPUTS ========

inertial imu(PORT1);

// ======== SUBSYSTEMS ========

robot_specs_t robot_cfg = {
  .robot_radius = 12, // inches
  .odom_wheel_diam = 2.84, // inches
  .odom_gear_ratio = 1.03, // inches
  .dist_between_wheels = 9.18, // inches
  .drive_correction_cutoff = 12, //inches
  .drive_pid = (PID::pid_config_t) 
  {
    .p = .1,
    .i = .01,
    .d = .008,
    .f = 0,
    .k = .05,
    .deadband = 0.5,
    .on_target_time = 0
  },
  .turn_pid = (PID::pid_config_t)
  {
    .p = 0.025,
    .i = 0.01,
    .d = 0.0015,
    .f = 0,
    .deadband = 7.5,
    .on_target_time = 0.1
  },
  .correction_pid = (PID::pid_config_t)
  {
    .p = .01,
  }
};








// ======== UTILS ========

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void) {

}