#include "main.h"

#include "pros/misc.h"

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
  int maxNelkin = 127;

  while (true) {
    /* * * Drive Control * * */
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
      controller.set_text(0, 0, "TANK  ");
      controller.rumble(".");
    } else if (tank == false) {
      chassis.arcade(leftY, rightX);
      controller.set_text(0, 0, "ARCADE");
      controller.rumble("_");
    }

    /* * * Clamp * * */
    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L1)) {
      clamp.toggle();
    }

    /* * * Intake * * */
    
    // Prints the intake angle to the brain
    pros::lcd::print(0, "Rotation Sensor: %d", rotationSensor.get_angle());

    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
      intakeMotors.move(115);
    } else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
      intakeMotors.move(-115);
    } else {
      intakeMotors.brake();
    }   

    /*** Test ***/
    /*

    The purpose of this test is to identify problems with our intake and determine the effectiveness of our ring scoring when clamping a mobile goal. 

    0 - *127*
    1 - *100*    
    2 - *127* We made the wattage higher to make the rings move faster but the rings were still stuck, even when it was only one wring.
    3 - *120* The intake spun faster leading to less grip at Row 3 as kinetic friction is less than stiatic friction. 
              Our ring was unable to push the presure hood up which is required to move forward.
    4 - *115* The intake surface is bending away from the ring, reducing the friction and making it get stuck again, even with lower power.
              Sometimes the rings get stuck diagonally on the barb. 
              We are adding some spacers on the edge of the hood to push the rings down when the rubber bands pull it.
    5 - *115* We had inconsistent results; sometimes the rings would slide onto the mobile goal while others got stuck on the barb or in Row 3.
              We cut a curved chunk out of the intake ramp with the same length as the radius of the ring.
              We believe the 
    */

    pros::delay(25);
  }
}