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

std::string auton = "awp";

void autonomous() {
  if (auton == "testing") {
    chassis.setPose(0, 0, 0);
    clamp.retract();
  } else if (auton == "awp_alliance") {
    chassis.setPose(0, 0, 0);
    clamp.extend();
    // Move to alliance stake and turn to it
    chassis.moveToPoint(0, -14, 1000, {.forwards = false});
    chassis.turnToHeading(90, 500);
    chassis.moveToPoint(-3.5, -15, 500, {.forwards = false});
    // Outtake preload onto alliance stake
    intakeMotors.move(127);
    pros::delay(1000);
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
    pros::delay(1500);
    // Turn to 2x2 ring stack
    chassis.turnToPoint(49, 25, 1000);
    // Move to 2x2 ring stack
    chassis.moveToPoint(49, 25, 3000, {.maxSpeed = 60});
    pros::delay(1000);
    // Touch ladder
    chassis.turnToHeading(180, 1000);
    chassis.moveToPoint(50, 8, 3000);
    chassis.waitUntilDone();
    clamp.retract();
  } else if (auton == "awp") {
    chassis.setPose(0, 0, 0);
    // Move to mobile goal
    chassis.moveToPose(29.5, 5, -120, 3000, {.forwards = false, .maxSpeed = 60});
    chassis.waitUntilDone();
    // Grab mobile goal
    clamp.extend();
    // Turn to individual ring stack
    chassis.turnToHeading(362, 1000);
    // Move to individual ring stack
    chassis.moveToPoint(34, 25, 1000);
    // Intake bottom ring
    intakeMotors.move(127);
    pros::delay(2000);
    // Turn to 2x2 ring stack
    chassis.turnToPoint(48, 25, 1000);
    // Move to first bottom ring
    chassis.moveToPoint(48, 25, 3000, {.maxSpeed = 50});
    pros::delay(1500);
    // Back away from first bottom ring
    chassis.moveToPoint(38, 33, 1000, {.forwards = false});
    // Turn to second bottom ring
    chassis.turnToPoint(48, 38, 1000);
    // Move to second bottom ring
    chassis.moveToPoint(48, 38, 2000, {.maxSpeed = 50});
    // Turn to ladder
    chassis.turnToHeading(180, 1000);
    // Touch ladder
    chassis.moveToPoint(47, 8, 3000, {.maxSpeed = 60});
    chassis.turnToHeading(150, 1000);
    chassis.waitUntilDone();
    clamp.retract();
  } else if (auton == "mogo_grab") {
    // Move to mogo
    chassis.moveToPoint(2, -30, 1000, {.forwards = false});
    chassis.moveToPose(12, -45.5, -12, 3000, {.forwards = false, .maxSpeed = 50});
    chassis.waitUntilDone();
    // Grab mogo
    clamp.extend();
    pros::delay(500);
    // Back up and score preload on mogo
    chassis.moveToPoint(12, -43, 1000);
    pros::delay(500);
    intakeMotors.move(127);
    pros::delay(1000);
    intakeMotors.brake();
    // Release mogo
    pros::delay(500);
    clamp.retract();
    pros::delay(500);
    // Move to other mogo
    chassis.moveToPose(35, -33, -134, 2000, {.forwards = false, .maxSpeed = 50});
    // Grab other mogo
    chassis.waitUntilDone();
    clamp.extend();
    pros::delay(500);
    intakeMotors.move(127);
    // Turn to rings
    chassis.turnToHeading(75, 1000);
    // Move to rings
    chassis.moveToPoint(22, -28, 1000);
    pros::delay(500);
    // Move to ring stack
    chassis.moveToPose(0.3, 8, -18, 2000);
  }
}
