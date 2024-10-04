#include "devices.h"
#include "lemlib/api.hpp"
#include "main.h"

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
  /* Close Mobile Goal Auton: 1 Point */
  
  // Move to mobile goal
  leftMotors.move(-71);
  rightMotors.move(-75);
  pros::delay(450);
  leftMotors.brake();
  rightMotors.brake();
  // Clamp mobile goal
  pros::delay(700);
  clamp.extend();
  pros::delay(600);
  // Outtake ring
  intakeMotors.move(130);
  pros::delay(2000);
  intakeMotors.brake();
  // Release mobile goal
  pros::delay(500);
  clamp.retract();
}

