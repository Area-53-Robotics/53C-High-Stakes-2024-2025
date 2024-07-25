#include "main.h"
#include "lemlib/api.hpp"

/* * * Controller * * */
inline pros::Controller controller(pros::E_CONTROLLER_MASTER);

/* * * Drivetrain * * */
inline pros::MotorGroup leftMotors({1, 2, 3}, pros::MotorGearset::blue);
inline pros::MotorGroup rightMotors({-4, -5, -6}, pros::MotorGearset::blue);

/* * * Sensors * * */

/* * * Motion Controllers * * */

/* * * Drive Curve * * */