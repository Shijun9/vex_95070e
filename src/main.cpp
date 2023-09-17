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
// FrontLeft            motor         19              
// FrontRight           motor         15              
// MiddleLeft           motor         13              
// MiddleRight          motor         14              
// BackRight            motor         11              
// BackLeft             motor         18              
// Controller1          controller                    
// Inertial21           inertial      21              
// Intake               motor         20              
// Catapult             motor         16              
// WingLeft             digital_out   A               
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
  FrontLeft.setVelocity(100, percent);
  MiddleLeft.setVelocity(100, percent);
  BackLeft.setVelocity(100, percent);
  FrontRight.setVelocity(100, percent);
  MiddleRight.setVelocity(100, percent);
  BackRight.setVelocity(100, percent);


  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
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
/*
void drivePID (double targetInches, double Kp, double Ki, double Kd) {
  double error = targetInches;
  double integral = 0;
  double lastError = error;

  while (true) {
    double measuredInches = 4 * 3.1415 * ((FrontLeft.position(degrees) + FrontRight.position(degrees) + MiddleLeft.position(degrees) + MiddleRight.position(degrees) + BackLeft.position(degrees) + BackRight.position(degrees))/6)/900;
    error = targetInches - measuredInches;
    integral += error;

    if (fabs(error) > 3){
      integral = 0;
    }

    float velocity = error * Kp + integral * Ki + (error - lastError) * Kd;

    FrontLeft.setVelocity(velocity, percent);
    FrontRight.setVelocity(velocity, percent);
    MiddleLeft.setVelocity(velocity, percent);
    MiddleRight.setVelocity(velocity, percent);
    BackLeft.setVelocity(velocity, percent);
    BackRight.setVelocity(velocity, percent);

    if (targetInches > 0) {
      FrontLeft.spin(forward);
      FrontRight.spin(forward);
      MiddleLeft.spin(forward);
      MiddleRight.spin(forward);
      BackLeft.spin(forward);
      BackRight.spin(forward);
    }
    else{
      FrontLeft.spin(reverse);
      FrontRight.spin(reverse);
      MiddleLeft.spin(reverse);
      MiddleRight.spin(reverse);
      BackLeft.spin(reverse);
      BackRight.spin(reverse); 
    }

    lastError = error;
  }
}

void turnPID (double targetDegrees, double Kp, double Ki, double Kd){
  double error = targetDegrees;
  double integral = 0;
  double lastError = error;

  Inertial.calibrate();

  while (fabs(error) > 1){
    error = targetDegrees - Inertial.heading(degrees);
    integral += error;

    if (fabs(error) > 300) {
      integral = 0;
    }

    FrontLeft.setVelocity(error * Kp + integral * Ki + (lastError - error) * Kd, percent);
    MiddleLeft.setVelocity(error * Kp + integral * Ki + (lastError - error) * Kd, percent);
    BackLeft.setVelocity(error * Kp + integral * Ki + (lastError - error) * Kd, percent);
    FrontRight.setVelocity(error * Kp + integral * Ki + (lastError - error) * Kd, percent);
    MiddleRight.setVelocity(error * Kp + integral * Ki + (lastError - error) * Kd, percent);
    BackRight.setVelocity(error * Kp + integral * Ki + (lastError - error) * Kd, percent);

    if (targetDegrees < 0){
      FrontLeft.spin(forward);
      MiddleLeft.spin(forward);
      BackLeft.spin(forward);
      FrontRight.spin(reverse);
      MiddleRight.spin(reverse);
      BackRight.spin(reverse);
    }
    else{
      FrontLeft.spin(reverse);
      MiddleLeft.spin(reverse);
      BackLeft.spin(reverse);
      FrontRight.spin(forward);
      MiddleRight.spin(forward);
      BackRight.spin(forward);
    }


    lastError = error;
    wait(0.01, seconds);
    
  }
}
*/

void moveDistance(double inches){
  double omniCircumfrence = 3.1415 * 2 * 3.5;
  int CartridgeTicks = 1800;
  double gearRatio = 0.6;
  float conversion = (CartridgeTicks*gearRatio)/omniCircumfrence;

  FrontLeft.spinFor(forward, inches * conversion, degrees);
  FrontRight.spinFor(forward, inches * conversion, degrees);
  MiddleLeft.spinFor(forward, inches * conversion, degrees);
  MiddleRight.spinFor(forward, inches * conversion, degrees);
  BackLeft.spinFor(forward, inches * conversion, degrees);
  BackRight.spinFor(forward, inches * conversion, degrees);
}

void turnDegrees(double turnDegrees){
  double omniCircumfrence = 3.1415 * 2 * 3.5;
  int CartridgeTicks = 1800;
  double gearRatio = 0.6;
  float conversion = (CartridgeTicks*gearRatio)/omniCircumfrence;
  double degreesFraction=turnDegrees/360;

  FrontLeft.spinFor(fwd, degreesFraction*conversion, degrees);
  FrontRight.spinFor(forward, degreesFraction * conversion, degrees);
  MiddleLeft.spinFor(forward, degreesFraction * conversion, degrees);
  MiddleRight.spinFor(forward, degreesFraction * conversion, degrees);
  BackLeft.spinFor(forward, degreesFraction * conversion, degrees);
  BackRight.spinFor(forward, degreesFraction * conversion, degrees);
}


void auton1 (){
  /*
  1. Intake Alliance triball
  2. Move forward two and a half tiles
  3. Turn 90 degrees right
  4. Move forward a half tile
  5. Outtake Alliance triball
  */

  Intake.spinFor(reverse, 720, degrees);

  moveDistance(45);

  turnDegrees(90);

  moveDistance(12);

  Intake.spinFor(forward, 720, degrees);

  moveDistance(-10);

  turnDegrees(180);

  moveDistance(-12);

  moveDistance(10);
}
 
void auton2(){
    /*
  1. Intake Alliance triball
  2. Move forward two and a half tiles
  3. Turn 90 degrees left
  4. Move forward a half tile
  5. Outtake Alliance triball
  */

  Intake.spinFor(forward, 720, degrees);

  moveDistance(45);

  turnDegrees(-90);

  moveDistance(12);

  Intake.spinFor(reverse, 720, degrees);

  moveDistance(-10);

  turnDegrees(180);

  moveDistance(-12);

  moveDistance(10);
}
void auton3 (){
  /*
  1. Intake Alliance triball
  2. Move forward two and a half tiles
  3. Turn 90 degrees right
  4. Move forward a half tile
  5. Outtake Alliance triball
  */
  Intake.spinFor(forward, 720, degrees);
  moveDistance(45);
  turnDegrees(90);
  moveDistance(12);
  Intake.spinFor(reverse, 720, degrees);
  moveDistance(-10);
  turnDegrees(180);
  moveDistance(-12);
  moveDistance(10);
}

void auton4(){
  //score a preloaded triball and touch the elevation pole after (left side)
  Intake.spinFor(forward, 720, degrees);
  moveDistance(45);
  turnDegrees(90);
  moveDistance(10);
  Intake.spinFor(reverse, 720, degrees);
  moveDistance(-10);
  turnDegrees(180);
  moveDistance(-10);
  moveDistance(10);
  turnDegrees(-90);
  moveDistance(45);
  turnDegrees(90);
  moveDistance(24);
  turnDegrees(90);
  moveDistance(10);
  turnDegrees(-90);
  moveDistance(20);
}

void auton5(){
  //auton 4 but on the right side
  Intake.spinFor(forward, 720, degrees);
  moveDistance(45);
  turnDegrees(-90);
  moveDistance(10);
  Intake.spinFor(reverse, 720, degrees);
  moveDistance(-10);
  turnDegrees(180);
  moveDistance(-10);
  moveDistance(10);
  turnDegrees(90);
  moveDistance(45);
  turnDegrees(-90);
  moveDistance(24);
  turnDegrees(-90);
  moveDistance(10);
  turnDegrees(90);
  moveDistance(20);
}
void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
  auton1();
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
    double rightspeed = (Controller1.Axis3.position()) + (Controller1.Axis1.position() * -1);
    double leftspeed = (Controller1.Axis3.position()) - (Controller1.Axis1.position() * -1);
    FrontLeft.spin(fwd,leftspeed,pct);
    MiddleLeft.spin(fwd,leftspeed,pct);
    BackLeft.spin(fwd,leftspeed,pct);
    FrontRight.spin(fwd,rightspeed,pct);
    MiddleRight.spin(fwd,rightspeed,pct);
    BackRight.spin(fwd,rightspeed,pct);


    //Intake code
    Intake.setVelocity(100, percent);
    if (Controller1.ButtonR1.pressing()){
      Intake.spin(forward);
    }
    else if(Controller1.ButtonR2.pressing()){
      Intake.spin(reverse);
    }
    else {
      Intake.stop();
    }

    if (Controller1.ButtonL1.pressing()){
      Catapult.spin(forward);

    }
    else{
      Catapult.stop();
    }

    if (Controller1.ButtonDown.pressing()){
      Catapult.spinFor(forward, 360, degrees);
    }

    if (Controller1.ButtonL2.pressing()){
      WingLeft.set(true);
    }

  

    wait(10, msec); // Sleep the task for a short amount of time to
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
