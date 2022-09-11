#include "robot-config.h"

using namespace vex;

// A global instance of brain used for printing to the V5 brain screen
brain Brain;

// ======== OUTPUTS ========

// ======== INPUTS ========

inertial imu(PORT1);

// ======== SUBSYSTEMS ========

robot_specs_t robot_cfg = {

    .drive_pid = (PID::pid_config_t){
        .p = .5,
        .i = .00,
        .d = .02,
        .f = 0,
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
        .p = 0.01
    },

    .odom_wheel_diam = 4.24,
    .odom_gear_ratio = 2.333333,
    .dist_between_wheels = 9.75
};

// ======== UTILS ========

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void) {

}