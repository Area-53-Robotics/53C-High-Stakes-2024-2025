#include "main.h"
#include "lemlib/api.hpp"

#include "pros/misc.h"
#include "devices.h"

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

	while (true) {
        int leftX = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X);
        int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int rightX = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
        int rightY = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
        
        if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_DOWN)) {
            tank = !tank;
        }

        if (tank == true) {
            chassis.tank(leftY, rightY);
            controller.set_text(0, 0, "TANK");
            controller.rumble(".");
        }
        if (tank == false) {
            chassis.arcade(leftY, rightX);
            controller.set_text(0, 0, "ARCADE");
            controller.rumble("_");
        }

        pros::delay(25);   
    }
}