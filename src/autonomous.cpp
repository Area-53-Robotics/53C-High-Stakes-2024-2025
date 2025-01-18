#include "devices.h"
#include "lemlib/api.hpp"
#include "main.h"

/** RING (AWP)
 * Scores preload on mobile goal
 * Intakes 1x1 stack
 * Intakes 2x2 stack
 * Touches ladder
 ** ALLY (AWP)
 * Scores preload on alliance stake
 * Intakes 1x1 stack
 * Intakes 2x2 stack
 * Touches ladder
 ** ELIM
 * ALLY but no ladder
 */
void red_ring() {}
void red_ring_ally() {
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
void red_ring_elim() {
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
void blue_ring() {
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
void blue_ring_ally() {
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
void blue_ring_elim() {}

/** MOGO
 * Scores preload on mogo
 * Intakes 1x1 stack
 * (red) gets other goal, unfinished
 ** ALLY (AWP)
 * Scores preload on alliance stake
 * Intakes 1x1 stack
 * Intakes corner stack
 * Touches ladder
 ** RUSH
 * Grabs neutral mogo first
 */
// GETS OTHER GOAL BUT DOES NOTHING (commented out rn)
void red_mogo() {
  // Turn to mobile goal
  chassis.turnToPoint(-24.5, 7, 500, {.forwards = false});
  clamp.retract();
  // Move to mobile goal
  chassis.moveToPoint(-24.5, 7, 5000, {.forwards = false});
  chassis.waitUntil(15);
  chassis.cancelMotion();
  chassis.moveToPoint(-24.5, 7, 5000, {.forwards = false, .maxSpeed = 30});
  // Clamp mobile goal
  chassis.waitUntilDone();
  clamp.extend();
  pros::delay(500);
  // Turn to ring stack
  chassis.turnToPoint(-30, 35, 1000);
  // Move to ring stack
  chassis.moveToPoint(-30, 35, 5000, {.maxSpeed = 60});
  // Intake ring
  intakeMotors.move(127);
  pros::delay(3000);
  intakeMotors.brake();
  /*
  // Turn to other mobile goal
  chassis.moveToPoint(-47.5, 35, 5000, {.forwards = false});
  chassis.waitUntilDone();
  clamp.extend();
  */
}
void red_mogo_ally() {
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
  pros::delay(1000);
  intakeMotors.brake();
  // Move to corner ring
  chassis.moveToPoint(-7.9, 35.8, 3000);
  chassis.turnToPoint(4, 45, 1000);
  intakeMotors.move(127);
  chassis.moveToPoint(4, 45, 3000);
  // Intake corner ring
  chassis.tank(80, 80);
  pros::delay(3000);
  chassis.tank(0, 0);
  intakeMotors.brake();
  // Move to ladder
  chassis.moveToPose(-42.5, 9.5, 45, 5000, {.forwards = false});
}
void red_mogo_rush() {}
void blue_mogo() {
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
  pros::delay(3000);
  intakeMotors.brake();
}
void blue_mogo_ally() {
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
  pros::delay(1000);
  intakeMotors.brake();
  // Move to corner ring
  chassis.moveToPoint(9.336, 35, 5000);
  chassis.turnToPoint(0, 44.8, 1000);
  intakeMotors.move(127);
  chassis.moveToPoint(0, 44.8, 5000);
  // Intake corner ring
  chassis.tank(80, 80);
  pros::delay(3000);
  chassis.tank(0, 0);
  intakeMotors.brake();
  // Move to ladder
  chassis.moveToPose(46, 7, 323.9, 5000, {.forwards = false});
}
// UNFINISHED
void blue_mogo_rush() {
  // Start moving to mobile goal
  chassis.moveToPoint(0, -32, 3000, {.forwards = false});
  chassis.moveToPoint(-6, -40, 3000, {.forwards = false});
  chassis.moveToPoint(-8.7, -44.6, 3000, {.forwards = false, .maxSpeed = 30});
  // In between point where it turns to and moves to mobile goal
  chassis.waitUntilDone();
  intakeMotors.move(127);
  // Clamp mogo
  clamp.extend();
  /*
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
  */
}

/** SKILLS
 * Starts on left red side
 * Scores preload on alliance stake
 * Grabs closest mogo and scores 6 rings
 * Pushes mogo in corner
 * Moves to other side and repeats
 ** NOTHING
 * Does nothing
 */
void skills() {
  // Score preload on alliance stake
  intakeMotors.move(-127);
  pros::delay(500);
  intakeMotors.brake();
  chassis.moveToPoint(0, 5, 3000);
  /* * * LEFT SIDE * * */
  // Grab mogo
  chassis.turnToPoint(-16.5, 14, 1000, {.forwards = false});
  chassis.moveToPoint(-16.5, 14, 3000, {.forwards = false, .maxSpeed = 40});
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
  chassis.moveToPoint(16.5, 14, 3000, {.forwards = false, .maxSpeed = 40});
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
void nothing() {}

// sameer is gay
std::string auton = "red_ring_ally";

void autonomous() {
  chassis.setPose(0, 0, 0);
  // Ring
  if (auton == "red_ring") {
    red_ring();
  } else if (auton == "red_ring_ally") {
    red_ring_ally();
  } else if (auton == "red_elim") {
    red_ring_elim();
  } else if (auton == "blue_ring") {
    blue_ring();
  } else if (auton == "blue_ring_ally") {
    blue_ring_ally();
  } else if (auton == "blue_ring_elim") {
    blue_ring_elim();
  }
  // Mogo
  else if (auton == "red_mogo") {
    red_mogo();
  } else if (auton == "red_mogo_ally") {
    red_mogo_ally();
  } else if (auton == "red_mogo_rush") {
    red_mogo_rush();
  } else if (auton == "blue_mogo") {
    blue_mogo();
  } else if (auton == "blue_mogo_ally") {
    blue_mogo_ally();
  } else if (auton == "blue_mogo_rush") {
    blue_mogo_rush();
  } 
  // Misc.
  else if (auton == "skills") {
    skills();
  } else if (auton == "nothing") {
    nothing();
  }
}
