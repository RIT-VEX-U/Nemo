#include "robot-config.h"

using namespace vex;

// A global instance of brain used for printing to the V5 brain screen
brain Brain;

// ======== OUTPUTS ========
motor left_front = motor(PORT1, true);
motor left_back = motor(PORT2, true);
motor right_front = motor(PORT3);
motor right_back = motor(PORT4);
motor_group left_drive = motor_group(left_front, left_back);
motor_group right_drive = motor_group(right_front, right_back);
CustomEncoder left_odom_wheel = CustomEncoder(Brain.ThreeWirePort.A, 90);
CustomEncoder right_odom_wheel = CustomEncoder(Brain.ThreeWirePort.C, 90);
OdometryTank odometry(left_odom_wheel, right_odom_wheel, robot_cfg);
TankDrive drive_system(left_drive, right_drive, robot_cfg, &odometry);

// ======== INPUTS ========
controller main_controller = controller(primary);
inertial imu(PORT10);

// ======== SUBSYSTEMS ========

robot_specs_t robot_cfg = {
  .robot_radius = 12, // inches
  .odom_wheel_diam = 2.84, // inches
  .odom_gear_ratio = 1.03, // inches
  .dist_between_wheels = 9.18, // inches
  .drive_correction_cutoff = 12, //inches
  .drive_pid = (PID::pid_config_t) 
  {
    .p = .5,
    .i = .00,
    .d = .02,
    .f = 0,
    .k = .0,
    .deadband = 0.1,
    .on_target_time = 0.1
  },
  .turn_pid = (PID::pid_config_t)
  {
    .p = 0.03,
    .i = 0.0,
    .d = 0.0015,
    .f = 0,
    .deadband = 2,
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