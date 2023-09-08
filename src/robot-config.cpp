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
OdometryTank odometry(left_odom_wheel, right_odom_wheel, config);
TankDrive drive_system(left_drive, right_drive, config, &odometry);

// ======== INPUTS ========
controller main_controller = controller(primary);
inertial imu(PORT10);

// ======== SUBSYSTEMS ========
PID::pid_config_t drive_pid_cfg = {
    .p = .05,
    .i = 0.00,
    .d = 0.02,
    .deadband = 0.1,
    .on_target_time = 0.1};

PID::pid_config_t turn_pid_cfg = {
    .p = .03,
    .i = 0.0,
    .d = .02,
    .deadband = 2.0,
    .on_target_time = .1};

robot_specs_t config = {
    .robot_radius = 12,
    .odom_wheel_diam = 2.84,
    .odom_gear_ratio = 1.03, // .44    16:12
    .dist_between_wheels = 9.18,

    .drive_correction_cutoff = 12,

    .drive_feedback = new PID(drive_pid_cfg),
    .turn_feedback = new PID(turn_pid_cfg),
    .correction_pid = {
        .p = .01,
        .i = 0,
        .d = 0.0012}};

// ======== UTILS ========

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void) {

}