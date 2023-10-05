#include "competition/opcontrol.h"
#include "robot-config.h"
#include "../core/include/utils/generic_auto.h"
#include "mazegame.h"

// #define AUTOMODE
#define NEMO

#define BLUE_HUE 265
#define TILE_HUE 39
#define TILE_BRIGHT 11
#define WHITE_BRIGHT 21

#define HUE_DEADBAND 100
#define BRIGHT_DEADBAND 3 

/**
 * Contains the main loop of the robot code while running in the driver-control period.
 */
void opcontrol() 
{
  // ========== INIT ==========
  imu.calibrate();
  while(imu.isCalibrating()) {
    vexDelay(20);
    }

    position_t starting_pos = {
      #ifdef AUTOMODE
      .x = 12, 
      .y = 12,
      .rot=90
      #else
      .x = 12,
      .y = 13,
      .rot = 90
      #endif
    };
    odom.set_position(starting_pos);

    #ifdef AUTOMODE
    timer auto_t;
    #endif

    GenericAuto a1;
    a1.add([](){return drive.drive_to_point(12, 132, .5, .5);});
    a1.add([](){return drive.turn_to_heading(0, .5);});

    a1.add([](){return drive.drive_to_point(36, 132, .5, .5);});
    a1.add([](){return drive.turn_to_heading(270, .5);});

    a1.add([](){return drive.drive_to_point(36, 12, .5, .5);});
    a1.add([](){return drive.turn_to_heading(0, .5);});

    a1.add([](){return drive.drive_to_point(60, 12, .5, .5);});
    a1.add([](){return drive.turn_to_heading(90, .5);});

    a1.add([](){return drive.drive_to_point(60, 36, .5, .5);});
    a1.add([](){return drive.turn_to_heading(0, .5);});

    a1.add([](){return drive.drive_to_point(84, 36, .5, .5);});
    a1.add([](){return drive.turn_to_heading(270, .5);});

    a1.add([](){return drive.drive_to_point(84, 12, .5, .5);});
    a1.add([](){return drive.turn_to_heading(0, .5);});

    a1.add([](){return drive.drive_to_point(132, 12, .5, .5);});
    a1.add([](){return drive.turn_to_heading(90, .5);});

    a1.add([](){return drive.drive_to_point(132, 36, .5, .5);});
    a1.add([](){return drive.turn_to_heading(180, .5);});

    a1.add([](){return drive.drive_to_point(112, 36, .5, .5);});
    a1.add([](){return drive.turn_to_heading(90, .5);});

    a1.add([](){return drive.drive_to_point(112, 60, .5, .5);});
    a1.add([](){return drive.turn_to_heading(180, .5);});

    a1.add([](){return drive.drive_to_point(60, 60, .5, .5);});
    a1.add([](){return drive.turn_to_heading(90, .5);});

    a1.add([](){return drive.drive_to_point(60, 84, .5, .5);});
    a1.add([](){return drive.turn_to_heading(0, .5);});

    a1.add([](){return drive.drive_to_point(108, 84, .5, .5);});
    a1.add([](){return drive.turn_to_heading(90, .5);});

    a1.add([](){return drive.drive_to_point(108, 108, .5, .5);});
    a1.add([](){return drive.turn_to_heading(180, .5);});

    a1.add([](){return drive.drive_to_point(60, 108, .5, .5);});
    a1.add([](){return drive.turn_to_heading(90, .5);});

    a1.add([](){return drive.drive_to_point(60, 132, .5, .5);});
    a1.add([](){return drive.turn_to_heading(0, .5);});

    a1.add([](){return drive.drive_to_point(132, 132, .5, .5);});
    a1.add([](){return drive.turn_to_heading(270, .5);});

    a1.add([](){return drive.drive_to_point(132, 60, .5, .5);});

    #ifdef NEMO
    #ifdef AUTOMODE
      a1.run(true);
      main_controller.Screen.setCursor(0, 0);
      main_controller.Screen.print("Auto Time: %f", auto_t.time(timeUnits::sec));
      return;
    #endif
    #endif

  int line_crossings = 0;

  position_t final_pos = {
    .x = 132,
    .y = 66
  };

  timer comp_timer;
  comp_timer.reset();

  MazeGame::init_bounds_lines();

  // while(!drive.drive_to_point(12, 132, .5, .5)) { vexDelay(20); }


  // ========== LOOP ==========
  while(true)
  {
    // printf("running: %d\n", is_running);
    // fflush(stdout);


    // ========== DRIVING CONTROLS ==========

    drive.drive_arcade(.7 * main_controller.Axis3.position() / 100.0, .4 * main_controller.Axis1.position() / 100.0, 2);

    // printf("HUE: %f, VALUE: %ld, BRIGHT: %f\n", line_tracker.hue(), line_tracker.value(), line_tracker.brightness());
    // fflush(stdout);

    // ========== MANIPULATING CONTROLS ==========

    
    // ========== SECONDARY REMOTE ==========


    // ========== AUTOMATION ==========

    

    position_t robot_pos = odom.get_position();
    if(MazeGame::is_dq(robot_pos))
    {
      main_controller.Screen.clearScreen();
      main_controller.Screen.setCursor(0, 0);
      main_controller.Screen.print("No Shortcuts!\n");
      printf("Double Line!\n");
      main_controller.rumble("-");
      drive.stop();
      return;
    }

    if(MazeGame::is_single_penalty(robot_pos))
    {
      line_crossings++;
      main_controller.rumble(".");
      printf("Crossing line!\n");
    }

    // Test if it's at the final position, and end the match!
    if(OdometryBase::pos_diff(odom.get_position(), final_pos) < 12)
    {
      double time_sec = comp_timer.time(timeUnits::sec);
      main_controller.Screen.clearScreen();
      main_controller.Screen.setCursor(0, 0);
      main_controller.Screen.print("Time: %f", time_sec);
      main_controller.Screen.newLine();
      main_controller.Screen.print("Penalties: %d", line_crossings);
      main_controller.Screen.newLine();
      main_controller.Screen.print("Score: %f", time_sec + (line_crossings * 5));
      main_controller.rumble("-");
      drive.stop();
      return;
    }



    // double dist_norm = OdometryBase::pos_diff(odom.get_position(), test_pos, true);
    // double dist_axis = OdometryBase::pos_diff(odom.get_position(), test_pos, true, true);

    printf("X: %f  Y: %f  rot: %f\n", odom.get_position().x,odom.get_position().y, odom.get_position().rot);
    // fflush(stdout);
    // fflush(stderr);

    // Wait 20 milliseconds for control loops to calculate time correctly
    vexDelay(20); 
  }

  drive.stop();
}