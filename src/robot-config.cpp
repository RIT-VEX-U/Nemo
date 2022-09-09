#include "vex.h"

using namespace vex;

// A global instance of brain used for printing to the V5 brain screen
brain Brain;
controller main_controller;
// ======== OUTPUTS ========

// ======== INPUTS ========

// ======== SUBSYSTEMS ========

// ======== UTILS ========
motor motorru(PORT20), motorrb(PORT19), motorlu(PORT11, true), motorlb(PORT12, true);

motor_group left_motors = {motorlu, motorlb};
motor_group right_motors = {motorru, motorrb};

robot_specs_t robot_cfg = {
  .robot_radius = 12, // inches
  .odom_wheel_diam = 2.85,//4.25, // inches
  .odom_gear_ratio = 1.03,//2.333333, // inches
  .dist_between_wheels = 9.75, // inches
  .drive_correction_cutoff = 12, //inches
  .drive_pid = (PID::pid_config_t) 
  {
    .p = .2,
    .i = .1,
    .d = .02,
    .f = 0,
    .k = .05,
    .deadband = .5,
    .on_target_time = .1
  },
  .turn_pid = (PID::pid_config_t)
  {
    .p = 0.06,
    .i = 0.05,
    .d = 0.004,
    .k = .005,
    .f = 0,
    .deadband = 2,
    .on_target_time = 0.1
  },
  .correction_pid = (PID::pid_config_t)
  {
    .p = 0.02,
    .d = 0.001
  }
};

TankDrive drive(left_motors, right_motors, robot_cfg);
/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void) {

}