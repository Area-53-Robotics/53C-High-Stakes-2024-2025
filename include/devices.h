#include "lemlib/api.hpp"
#include "lemlib/chassis/chassis.hpp"
#include "lemlib/chassis/trackingWheel.hpp"
#include "main.h"
#include "pros/adi.hpp"

/* * * Controller * * */
inline pros::Controller controller(pros::E_CONTROLLER_MASTER);

/* * * Pneumatics * * */
inline pros::adi::Pneumatics clamp('A', false);
inline pros::adi::Pneumatics intake('B', false);
inline pros::adi::Pneumatics doinker('C', false);

/* * * Sensors * * */
inline pros::IMU imu(6);
inline pros::Rotation verticalRotation(-4);
inline lemlib::TrackingWheel
    verticalTrackingWheel(&verticalRotation, lemlib::Omniwheel::NEW_275, 1);
inline pros::Rotation horizontalRotation(-5);
inline lemlib::TrackingWheel
    horizontalTrackingWheel(&horizontalRotation, lemlib::Omniwheel::NEW_275, 1);

/* * * Motors * * */
inline pros::MotorGroup intakeMotors({-19, 20});

/* * * Drivetrain * * */
// Dead ports: 3, 6, 7, 12, 14, 18, 20,
inline pros::Motor frontLeftMotor(-1);
inline pros::Motor middleLeftMotor(-2);
inline pros::Motor backLeftMotor(-3);

inline pros::Motor frontRightMotor(8);
inline pros::Motor middleRightMotor(9);
inline pros::Motor backRightMotor(10);

inline pros::MotorGroup leftMotors({-1, -2, -3}, pros::MotorGearset::blue);
inline pros::MotorGroup rightMotors({8, 9, 10}, pros::MotorGearset::blue);

inline lemlib::Drivetrain drivetrain(&leftMotors,  // left motor group
                                     &rightMotors, // right motor group
                                     11.5,         // track width
                                     lemlib::Omniwheel::NEW_325, // wheel size
                                     450, // drivetrain rpm
                                     2    // horizontal drift
);

/* * * Sensors * * */
inline lemlib::OdomSensors
    sensors(&verticalTrackingWheel,   // vertical tracking wheel 1
            nullptr,                  // vertical tracking wheel 2
            &horizontalTrackingWheel, // horizontal tracking wheel 1
            nullptr,                  // horizontal tracking wheel 2
            &imu                      // inertial sensor
    );

/* * * Motion Controllers * * */
inline lemlib::ControllerSettings
    lateral_controller(10,  // proportional gain (kP) 10
                       0,   // integral gain (kI)
                       3,   // derivative gain (kD) 3
                       3,   // anti windup
                       1,   // small error range, in inches
                       100, // small error range timeout, in milliseconds
                       3,   // large error range, in inches
                       500, // large error range timeout, in milliseconds
                       20   // maximum acceleration (slew)
    );

inline lemlib::ControllerSettings
    angular_controller(2,  // proportional gain (kP) 2
                       0,  // integral gain (kI)
                       10, // derivative gain (kD) 10
                       0,  // anti windup
                       0,  // small error range, in degrees
                       0,  // small error range timeout, in milliseconds
                       0,  // large error range, in degrees
                       0,  // large error range timeout, in milliseconds
                       0   // maximum acceleration (slew)
    );
/* * * Drive Curve * * */
// input curve for throttle input during driver control
inline lemlib::ExpoDriveCurve
    throttle_curve(10,   // joystick deadband out of 127
                   10,   // minimum output where drivetrain will move out of 127
                   1.015 // expo curve gain
    );

// only used for arcade
// input curve for steer input during driver control
inline lemlib::ExpoDriveCurve
    steer_curve(10,  // joystick deadband out of 127
                10,  // minimum output where drivetrain will move out of 127
                1.03 // expo curve gain
    );

/* * * Chassis * * */
inline lemlib::Chassis chassis(drivetrain,         // drivetrain settings
                               lateral_controller, // lateral PID settings
                               angular_controller, // angular PID settings
                               sensors,            // odometry sensors
                               &throttle_curve, &steer_curve);
