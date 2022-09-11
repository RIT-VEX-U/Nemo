#include "robot-config.h"

using namespace vex;

// A global instance of brain used for printing to the V5 brain screen
brain Brain;

// ======== OUTPUTS ========

// ======== INPUTS ========

inertial imu(PORT1);
CustomEncoder tracking_enc(Brain.ThreeWirePort.A, 2048);

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
    .i = .001,
    .d = .008,
    .f = 0,
    .k = .05,
    .deadband = 0.3,
    .on_target_time = 0
  },
  .turn_pid = (PID::pid_config_t)
  {
    .p = 0.025,
    .i = 0.01,
    .d = 0.0015,
    .f = 0,
    .deadband = 5,
    .on_target_time = 0.1
  },
  .correction_pid = (PID::pid_config_t)
  {
    .p = .01,
  }
};
motor leftMotorF = motor(PORT11, true);
motor leftMotorB = motor(PORT12, true);

motor rightMotorF = motor(PORT20);
motor rightMotorB = motor(PORT19);


motor_group leftMotors = {leftMotorF, leftMotorB};
motor_group rightMotors = {rightMotorF, leftMotorF};


OdometryTank odom(tracking_enc, tracking_enc, robot_cfg, &imu);


TankDrive drive_sys = TankDrive(leftMotors, rightMotors, robot_cfg, &odom);

controller main_controller;

// ======== UTILS ========

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void) {

}