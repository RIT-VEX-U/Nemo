#include "competition/opcontrol.h"
#include "robot-config.h"

#define ENC_IN(enc) (enc.position(rev) * PI * robot_cfg.odom_wheel_diam)
#define ENC_DIFF_IN(left, right) (fabs(ENC_IN(left) - ENC_IN(right)) / 2.0)

enum DriveType
{
    DRIVE, TURN
};

double stored_avg = 0;
double stored_num = 0;
double continuous_avg(double updateval)
{
    stored_num++;

    if (stored_num < 1)
    {
        stored_avg = 0.0;
    }
    else
    {
        stored_avg = (stored_avg * (stored_num - 1) / stored_num) + (updateval / stored_num);
    }
    return stored_avg;
}

void reset_avg_counter()
{
    stored_avg = 0;
    stored_num = 0;
}

void tune_odometry_wheel_diam()
{
    if (main_controller.ButtonA.pressing())
    {
        // SET THESE BACK TO LEFT ENC RIGHT ENC
        // left_motors.resetPosition();
        // right_motors.resetPosition();
        left_odom_wheel.resetRotation();
        right_odom_wheel.resetRotation();
    }
    double avg = (fabs(left_odom_wheel.rotation(rev)) + fabs(right_odom_wheel.rotation(rev))) / 2.0;
    // double avg = (fabs(left_motors.position(rev)) + fabs(right_motors.position(rev))) / 2.0;
    if (fabs(avg) < .1)
    {
        printf("Diam: 0\n");
        return;
    }
    double diam = 100.0 / (avg * PI);

    main_controller.Screen.clearScreen();
    main_controller.Screen.setCursor(1, 1);
    main_controller.Screen.print("Push robot 100 inches");
    main_controller.Screen.setCursor(2, 1);
    main_controller.Screen.print("Diam: %f", diam);
    printf("Diam: %f\n", diam);
}

void tune_odometry_wheelbase()
{
    int times_to_turn = 5;
    if (main_controller.ButtonA.pressing())
    {
        left_odom_wheel.resetRotation();
        right_odom_wheel.resetRotation();
        // left_motors.resetPosition();
        // right_motors.resetPosition();
    }
    double radius =  ENC_DIFF_IN(left_odom_wheel, right_odom_wheel) / ((double)times_to_turn * 2 * PI); // radius = arclength / theta
    // double radius = ENC_DIFF_IN(left_motors, right_motors) / ((double)times_to_turn * 2 * PI); // radius = arclength / theta

    double wheelbase = 2 * radius;

    main_controller.Screen.clearScreen();
    main_controller.Screen.setCursor(1, 1);
    main_controller.Screen.print("Turn the robot in place %d times", times_to_turn);
    main_controller.Screen.setCursor(2, 1);
    main_controller.Screen.print("Wheelbase: %f", wheelbase);
    printf("Wheelbase: %f\n", wheelbase);
}

// Drive Tuning
void tune_drive_ff_ks(DriveType dt)
{
    static timer tmr;
    static double test_pct = 0.0;
    static bool new_press = true;
    static bool done = false;

    if (main_controller.ButtonA.pressing())
    {
        if (new_press)
        {
            // Initialize the function once
            tmr.reset();
            left_odom_wheel.resetRotation();
            right_odom_wheel.resetRotation();
            // left_motors.resetPosition();
            // right_motors.resetPosition();
            test_pct = 0.0;
            done = false;
            new_press = false;
        }

        if (done || (fabs(left_odom_wheel.position(rev)) + fabs(right_odom_wheel.position(rev))) > 0)
        {
            main_controller.Screen.clearScreen();
            main_controller.Screen.setCursor(1, 1);
            main_controller.Screen.print("kS: %f", test_pct);
            printf("kS: %f\n", test_pct);
            done = true;
            return;
        }
        else
        {
            main_controller.Screen.clearScreen();
            main_controller.Screen.setCursor(1, 1);
            main_controller.Screen.print("Running...");
        }

        if (tmr.time() > 500)
        {
            test_pct += 0.01;
            tmr.reset();
        }

        if (dt == DRIVE)
            drive_system.drive_tank(test_pct, test_pct);
        else if (dt == TURN)
            drive_system.drive_tank(test_pct, -test_pct);
    }
    else
    {
        drive_system.stop();
        new_press = true;
    }
}

void tune_drive_ff_kv(DriveType dt, double ks)
{
    static bool new_press = true;
    static timer tmr;

    static int start_delay_ms = 2000;

    if (main_controller.ButtonA.pressing())
    {
        if (new_press)
        {
            tmr.reset();
            reset_avg_counter();
            new_press = false;
        }

        double vel = 0;

        if (dt == DRIVE)
        {
            drive_system.drive_tank(0.5, 0.5);
            vel = odometry.get_speed();
        }
        else if (dt == TURN)
        {
            drive_system.drive_tank(0.5, -0.5);
            vel = odometry.get_angular_speed_deg();
        }

        double kv = 0;
        if(tmr.time(msec) > start_delay_ms)
            kv = (0.5 - ks) / continuous_avg(vel);

        main_controller.Screen.clearScreen();
        main_controller.Screen.setCursor(1, 1);
        main_controller.Screen.print("kV: %f", kv);
        printf("kV: %f\n", kv);
    }
    else
    {
        drive_system.stop();
        new_press = true;
    }
}


void tune_drive_motion_maxv(DriveType dt)
{
    static bool new_press = true;

    if (main_controller.ButtonA.pressing())
    {
        if (new_press)
        {
            reset_avg_counter();
            new_press = false;
        }

        double maxv = 0;

        if (dt == DRIVE)
        {
            drive_system.drive_tank(1.0, 1.0);
            maxv = continuous_avg(odometry.get_speed());
        }
        else if (dt == TURN)
        {
            drive_system.drive_tank(1.0, -1.0);
            maxv = continuous_avg(odometry.get_angular_speed_deg());
        }

        main_controller.Screen.clearScreen();
        main_controller.Screen.setCursor(1, 1);
        main_controller.Screen.print("maxV: %f", maxv);
        printf("maxV: %f\n", maxv);
    }
    else
    {
        drive_system.stop();
        new_press = true;
    }
}

/**
 * Contains the main loop of the robot code while running in the driver-control period.
 */
void opcontrol()
{
  // Initialization

    // odometry.set_position({0,0,0});
  // Periodic
  while(true)
  {
    
    // ========== DRIVING CONTROLS ==========

    // tune_drive_motion_maxv(DRIVE);
    
    static bool is_done = false;
    if(main_controller.ButtonA.pressing())
    {
      if (!is_done && drive_system.drive_forward(24,fwd))
        is_done = true;

    }else
    {
      is_done = false;
      drive_system.reset_auto();
      drive_system.drive_arcade(
        main_controller.Axis3.position(pct) / 100.0,
        main_controller.Axis1.position(pct) / 100.0);
    }

    pose_t p = odometry.get_position();
    printf("X: %.2f Y: %.2f, R: %.2f\n", p.x, p.y, p.rot);
    // ========== MANIPULATING CONTROLS ==========

    // ========== SECONDARY REMOTE ==========

    // ========== AUTOMATION ==========    


    // Wait 20 milliseconds for control loops to calculate time correctly
    vexDelay(20);
  }
}