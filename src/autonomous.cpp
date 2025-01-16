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

void ring_red() {
  clamp.retract();
  // Move to alliance stake
  chassis.moveToPoint(0, -12, 5000, {.forwards = false, .maxSpeed = 80});
  chassis.waitUntil(8);
  chassis.cancelMotion();
  // Turn to alliance stake
  chassis.turnToHeading(90, 500, {.maxSpeed = 50}); // maybe make slower
  chassis.moveToPoint(-6.5, -16, 5000, {.forwards = false, .maxSpeed = 80});
  chassis.waitUntilDone();
  // Outtake preload
  intakeMotors.move(-60);
  pros::delay(500);
  intakeMotors.brake();
  // Move back from alliance stake
  chassis.moveToPoint(0, -14, 800);
  // Move to mobile goal
  chassis.moveToPose(29.5, 2.3, -242, 3000,
                     {.forwards = false, .maxSpeed = 50});
  chassis.waitUntilDone();
  // Grab mobile goal
  clamp.extend();
  pros::delay(1000);
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
}
void ring_blue() {
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
}

/** RING (ally)
 * Scores preload on alliance stake
 * Moves to 1x2 stack and intakes the bottom one
 * RING (new) just doesn't have alliance stake
 */
void ring_red_new() {}
void ring_blue_new() {
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
  chassis.turnToPoint(-36, 28, 1000);
  // Move to ring stack
  chassis.moveToPoint(-36, 28, 5000, {.maxSpeed = 60});
  // Intake ring
  intakeMotors.move(127);
  // Turn to 2x2 ring stack
  chassis.turnToPoint(-45, 23, 1000);
  // Move to 2x2 ring stack (left side)
  chassis.moveToPoint(-45, 23, 5000, {.maxSpeed = 80});
  chassis.waitUntilDone();
  pros::delay(500);
  // Move back
  chassis.moveToPoint(-36, 28, 5000, {.forwards = false});
  // Move to 2x2 ring stack (right side)
  chassis.moveToPoint(-45, 33, 1000, {.maxSpeed = 80});
  chassis.waitUntilDone();
  pros::delay(1000);
  // Turn to ladder
  chassis.turnToPoint(-45, 8, 1000, {.forwards = false});
  // Move to ladder
  chassis.moveToPoint(-45, 8, 5000);
}
void ring_red_ally() {
  clamp.extend();
  // Move to alliance stake
  chassis.moveToPoint(0, -12, 5000, {.forwards = false, .maxSpeed = 80});
  chassis.waitUntil(8);
  chassis.cancelMotion();
  // Turn to alliance stake
  chassis.turnToHeading(90, 500, {.maxSpeed = 50}); // maybe make slower
  chassis.moveToPoint(-7.2, -16, 5000, {.forwards = false, .maxSpeed = 80});
  chassis.waitUntilDone();
  // Outtake preload
  intakeMotors.move(-60);
  pros::delay(500);
  intakeMotors.brake();
  // Move back from alliance stake
  chassis.moveToPoint(0, -14, 800);
  // Turn to mobile goal
  chassis.turnToPoint(30, 0, 5000, {.forwards = false});
  clamp.retract();
  // Move to mobile goal
  chassis.moveToPoint(30, 0, 5000, {.forwards = false});
  chassis.waitUntil(15);
  chassis.cancelMotion();
  chassis.moveToPoint(30, 0, 5000, {.forwards = false, .maxSpeed = 30});
  // Clamp mobile goal
  chassis.waitUntilDone();
  clamp.extend();
  // Turn to ring stack
  chassis.turnToPoint(36, 28, 1000);
  // Move to ring stack
  chassis.moveToPoint(36, 28, 5000, {.maxSpeed = 60});
  // Intake ring
  intakeMotors.move(127);
  // Turn to 2x2 ring stack
  chassis.turnToPoint(51, 34.5, 1000);
  // Move to 2x2 ring stack (left side)
  chassis.moveToPoint(51, 34.5, 5000, {.maxSpeed = 80});
  chassis.waitUntilDone();
  pros::delay(500);
  // Move back
  chassis.moveToPoint(36, 28, 5000, {.forwards = false});
  /*
  // Move to 2x2 ring stack (right side)
  chassis.moveToPoint(45, 33, 1000, {.maxSpeed = 80});
  chassis.waitUntilDone();
  pros::delay(1000);
  intakeMotors.brake();*/

  // Turn to ladder
  chassis.turnToPoint(46, -3.5, 1000, {.forwards = false});
  // Move to ladder
  chassis.moveToPose(40, -4, 364, 5000, {.forwards = false});
  chassis.waitUntilDone();
  intakeMotors.brake();
}
void ring_blue_ally() {
  pros::delay(1000);
  clamp.extend();
  // Move to alliance stake
  chassis.moveToPoint(0, -12, 5000, {.forwards = false, .maxSpeed = 80});
  chassis.waitUntil(8);
  chassis.cancelMotion();
  // Turn to alliance stake
  chassis.turnToHeading(-90, 500, {.maxSpeed = 50}); // maybe make slower
  chassis.moveToPoint(7.2, -16, 5000, {.forwards = false, .maxSpeed = 80});
  chassis.waitUntilDone();
  // Outtake preload
  intakeMotors.move(-60);
  pros::delay(500);
  intakeMotors.brake();
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
  pros::delay(500);
  // Turn to ring stack
  chassis.turnToPoint(-36, 28, 1000);
  // Move to ring stack
  chassis.moveToPoint(-36, 28, 5000, {.maxSpeed = 60});
  // Intake ring
  intakeMotors.move(127);
  // Turn to 2x2 ring stack
  chassis.turnToPoint(-45, 23, 1000);
  // Move to 2x2 ring stack (left side)
  chassis.moveToPoint(-45, 23, 5000, {.maxSpeed = 80});
  chassis.waitUntilDone();
  pros::delay(1000);
  // Move back
  chassis.moveToPoint(-36, 28, 5000, {.forwards = false});
  // Move to 2x2 ring stack (right side)
  chassis.moveToPoint(-44, 33, 1000, {.maxSpeed = 80});
  chassis.waitUntilDone();
  pros::delay(1500);
  // Turn to ladder
  chassis.turnToPoint(-46, -3.5, 1000, {.forwards = false});
  // Move to ladder
  chassis.moveToPose(-45, -3.5, -501, 5000, {.forwards = false});
}
void ring_red_ally_elim() {
  pros::delay(1000);
  clamp.extend();
  // Move to alliance stake
  chassis.moveToPoint(0, -12, 5000, {.forwards = false, .maxSpeed = 80});
  chassis.waitUntil(8);
  chassis.cancelMotion();
  // Turn to alliance stake
  chassis.turnToHeading(90, 500, {.maxSpeed = 50}); // maybe make slower
  chassis.moveToPoint(-7.2, -16, 5000, {.forwards = false, .maxSpeed = 80});
  chassis.waitUntilDone();
  // Outtake preload
  intakeMotors.move(-60);
  pros::delay(500);
  intakeMotors.brake();
  // Move back from alliance stake
  chassis.moveToPoint(0, -14, 800);
  // Turn to mobile goal
  chassis.turnToPoint(30, 0, 1000, {.forwards = false});
  clamp.retract();
  // Move to mobile goal
  chassis.moveToPoint(30, 0, 5000, {.forwards = false});
  chassis.waitUntil(15);
  chassis.cancelMotion();
  chassis.moveToPoint(30, 0, 5000, {.forwards = false, .maxSpeed = 30});
  // Clamp mobile goal
  chassis.waitUntilDone();
  clamp.extend();
  // Turn to ring stack
  chassis.turnToPoint(36, 28, 1000);
  // Move to ring stack
  chassis.moveToPoint(36, 28, 5000, {.maxSpeed = 60});
  // Intake ring
  intakeMotors.move(127);
  // Turn to 2x2 ring stack
  chassis.turnToPoint(51, 34.5, 1000);
  // Move to 2x2 ring stack (left side)
  chassis.moveToPoint(49, 34.5, 5000, {.maxSpeed = 80});
  chassis.waitUntilDone();
  pros::delay(500);
  // Move back
  chassis.moveToPoint(36, 28, 5000, {.forwards = false});
  chassis.waitUntilDone();
  intakeMotors.brake();
}

/** MOGO
 *
 */
void mogo_red() {
  // Start moving to mobile goal
  chassis.moveToPoint(4, -30, 1000, {.forwards = false});
  chassis.waitUntil(22);
  chassis.cancelMotion();
  intakeMotors.move(127);
  // In between point where it turns to and moves to mobile goal
  chassis.moveToPoint(8, -48, 5000, {.forwards = false, .maxSpeed = 50});
  chassis.waitUntilDone();
  // Clamp mogo
  clamp.extend();
  // Move to ring (1/2)
  chassis.moveToPoint(11, -8, 1000);
  chassis.waitUntil(8);
  // Drop mogo
  clamp.retract();
  // Move to ring (2/2)
  chassis.waitUntil(15);
  chassis.cancelMotion();
  chassis.moveToPose(11, -8, 0, 1000); //-17, -35, 104
  // Intake ring
  chassis.waitUntilDone();
  pros::delay(500);
  intakeMotors.brake();
  // Move to 2nd mogo
  chassis.moveToPose(32, -31, -54, 2000, {.forwards = false});
  chassis.waitUntilDone();
  intakeMotors.move(127);
  // Clamp 2nd mogo
  clamp.extend();
  /*
  pros::delay(500);
  chassis.moveToPoint(41, -31, 100, {.maxSpeed = 80});
  // Move to other ring
  chassis.moveToPose(17, -35, -104, 5000);
  chassis.waitUntilDone();
  pros::delay(500);
  intakeMotors.brake();
  chassis.moveToPose(41, -42, -77, 5000, {.forwards = false});*/
}
void mogo_blue() {
  // Start moving to mobile goal
  chassis.moveToPoint(-4, -30, 1000, {.forwards = false});
  chassis.waitUntil(22);
  chassis.cancelMotion();
  intakeMotors.move(127);
  // In between point where it turns to and moves to mobile goal
  chassis.moveToPoint(-10, -44, 5000, {.forwards = false, .maxSpeed = 50});
  chassis.waitUntilDone();
  // Clamp mogo
  clamp.extend();
  // Move to ring (1/2)
  chassis.moveToPoint(-12, -2, 1000);
  chassis.waitUntil(6);
  // Drop mogo
  clamp.retract();
  // Move to ring (2/2)
  chassis.waitUntil(15);
  chassis.cancelMotion();
  chassis.moveToPoint(-12, -2, 5000, {.maxSpeed = 20}); //-17, -35, 104
  // Intake ring
  chassis.waitUntilDone();
  intakeMotors.brake();
  // Move to 2nd mogo
  chassis.moveToPose(-33, -25, 50, 2000, {.forwards = false});
  chassis.waitUntilDone();
  intakeMotors.move(127);
  // Clamp 2nd mogo
  clamp.extend();
  pros::delay(500);
  chassis.moveToPoint(-41, -31, 100, {.maxSpeed = 80});
  // Move to other ring
  chassis.moveToPose(-17, -35, 104, 5000);
  chassis.waitUntilDone();
  pros::delay(500);
  intakeMotors.brake();
  chassis.moveToPose(-41, -42, 77, 1000, {.forwards = false});
}

/** SKILLS
 * Grabs one of the red side mobile goal
 * Turns to the three rings in an L shape
 * Intakes the first two in a row
 * Pushes the mogo into the corner and drops
 */

void skills_1() {
  // Move to mogo
  chassis.moveToPoint(0, -12, 5000, {.forwards = false});
  chassis.waitUntilDone();
  // Clamp mogo
  clamp.extend();
  pros::delay(500);
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
  // Back into corner
  chassis.turnToHeading(-143, 1000);
  chassis.moveToPoint(36, -6, 5000, {.forwards = false, .maxSpeed = 60});
  // Drop mogo
  chassis.waitUntilDone();
  clamp.retract();
  pros::delay(500);
  // Move to next mobile goal
  chassis.moveToPose(-46, -20, -636, 1000);

  /* * * DO ALL OF THE ABOVE AGAIN * * */
  chassis.setPose(0, -12, 90);

  clamp.extend();
  pros::delay(500);
  // Turn to first ring
  chassis.turnToPoint(0, -36, 1000);
  // Move to first ring
  chassis.moveToPoint(0, -36, 5000, {.maxSpeed = 60});
  intakeMotors.move(127);
  chassis.waitUntilDone();
  pros::delay(500);
  // Turn to second ring
  chassis.turnToPoint(-24, -36, 1000);
  // Move to second ring
  chassis.moveToPoint(-24, -36, 5000, {.maxSpeed = 60});
  chassis.waitUntilDone();
  pros::delay(500);
  // Turn to third ring
  chassis.turnToPoint(-24, -12, 1000);
  // Move to third ring and fourth ring (in one movement)
  chassis.moveToPoint(-24, 0, 5000, {.maxSpeed = 40});
  chassis.waitUntilDone();
  pros::delay(500);
  // Move back to fifth ring
  chassis.moveToPoint(-24, -36, 5000, {.forwards = false});
  // Move to fifth ring
  chassis.moveToPose(-32, -12, 0, 3000, {.maxSpeed = 60});
  chassis.waitUntilDone();
  intakeMotors.brake();
  // Back into corner
  chassis.turnToHeading(143, 1000);
  chassis.moveToPoint(-36, -6, 5000, {.forwards = false, .maxSpeed = 60});
  // Drop mogo
  chassis.waitUntilDone();
  clamp.retract();
  pros::delay(1000);
  intakeMotors.brake();
}

ASSET(skills_2_txt);

void skills_2() {
  // Score preload on alliance stake
  intakeMotors.move(-127);
  pros::delay(500);
  intakeMotors.brake();
  chassis.moveToPoint(0, 5, 3000);
  /* * * LEFT SIDE * * */
  // Grab mogo
  chassis.turnToPoint(-16.5, 14, 1000, {.forwards = false});
  chassis.moveToPoint(-16.5, 14, 3000, {.forwards = false, .maxSpeed = 30});
  chassis.waitUntilDone();
  clamp.extend();
  pros::delay(500);
  // Turn to ring
  chassis.turnToPoint(-28, 44, 1000);
  chassis.waitUntilDone();
  intakeMotors.move(127);
  // Move to first ring
  chassis.moveToPoint(-28, 44, 3000, {.maxSpeed = 60});
  // Move to second ring
  chassis.moveToPoint(-58, 59, 3000, {.maxSpeed = 60});
  // Turn to third ring
  chassis.turnToPoint(-46, 37, 1000);
  chassis.moveToPose(-43, 37, -180, 3000);
  // Move to fourth and fifth ring
  chassis.moveToPoint(-43, 7, 3000, {.maxSpeed = 40});
  chassis.waitUntilDone();
  // Move to sixth ring
  chassis.turnToPoint(-58, 13, 1000);
  chassis.moveToPoint(-58, 13, 1000);
  // Back up mogo to corner and drop
  chassis.moveToPose(-57, 4, 46, 3000, {.forwards = false});
  chassis.waitUntilDone();
  clamp.retract();
  pros::delay(1000);
  // Move away from corner
  chassis.moveToPoint(-58, 13, 1000);
  /* * * RIGHT SIDE * * */
  // Move to second mogo
  chassis.turnToPoint(16.5, 14, 1000, {.forwards = false});
  chassis.moveToPoint(16.5, 14, 3000, {.forwards = false, .maxSpeed = 20});
  chassis.waitUntilDone();
  clamp.extend();
  pros::delay(500);
  // Turn to ring
  chassis.turnToPoint(28, 44, 1000);
  chassis.waitUntilDone();
  intakeMotors.move(127);
  // Move to first ring
  chassis.moveToPoint(28, 44, 3000, {.maxSpeed = 60});
  // Move to second ring
  chassis.moveToPoint(58, 59, 3000, {.maxSpeed = 60});
  // Turn to third ring
  chassis.turnToPoint(48, 37, 1000);
  chassis.moveToPose(48, 37, -180, 3000);
  // Move to fourth and fifth ring
  chassis.moveToPoint(52, 7, 3000, {.maxSpeed = 40});
  chassis.waitUntilDone();
  // Move to sixth ring
  chassis.turnToPoint(52, 13, 1000);
  chassis.moveToPoint(52, 13, 1000);
  // Back up mogo to corner and drop
  chassis.moveToPose(57, 4, -46, 3000, {.forwards = false});
  chassis.waitUntilDone();
  clamp.retract();
  pros::delay(1000);
  // Move away from corner
  chassis.moveToPoint(58, 13, 1000);
}

/** TESTING
 * Move in a 24x24 inch square
 */
void testing() {
  
}

// sameer is gay
std::string auton = "skills";

void autonomous() {
  chassis.setPose(0, 0, 0);
  if (auton == "red-ring") {
    ring_red_ally();
  } else if (auton == "red-mogo") {
    mogo_red();
  } else if (auton == "red-elim") {
    ring_red_ally_elim();
  } else if (auton == "blue-ring") {
    ring_blue_ally();
  } else if (auton == "blue-mogo") {
    mogo_blue();
  } else if (auton == "blue-elim") {

  } else if (auton == "skills") {
    skills_2();
  }
}
