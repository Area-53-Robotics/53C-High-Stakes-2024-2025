#include "main.h"
#include "lemlib/api.hpp"

void quickMove(float x, float y, int timeout, int wait) {
  chassis.moveToPoint(x, y, timeout);
  chassis.waitUntil(wait);
  chassis.cancelMotion();
  chassis.moveToPoint(x, y, timeout, {.maxSpeed = 100});
}

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
void red_ring() {
  // Move to mogo
  chassis.moveToPose(0, -26, 0, 5000, {.forwards = false});
  chassis.waitUntilDone();
  // clamp.extend();
  // Turn and move to ring stack
  chassis.turnToHeading(90, 1000);
  intake.move(127);
  chassis.moveToPose(16, -26, 90, 5000);

  // chassis.moveToPose(35, -3, 47, 5000);
}
void red_ring_ally() {
  
}
void red_ring_elim() {
  
}
void blue_ring() {
  
}
void blue_ring_ally() {
  
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
void red_mogo() {
  
}
void red_mogo_ally() {
  
}
void red_mogo_rush() {}
void blue_mogo() {
  
}
void blue_mogo_ally() {
  
}

void blue_mogo_rush() {
  
}
void nothing() {
  chassis.turnToHeading(90, 5000);
}
void skills() {

}

// sameer is gay
std::string auton = "red_ring";

void autonomous() {
  chassis.setPose(0, 0, 0);
  // Ring
  if (auton == "red_ring") {
    red_ring();
  } else if (auton == "red_ring_ally") {
    red_ring_ally();
  } else if (auton == "red_ring_elim") {
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