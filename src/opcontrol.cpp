#include "main.h"

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */

void opcontrol() {
  bool tank = true;

  // clamp.extend();

  while (true) {
    int leftX = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X);
    int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
    int rightX = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
    int rightY = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
    
    // Toggle tank and arcade drive
    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_DOWN)) {
      tank = !tank;
    }

    if (tank == true) {
      chassis.tank(leftY, rightY);
      controller.set_text(1, 0, "TANK  ");
      controller.rumble(".");
    } else if (tank == false) {
      chassis.arcade(leftY, rightX);
      controller.set_text(1, 0, "ARCADE");
      controller.rumble("_");
    }
    
    if (
      controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B) &&
      controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_DOWN) &&
      controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_LEFT)
    ) {
      // Climb
    }

    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L1)) { 
      clamp.toggle();
    }
    
    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L2)) {
      if (ladyBrownPos == Start) {
        ladyBrownPos = Load;
      } else if (ladyBrownPos == Load) {
        ladyBrownPos = RideUp;
      } else if (ladyBrownPos == RideUp) {
        ladyBrownPos = Score;
      } else if (ladyBrownPos == Score) {
        ladyBrownPos = Start;
      }
    }

    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A)) {
      doinker.toggle();
    }
    
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
      // Intake
      intake.move(127);
    } else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
      // Outtake
      intake.move(-127);
      // intakeLift.extend();
    } else {
      // Brake
      intake.brake();
      // intakeLift.retract();
    }
    
    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_UP)) {
      intakeLift.toggle();
    }
    pros::delay(25);
  }
}