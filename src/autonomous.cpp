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

/** RING (old)
 * Grabs the mobile goal
 * Turns to the 1x2 ring stack and intakes the bottom one
 * Intakes preload ring
 * Turns to the 2x2 ring stack and intakes both rings
 * Moves to the ladder and touches the side
 */

void qual_ring_red() {
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
  chassis.turnToPoint(49, 26, 1000);
  // Move to first bottom ring
  chassis.moveToPoint(49, 26, 3000, {.maxSpeed = 50});
  chassis.waitUntilDone();
  pros::delay(2000);
  // Back away from first bottom ring
  chassis.moveToPoint(38, 33, 1000, {.forwards = false});
  // Turn to second bottom ring
  chassis.turnToHeading(79, 1000);
  // Move to second bottom ring
  chassis.moveToPoint(47, 36, 2000, {.maxSpeed = 50});
  chassis.waitUntilDone();
  // Turn to ladder
  chassis.turnToHeading(180, 1000);
  // Touch ladder
  chassis.moveToPoint(47, 8, 3000, {.maxSpeed = 60});
  chassis.turnToHeading(150, 1000);
  chassis.waitUntilDone();
  clamp.retract();
}
void qual_ring_blue() {
  // Move to mobile goal
  chassis.moveToPose(-25, 7, 122, 3000, {.forwards = false, .maxSpeed = 80});
  chassis.waitUntilDone();
  // Grab mobile goal
  pros::delay(500);
  clamp.extend();
  pros::delay(500);
  // Turn to individual ring stack
  chassis.turnToHeading(-10, 1000, {.maxSpeed = 80});
  // Move to individual ring stack
  chassis.moveToPoint(-34, 26, 1000);
  // Intake bottom ring
  intakeMotors.move(127);
  pros::delay(2500);
  intakeMotors.brake();
  // Move to first bottom ring
  chassis.moveToPose(-47, 27, -90, 3000, {.maxSpeed = 50});
  pros::delay(1500);
  intakeMotors.move(127);
  // Move to second bottom ring
  chassis.moveToPoint(-42, 27, 1000, {.forwards = false});
  chassis.moveToPose(-50, 40, -90, 5000);
  chassis.waitUntilDone();
  intakeMotors.brake();
  // Touch ladder
  chassis.moveToPose(-46, 9, 16, 5000, {.forwards = false});
  chassis.waitUntilDone();
  // Let go of mogo
  clamp.retract();
}
void elim_ring_red() {
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
  chassis.turnToPoint(49, 26, 1000);
  // Move to first bottom ring
  chassis.moveToPoint(49, 26, 3000, {.maxSpeed = 50});
  chassis.waitUntilDone();
  pros::delay(2000);
  // Back away from first bottom ring
  chassis.moveToPoint(38, 33, 1000, {.forwards = false});
  // Turn to second bottom ring
  chassis.turnToHeading(79, 1000);
  // Move to second bottom ring
  chassis.moveToPoint(47, 36, 2000, {.maxSpeed = 50});
  chassis.waitUntilDone();
}
void elim_ring_blue() {}

/** RING (new)
 * Scores preload on alliance stake
 * Moves to 1x2 stack and intakes the bottom one
 */
void qual_ring_red_ally() {}
void qual_ring_blue_ally() {
  clamp.extend();
  // Move to alliance stake
  chassis.moveToPoint(0, -10, 5000, {.forwards = false});
  chassis.waitUntil(8);
  chassis.cancelMotion();
  // Turn to alliance stake
  chassis.turnToHeading(-90, 500); // maybe make slower
  chassis.moveToPoint(7.7, -16, 5000, {.forwards = false, .maxSpeed = 80});
  // Move back from alliance stake
  chassis.moveToPoint(0, -14, 800);
  // Turn to mobile goal
  chassis.turnToPoint(-27, 2.6, 500, {.forwards = false});
  clamp.retract();
  // Move to mobile goal
  chassis.moveToPoint(-27, 2.6, 5000, {.forwards = false});
  chassis.waitUntil(15);
  chassis.cancelMotion();
  chassis.moveToPoint(-27, 2.6, 5000, {.forwards = false, .maxSpeed = 30});
  // Clamp mobile goal
  chassis.waitUntilDone();
  clamp.extend();
  // Turn to ring stack
  chassis.turnToPoint(-34, 28, 1000);
  chassis.moveToPoint(-34, 28, 5000);
  intakeMotors.move(127);
  pros::delay(1000);
  intakeMotors.brake();
}
void elim_mogo_red() {}
void elim_mogo_blue() {
  // Move to mobile goal
  chassis.moveToPose(-25, 7, 122, 3000, {.forwards = false, .maxSpeed = 100});
  chassis.waitUntilDone();
  // Grab mobile goal
  pros::delay(500);
  clamp.extend();
  pros::delay(500);
  // Turn to individual ring stack
  chassis.turnToHeading(-10, 1000, {.maxSpeed = 80});
  // Move to individual ring stack
  chassis.moveToPoint(-34, 26, 1000);
  // Intake bottom ring
  intakeMotors.move(127);
  pros::delay(2500);
  intakeMotors.brake();
  // Move to first bottom ring
  chassis.moveToPose(-47, 27, -90, 3000, {.maxSpeed = 50});
  pros::delay(1500);
  intakeMotors.move(127);
  // Move to second bottom ring
  chassis.moveToPoint(-42, 27, 1000, {.forwards = false});
  chassis.moveToPose(-50, 40, -90, 5000);
  chassis.waitUntilDone();
  intakeMotors.brake();
  // Let go of mogo
  clamp.retract();
}

/** MOGO
 *
 */
void qual_mogo_red() {
  // Move to mogo
  chassis.turnToHeading(90, 1000);
  chassis.moveToPose(-25, 8, 90, 3000, {.forwards = false});
  chassis.waitUntilDone();
  pros::delay(1000);
  // Clamp mogo
  clamp.extend();
  pros::delay(500);
  // Score preload ring
  intakeMotors.move(127);
  pros::delay(500);
  intakeMotors.brake();
  // Move to ring stack
  chassis.moveToPose(-34, 28, 10, 5000);
  chassis.waitUntilDone();
  // Intake and score ring
  intakeMotors.move(127);
  pros::delay(2000);
  intakeMotors.brake();
}
void qual_mogo_blue() {}

/** SKILLS
 * Grabs one of the red side mobile goal
 * Turns to the three rings in an L shape
 * Intakes the first two in a row
 * Pushes the mogo into the corner and drops
 */

void skills_left() {
  // Move to mogo
  chassis.moveToPoint(0, -12, 5000, {.forwards = false});
  chassis.waitUntilDone();
  // Clamp mogo
  clamp.extend();
  // Turn to first ring
  chassis.turnToPoint(0, -36, 1000);
  // Move to first ring
  chassis.moveToPoint(0, -36, 5000, {.maxSpeed = 60});
  intakeMotors.move(127);
  chassis.waitUntilDone();
  pros::delay(500);
  // Turn to second ring
  chassis.turnToPoint(24, -36, 1000);
  // Move to second ring
  chassis.moveToPoint(24, -36, 5000, {.maxSpeed = 60});
  chassis.waitUntilDone();
  pros::delay(500);
  // Turn to third ring
  chassis.turnToPoint(24, -12, 1000);
  // Move to third ring and fourth ring (in one movement)
  chassis.moveToPoint(24, 0, 5000, {.maxSpeed = 40});
  chassis.waitUntilDone();
  pros::delay(500);
  // Move back to fifth ring
  chassis.moveToPoint(24, -36, 5000, {.forwards = false});
  // Move to fifth ring
  chassis.moveToPose(32, -12, 0, 3000, {.maxSpeed = 60});
  chassis.waitUntilDone();
  intakeMotors.brake();
}
void skills_right() {
  // Move to mogo
  chassis.moveToPoint(0, -12, 1000, {.forwards = false});
  chassis.waitUntilDone();
  // Clamp mogo
  clamp.extend();
}

/** TESTING
 * Move in a 24x24 inch square
 */
void testing() {
  chassis.moveToPoint(0, 24, 5000);
  chassis.turnToHeading(90, 5000);
  chassis.moveToPoint(24, 24, 5000);
  chassis.turnToHeading(180, 5000);
  chassis.moveToPoint(24, 0, 5000);
  chassis.turnToHeading(270, 5000);
  chassis.moveToPoint(0, 0, 5000);
  chassis.turnToHeading(0, 5000);
}

// sameer is gay

void autonomous() {
  chassis.setPose(0, 0, 0);
  skills_left();
}
