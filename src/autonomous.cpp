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
  /* AWP */

  chassis.setPose(0, 0, 0);
  clamp.extend();
  // Move to alliance stake and turn to it
  chassis.moveToPoint(0, -14, 1000, {.forwards = false});
  chassis.turnToHeading(90, 500);
  chassis.moveToPoint(-3.5, -15, 500, {.forwards = false});
  // Outtake preload onto alliance stake
  intakeMotors.move(127);
  pros::delay(1500);
  intakeMotors.brake();
  // Move away from wall
  chassis.moveToPoint(0, -16, 500);
  // Turn to mobile goal
  chassis.turnToHeading(236.5, 1000);
  clamp.retract();
  // Move to mobile goal
  chassis.moveToPoint(32, 2, 2000, {.forwards = false, .maxSpeed = 60});
  chassis.waitUntilDone();
  // Grab mobile goal
  clamp.extend();
  // Turn to individual ring stack
  chassis.turnToHeading(362, 1000);
  // Move to individual ring stack
  chassis.moveToPoint(34, 25, 1000);
  // Intake bottom ring
  intakeMotors.move(127);
  pros::delay(1000);
  // Return to mobile goal position
  chassis.moveToPoint(36, 5, 1000, {.forwards = false});
  // Arc to 2x2 ring stack
  chassis.moveToPose(51, 31, 370, 3000);
  // Touch ladder
  chassis.moveToPose(50, 13, 362, 3000, {.forwards = false});
  chassis.waitUntilDone();
  clamp.retract();

  /* Close Mobile Goal Auton: 1 Point

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

  */
}
