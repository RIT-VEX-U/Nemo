#include "robot-config.h"

using namespace vex;

// A global instance of brain used for printing to the V5 brain screen
brain Brain;

controller main_controller;

// ======== OUTPUTS ========

motor lftFrnt = motor{PORT1,true};
motor lftBack = motor{PORT2,true};
motor rgtFrnt = motor{PORT3};
motor rgtBack = motor{PORT4};

motor_group leftSide = motor_group{lftFrnt,lftBack};
motor_group rightSide = motor_group{rgtFrnt,rgtBack};

// ======== INPUTS ========

inertial imu(PORT5);
CustomEncoder rgtEnc = CustomEncoder{Brain.ThreeWirePort.A,90};
CustomEncoder lftEnc = CustomEncoder{Brain.ThreeWirePort.C,90};

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

OdometryTank odom = OdometryTank{lftEnc,rgtEnc,robot_cfg,&imu,true};

TankDrive tank = TankDrive(leftSide,rightSide,robot_cfg,&odom);
// ======== UTILS ========

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void) {

}