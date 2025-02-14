#include "ladybrown.h"
#include "devices.h"

void LadyBrownTask(void *param) {
  float startPos;
  float loadPos;
  float scorePos;

  float currentAngle;
  float targetAngle;
  float error;

  LadyBrownState state = Start;

  while (true) {

    switch (state) {
      case Start:
        targetAngle = startPos;
      case Load:
        targetAngle = loadPos;
      case Score:
        targetAngle = scorePos;
    }

    error = targetAngle - currentAngle;
    
    while (std::abs(error) > 0.1) {
      ladyBrown.move(60);
    }

    pros::delay(20);
  }
}