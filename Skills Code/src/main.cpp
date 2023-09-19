/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// FrontLeft            motor         15              
// FrontRight           motor         19              
// MiddleLeft           motor         13              
// MiddleRight          motor         14              
// BackLeft             motor         20              
// BackRight            motor         11              
// Inertial21           inertial      21              
// Intake               motor         17              
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}
// Function that moves and turns robot

void moveDistance(double inches){
  double omniCircumfrence = 3.1415 * 2 * 3.5;
  int greenCartridgeTicks = 900;
  double gearRatio = 0.6;
  float conversion = greenCartridgeTicks/omniCircumfrence * gearRatio;

  FrontLeft.spinFor(forward, inches * conversion, degrees);
  FrontRight.spinFor(forward, inches * conversion, degrees);
  MiddleLeft.spinFor(forward, inches * conversion, degrees);
  MiddleRight.spinFor(forward, inches * conversion, degrees);
  BackLeft.spinFor(forward, inches * conversion, degrees);
  BackRight.spinFor(forward, inches * conversion, degrees);
}

void turnDegrees(double turnDegrees){
  double omniCircumfrence = 3.1415 * 2 * 3.5;
  int greenCartridgeTicks = 900;
  double gearRatio = 0.6;
  float conversion = greenCartridgeTicks/omniCircumfrence * gearRatio;
  double degreesFraction=turnDegrees/360;

  FrontLeft.spinFor(fwd, degreesFraction*conversion, degrees);
  FrontRight.spinFor(forward, -1 * degreesFraction * conversion, degrees);
  MiddleLeft.spinFor(forward, degreesFraction * conversion, degrees);
  MiddleRight.spinFor(forward, -1 * degreesFraction * conversion, degrees);
  BackLeft.spinFor(forward, degreesFraction * conversion, degrees);
  BackRight.spinFor(forward, -1 * degreesFraction * conversion, degrees);
}
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void){
  //
}

void place1(void) {
  //intake and score preload triball and launch matchload triball over the goal
  //most left position; blue side; score a preloaded triball 
  Intake.spinFor(forward, 720, degrees);
  moveDistance(48);
  turnDegrees(-90);
  moveDistance(10);
  Intake.spinFor(reverse, 720, degrees);
  moveDistance(-10);
  turnDegrees(180);
  moveDistance(-10);
  moveDistance(10);
  turnDegrees(90);
  moveDistance(55);
  turnDegrees(-90);
  moveDistance(36);
  turnDegrees(-90);
  moveDistance(12);
  moveDistance(-8);
  turnDegrees(-90);
  moveDistance(36);
  turnDegrees(90);


  Intake.spinFor(reverse, 720, degrees);
  moveDistance(45);
  turnDegrees(90);
  moveDistance(12);
  Intake.spinFor(forward, 720, degrees);
  moveDistance(-10);
  turnDegrees(180);
  moveDistance(-12);
  moveDistance(10);
  while (true){
    Catapult.spin(forward);
  }
}



/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
