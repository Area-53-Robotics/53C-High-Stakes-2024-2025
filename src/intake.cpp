#include "intake.h"
#include "devices.h"

float targetAngle;
float currentAngle;
float error;

const float KP = 0.5;
// const float KI = 0.0;
// const float KD = 0.0;
// We don't need to use integral or derivative to test the arm
// but we may use them in the future, so they are reserved here

enum class Intake { FLOOR, STAKE };

void liftIntake(Intake state) {
  while (error >= 1) {
    switch (state) {
    case Intake::FLOOR:
      targetAngle = 27000;
    case Intake::STAKE:
      targetAngle = 15000;
    }
    error = targetAngle - currentAngle;
    intakeMotor.move(error * KP);
  }
}