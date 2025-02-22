#include "main.h"
#include "lemlib/api.hpp"

/**
 * Updates the coordinates of the robot and prints to the controller screen.
 */
void updateCoordinates() {
  controller.print(0, 0, "X: %f", std::round(chassis.getPose().x * 100) / 100);
  controller.print(0, 1, "Y: %f", std::round(chassis.getPose().y * 100) / 100);
  controller.print(0, 2, "Theta: %f", std::round(chassis.getPose().theta * 100) / 100);
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
  // Initialize
  pros::lcd::initialize();
  chassis.calibrate();

  // Lady Brown
  ladyBrown.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  pros::Task lady_brown(LadyBrownTask);

  // Coordinates
  pros::Task screen_task([&]() {
    while (true) {
      // updateCoordinates();
      pros::lcd::print(0, "X: %f", chassis.getPose().x);
      pros::lcd::print(1, "Y: %f", chassis.getPose().y);
      pros::lcd::print(2, "Theta: %f", chassis.getPose().theta);
      pros::delay(20);
    }
  });
}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

// sameer is gay