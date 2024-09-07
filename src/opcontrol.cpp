#include "lemlib/api.hpp"
#include "main.h"

#include "devices.h"
#include "pros/misc.h"

#include "intake.h"

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
  bool clampOn = HIGH;

  while (true) {
    /* * * Drive Control * * */
    int leftX = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X);
    int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
    int rightX = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
    int rightY = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);

    // Toggle tank and arcade drive
    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_LEFT)) {
      tank = !tank;
    }

    if (tank == true) {
      chassis.tank(leftY, rightY);
      controller.set_text(0, 0, "TANK  ");
      controller.rumble(".");
    } else if (tank == false) {
      chassis.arcade(leftY, rightX);
      controller.set_text(0, 0, "ARCADE");
      controller.rumble("_");
    }

    /* * * Clamp * * */
    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R1)) {
      clamp.toggle();
    }

    /* * * Intake * * */

    // Prints the intake angle to the brain
    pros::lcd::print(0, "Rotation Sensor: %d", rotationSensor.get_angle());

    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_UP)) {
      intakeMotor.move(-50);
    } else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)) {
      intakeMotor.move(50);
    } else {
      intakeMotor.brake();
    }

    pros::delay(25);
  }
}