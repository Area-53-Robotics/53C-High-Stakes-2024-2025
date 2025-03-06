#include "ladybrown.h"
#include "devices.h"

LadyBrownState ladyBrownPos = Start;

void setLadyBrown(LadyBrownState state) {
  ladyBrownPos = state;
}

void LadyBrownTask(void *param) {
  float startPos = 217.26;
  float loadPos = 205.09;
  float rideUpPos = 94;
  float scorePos = 87;
  
  float autonPos = 180;
  float testPos = 120;

  float currentAngle;
  float targetAngle;

  float error;
  float kP = 1.6;
  float power;

  while (true) {
    // Set initial position
    switch (ladyBrownPos) {
      case Start:
        targetAngle = startPos;
        break;
      case Load:
        targetAngle = loadPos;
        break;
      case RideUp:
        targetAngle = rideUpPos;
        break;
      case Score:
        targetAngle = scorePos;
        break;
      case Auton:
        targetAngle = autonPos;
        break;
      case Test:
        targetAngle = testPos;
        break;
    }
    
    currentAngle = rotationSensor.get_angle() / 100.00;

    error = targetAngle - currentAngle;
    power = error * kP;
    
    while (std::abs(error) > 0.5) {
      // Set continuous position
      switch (ladyBrownPos) {
        case Start:
          targetAngle = startPos;
          break;
        case Load:
          targetAngle = loadPos;
          break;
        case RideUp:
          targetAngle = rideUpPos;
          break;
        case Score:
          targetAngle = scorePos;
          break;
        case Auton:
          targetAngle = autonPos;
          break;
        case Test:
          targetAngle = testPos;
          break;
      }
      
      currentAngle = rotationSensor.get_angle() / 100.00;
      
      error = targetAngle - currentAngle;
      power = error * kP;

      ladyBrown.move(power);
      pros::Task::delay(20);
    }
    
    ladyBrown.brake();
    pros::Task::delay(20);
    
  }
}