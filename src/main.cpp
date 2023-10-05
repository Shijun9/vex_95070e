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
// MiddleLeft           motor         14              
// MiddleRight          motor         10              
// BackRight            motor         11              
// BackLeft             motor         18              
// Controller1          controller                    
// Inertial21           inertial      21              
// Intake               motor         12              
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
int slctauton;
void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  FrontLeft.setVelocity(100, percent);
  MiddleLeft.setVelocity(100, percent);
  BackLeft.setVelocity(100, percent);
  FrontRight.setVelocity(100, percent);
  MiddleRight.setVelocity(100, percent);
  BackRight.setVelocity(100, percent);
  // Elevation.setVelocity(100,percent);


  // Elevation.setPosition(90, degrees);
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

void testmove(double inches){
  //FrontLeft.spinFor(forward, inches, degrees, false);//works
  //FrontRight.spinFor(forward, inches, degrees, false);//works
  //MiddleLeft.spinFor(forward, inches, degrees, false);//works
  //MiddleRight.spinFor(forward, inches, degrees, false);//doesnt work
  BackLeft.spinFor(forward, inches, degrees, false);//
  BackRight.spinFor(reverse, inches, degrees);//
}

void moveDistance(double inches){
  double omniCircumfrence = atan(-1)*4 * 2 * 3;//18.849
  int CartridgeTicks = 900;
  double gearRatio = 10/6;
  float conversion = (CartridgeTicks*gearRatio)/omniCircumfrence;//1080/18.849 ~ 57.29746936


  FrontLeft.spinFor(forward, inches, degrees, false);
  FrontRight.spinFor(forward, inches, degrees, false);
  MiddleLeft.spinFor(forward, inches, degrees, false);
  MiddleRight.spinFor(forward, inches, degrees, false);
  BackLeft.spinFor(forward, inches, degrees, false);
  BackRight.spinFor(forward, inches, degrees);
}

void turnDegrees(double turnDegrees){
  double omniCircumfrence = atan(-1)*4 * 2 * 3;
  int CartridgeTicks = 900;
  double gearRatio = 10/6;
  float conversion = (CartridgeTicks*gearRatio)/omniCircumfrence;
  double degreesFraction=turnDegrees/360;

  FrontLeft.spinFor(fwd, turnDegrees, degrees, false);
  FrontRight.spinFor(reverse, turnDegrees, degrees, false);
  MiddleLeft.spinFor(fwd, turnDegrees, degrees, false);
  MiddleRight.spinFor(reverse, turnDegrees, degrees, false);
  BackLeft.spinFor(fwd, turnDegrees, degrees, false);
  BackRight.spinFor(reverse, turnDegrees, degrees);
}


void auton1 (){
  /*
  1. Intake Alliance triball
  2. Move forward two and a half tiles
  3. Turn 90 degrees right
  4. Move forward a half tile
  5. Outtake Alliance triball
  */

  // Catapult.spinFor(100, degrees);

  moveDistance(250);

  turnDegrees(200);
  moveDistance(12);
  Intake.spinFor(forward, 720, degrees);
  // moveDistance(-10);
  // turnDegrees(180);
 // moveDistance(-12);
  // moveDistance(10);
}
 
void auton2(){
  /*
  1. Intake Alliance triball
  2. Move forward two and a half tiles
  3. Turn 90 degrees left
  4. Move forward a half tile
  5. Outtake Alliance triball
  */

  // Catapult.spinFor(100, degrees);
  moveDistance(250);

  turnDegrees(-90);
  moveDistance(12);
  Intake.spinFor(forward, 720, degrees);
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

void auton6(void){
  //score the perload triball
  //then score the triball right outside the goal
  Intake.spinFor(reverse, 720, degrees);
  moveDistance(45);
  turnDegrees(90);
  moveDistance(12);
  Intake.spinFor(forward, 720, degrees);
  moveDistance(-10);
  turnDegrees(180);
  moveDistance(-12);
  moveDistance(10);
  turnDegrees(-90);
  moveDistance(12);
  turnDegrees(90);
  moveDistance(15);
  Intake.spinFor(forward, 720, degrees);
  turnDegrees(180);
  moveDistance(30);
  Intake.spinFor(reverse, 720, degrees);
  moveDistance(-10);
  turnDegrees(180);
  moveDistance(-10);

 
}

void auton7(void){
  //score the perload triball
  //then score the triball right outside the goal
  //scoring the triball that was behind the other triball that we scored
  Intake.spinFor(reverse, 720, degrees);
  moveDistance(45);
  turnDegrees(90);
  moveDistance(12);
  Intake.spinFor(forward, 720, degrees);
  moveDistance(-10);
  turnDegrees(180);
  moveDistance(-12);
  moveDistance(10);
  turnDegrees(-90);
  moveDistance(12);
  turnDegrees(90);
  moveDistance(15);
  Intake.spinFor(forward, 720, degrees);
  turnDegrees(180);
  moveDistance(30);
  Intake.spinFor(reverse, 720, degrees);
  moveDistance(-10);
  turnDegrees(180);
  moveDistance(-10);
  moveDistance(48);
  Intake.spinFor(forward, 720, degrees);
  moveDistance(-25);
  turnDegrees(180);
  moveDistance(-25);
  Intake.spinFor(reverse, 720, degrees);
  moveDistance(-10);
  turnDegrees(180);
  moveDistance(-10);

}
//current test/trial: get the motors to spin and work up until simiplr to auton
//next test/trial: make each motor spin induvidually
//other options: put wait time to prevent overrides
void testAuton(void){
  turnDegrees(180);
}

void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................

  if (slctauton == 1) {
    auton1();
  }

  if (slctauton == 2) {
    auton2();
  }

  if (slctauton == 3) {
    auton3();
  }

  if (slctauton == 4) {
    auton4();
  }

  if (slctauton == 5) {
    auton5();
  }

  if (slctauton == 6) {
    auton6();
  }

  if (slctauton == 7) {
    auton7();
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
/*
void unitTest (){
  while (1){
    FrontLeft.spin(fwd);
  }
}
*/



bool Jessica = 0;

void autonslctr() {
  int numofautons = 7;
  if (slctauton > numofautons) {
    slctauton = 1;
  }
  
  else if (slctauton < 0) {
    slctauton = numofautons;
  }

  if (Controller1.ButtonRight.pressing()) {
    wait(1000,msec);
    slctauton++;
  }

  else if (Controller1.ButtonLeft.pressing()) {
    wait(1000,msec);
    slctauton--;
  }

  if (slctauton == 1) {
    Controller1.Screen.clearScreen();
    Controller1.Screen.setCursor(1,1);
    Controller1.Screen.print("Auton 1");
    }

  else if (slctauton == 2) {
    Controller1.Screen.clearScreen();
    Controller1.Screen.setCursor(1,1);
    Controller1.Screen.print("Auton 2");
  }

  else if (slctauton == 3) {
    Controller1.Screen.clearScreen();
    Controller1.Screen.setCursor(1,1);
    Controller1.Screen.print("Auton 3");
  }

  else if (slctauton == 4) {
    Controller1.Screen.clearScreen();
    Controller1.Screen.setCursor(1,1);
    Controller1.Screen.print("Auton 4");
  }

  else if(slctauton == 5) {
    Controller1.Screen.clearScreen();
    Controller1.Screen.setCursor(1,1);
    Controller1.Screen.print("Auton 5");
  }

  else if (slctauton == 6) {
    Controller1.Screen.clearScreen();
    Controller1.Screen.setCursor(1,1);
    Controller1.Screen.print("Auton 6");
  }

  else if (slctauton == 7) {
    Controller1.Screen.clearScreen();
    Controller1.Screen.setCursor(1,1);
    Controller1.Screen.print("Auton 7");
  }

}


void usercontrol(void) {
  // User control code here, inside the loop
  while(!Jessica) {
    autonslctr();
    if (Controller1.ButtonA.pressing()) {
      Jessica = 1;
    }
    wait(20,msec);
  }


  while (Jessica) {
    // unitTest();
    
    
    double rightspeed = (Controller1.Axis3.position()) + (Controller1.Axis1.position() * -0.8);
    double leftspeed = (Controller1.Axis3.position()) - (Controller1.Axis1.position() * -0.8);
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
    //Cata 
    
    if (Controller1.ButtonL1.pressing()){ 
      Catapult.setMaxTorque(70, pct);
      Catapult.setStopping(coast);
      Catapult.spin(forward,100,pct);

    }
    else{
      Catapult.stop();
    }
    // cata down
    if (Controller1.ButtonDown.pressing()){
      // Catapult.setStopping(hold);
      Catapult.spinFor(forward, 1, degrees);
    }

    if (Controller1.ButtonX.pressing()){
      WingLeft.set(true);
    }
    //Elevation code
    /*
    if(Controller1.ButtonUp.pressing()){
      Elevation.spin(forward);
    }
    */

    wait(10, msec); // Sleep the task for a short amount of time
                    // to prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//



int main() {
  // Set up callbacks for autonomous and driver control periods.
  // unitTest();
  
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
  

  // Run the pre-autonomous function.
  pre_auton();
  
  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
  
 
}


