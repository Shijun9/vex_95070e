// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// FrontLeft            motor         20              
// FrontRight           motor         11              
// MiddleLeft           motor         19              
// MiddleRight          motor         9               
// BackRight            motor         1               
// BackLeft             motor         10              
// Controller1          controller                    
// Inertial             inertial      4               
// Intake               motor         18              
// Catapult             motor         5               
// WingLeft             digital_out   A               
// WingRight            digital_out   H               
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// FrontLeft            motor         20              
// FrontRight           motor         11              
// MiddleLeft           motor         19              
// MiddleRight          motor         9               
// BackRight            motor         1               
// BackLeft             motor         10              
// Controller1          controller                    
// Inertial             inertial      7               
// Intake               motor         18              
// Catapult             motor         5               
// WingLeft             digital_out   A               
// WingRight            digital_out   H               
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// FrontLeft            motor         20              
// FrontRight           motor         11              
// MiddleLeft           motor         19              
// MiddleRight          motor         9               
// BackRight            motor         1               
// BackLeft             motor         10              
// Controller1          controller                    
// Inertial             inertial      2               
// Intake               motor         18              
// Catapult             motor         5               
// WingLeft             digital_out   A               
// WingRight            digital_out   H               
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// FrontLeft            motor         1               
// FrontRight           motor         10              
// MiddleLeft           motor         2               
// MiddleRight          motor         9               
// BackRight            motor         8               
// BackLeft             motor         3               
// Controller1          controller                    
// Inertial             inertial      4               
// Intake               motor         20              
// Catapult             motor         5               
// WingLeft             digital_out   A               
// WingRight            digital_out   H               
// ---- END VEXCODE CONFIGURED DEVICES ----


#include "vex.h"
#include <cmath>
using namespace vex;
#include <iostream>
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
//testing
float actualHeading = Inertial.heading(degrees);
float targetDegrees = 0;
float targetHeading = targetDegrees;
float error = targetHeading - actualHeading;
float motorSpeed = error;
void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  FrontLeft.setVelocity(100, percent);
  MiddleLeft.setVelocity(100, percent);
  BackLeft.setVelocity(100, percent);
  FrontRight.setVelocity(100, percent);
  MiddleRight.setVelocity(100, percent);
  BackRight.setVelocity(100, percent);
  Catapult.setVelocity(90, pct);
  Intake.setVelocity(80, pct);

  WingLeft.set(false);
  WingRight.set(false);

  Inertial.calibrate();

  while (Inertial.isCalibrating()){
    Controller1.Screen.print("DON'T MOVE!");
  }
 // Controller1.rumble(rumblePulse);
  
  Inertial.setHeading(0, degrees);
  Controller1.Screen.clearScreen();
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
  //360 degrees 
  //9.42 in 1 fulll rotation
  //36-tooth
  //60-tooth
  //36:60 ~ 1:0.6
  //360 degrees - 0.6
  //5.652 inches per 360 degrees input
  //each tile is 24 in long
  //move 1 tile ~ 1528.66 degrees input

  FrontLeft.spinFor(fwd, inches, degrees, false);
  FrontRight.spinFor(fwd, inches, degrees, false);
  MiddleLeft.spinFor(fwd, inches, degrees, false);
  MiddleRight.spinFor(fwd, inches, degrees, false);
  BackLeft.spinFor(fwd, inches, degrees, false);
  BackRight.spinFor(fwd, inches, degrees);
}
/*
FrontLeft.spinFor(fwd, Inertial.rotation(degrees)+turnDegrees, degrees, false);
FrontRight.spinFor(reverse, Inertial.rotation(degrees)+turnDegrees, degrees, false);
MiddleLeft.spinFor(fwd, Inertial.rotation(degrees)+turnDegrees, degrees, false);
MiddleRight.spinFor(reverse, Inertial.rotation(degrees)+turnDegrees, degrees, false);
BackLeft.spinFor(fwd, Inertial.rotation(degrees)+turnDegrees, degrees, false);
BackRight.spinFor(reverse, Inertial.rotation(degrees)+turnDegrees, degrees);
// wait(10, msec);
// double omniCircumfrence = atan(-1)*4 * 2 * 3;
// int CartridgeTicks = 900;
// double gearRatio = 10/6;
// float conversion = (CartridgeTicks*gearRatio)/omniCircumfrence;
// double degreesFraction=targetDegrees/360;
*/

float kp = 0.6;
float ki = 0;
float kd = 0.5;


void turnDegrees(double targetDegrees){
  double omniCircumfrence = atan(-1)*4 * 2 * 3;//18.849
  int CartridgeTicks = 900;
  double gearRatio = 10/6;
  float conversion = (CartridgeTicks*gearRatio)/omniCircumfrence;//1080/18.849 ~ 57.29746936
  //360 degrees 
  //9.42 in 1 fulll rotation
  //36-tooth
  //60-tooth
  //36:60 ~ 1:0.6
  //360 degrees - 0.6
  //5.652 inches per 360 degrees input
  //each tile is 24 in long
  //move 1 tile ~ 1528.66 degrees input

  FrontLeft.spinFor(fwd, targetDegrees, degrees, false);
  FrontRight.spinFor(reverse, targetDegrees, degrees, false);
  MiddleLeft.spinFor(fwd, targetDegrees, degrees, false);
  MiddleRight.spinFor(reverse, targetDegrees, degrees, false);
  BackLeft.spinFor(fwd, targetDegrees, degrees, false);
  BackRight.spinFor(reverse, targetDegrees, degrees);
 
  /*
  Controller1.Screen.print("turning...");
  
  // Inertial.calibrate();
  
  float actualHeading = Inertial.heading(degrees);
  float targetHeading = targetDegrees;
  float error = targetHeading - actualHeading;
  float motorSpeed = kp*error;

  while (true){
      
   
    while (fabs(error)>2){
      actualHeading = Inertial.heading(degrees);
     error = targetHeading - actualHeading;
      motorSpeed = kp*error;
      FrontLeft.spin(fwd, motorSpeed, pct);
      FrontRight.spin(reverse, motorSpeed,pct);
     MiddleLeft.spin(fwd, motorSpeed, pct);
     MiddleRight.spin(reverse, motorSpeed, pct);
     BackLeft.spin(fwd, motorSpeed, pct);
     BackRight.spin(reverse, motorSpeed, pct);
     Controller1.Screen.clearScreen();
     Controller1.Screen.setCursor(1, 1);
     Controller1.Screen.print("error =  : %f", error);
     Controller1.Screen.setCursor(2, 1);
     Controller1.Screen.print("Inertial heading is : %f, ", Inertial.heading());
     wait (15, msec);
     
    }
    return;
    // motorSpeed = 0;
    //break;
  
  
    
  }
  */
}
/*          NOTES
have a way of caltulating heading so it turns in the moroe efficient direction - basic casework maybe
find way of going over 0
clockwise is positive, counterclockwise is negative

static double Turnerror (double targetdegrees){
int throughZeroDirection;
doiuble smallerDegree = std::min(targetdegrees, inertial.heading)
double largerDegree = std::max (targetdegreees, inertial.heading)

if (smallerDegree == target){
  throughZeroDirection = 1;
}
else {
  throughzeroDirection = -1;
}

if  (largerDegree - sallerdegree > 180){
  return throughZerodirection * (360 - largerdegree + smallerdegree)
}
else{
  return tartgetdegrees - ineritla.heading
}
}

added - add minimum speed; like is motorspeed less than 5, make it spin a 5

done - change fabs(error)>1 to fabs(error) >3 in if statement

maybe retune it; incrasase kp until fluctuates, then change kd until it stops (repeat until cant no more)
integral if there is a stready state; propbabbly not necesary - after comp

*/
/*
double turnError (double targetDegrees){

  int throughZeroDirection;

  double smallerDegree = std::min(targetDegrees, Inertial.heading());
  double largerDegree = std::max (targetDegrees, Inertial.heading());

  if (smallerDegree == targetDegrees){
    throughZeroDirection = 1;
  }

  else {
    throughZeroDirection = -1;
  }

  if  (largerDegree - smallerDegree > 180){
    return throughZeroDirection * (360 - largerDegree + smallerDegree);
  }

  else {
    return targetDegrees - Inertial.heading();
  }

}
*/

void turnPID (float targetDegrees){
  float integral = 0;
  float error = targetDegrees - Inertial.heading(degrees);
  float derivative = 0;
  float lastError = error;
  float motorSpeed = 0;
  while (fabs(error) > 1){
    error = targetDegrees - Inertial.heading(degrees);
    integral += error;
    if (fabs(error) < 3){
      FrontLeft.stop();
      FrontRight.stop();
      MiddleLeft.stop();
      MiddleRight.stop();
      BackRight.stop();
      BackLeft.stop();
      return;
    }
    motorSpeed = error * kp + integral * ki + (error - lastError) * kd;
    FrontLeft.spin(fwd, motorSpeed, pct);
    FrontRight.spin(reverse, motorSpeed, pct);
    MiddleLeft.spin(fwd, motorSpeed, pct);
    MiddleRight.spin(reverse, motorSpeed, pct);
    BackRight.spin(reverse, motorSpeed, pct);
    BackLeft.spin(fwd, motorSpeed, pct);
    lastError = error;
    wait (20, msec);

  }


}

int lastHeading=0;
void Right(double angle) {
  Inertial.setRotation(0,deg);
  while (fabs(Inertial.rotation()) < angle) {
    double error = angle - fabs(Inertial.rotation());
    L.spin(forward, error * 0.35 + 5, pct);
    R.spin(reverse, error * 0.35 + 5, pct);
  }
  L.stop(brake);
  R.stop(brake);
}

void Left(double angle) {
  Inertial.setRotation(0,deg);
  while (fabs(Inertial.rotation()) < angle) {
    lastHeading=Inertial.rotation();
    double error = angle - fabs(Inertial.rotation());
    L.spin(reverse, error * 0.35 + 5, pct);
    R.spin(forward, error * 0.35 + 5, pct);
  }
  L.stop(brake);
  R.stop(brake);
}

void drivePID(double targetdegrees) {
  double error = targetdegrees;
  double integral = 0;
  double lasterror = error;
  // tare


  while (true) {
    if (fabs(error) < 3) {
      integral += error;
    }
    double measureddegrees = Inertial.heading();
    error = targetdegrees - measureddegrees;

    //Controller1.Screen.setCursor(1, 1);
    
    Controller1.Screen.print("error: %f", error);
    Controller1.Screen.newLine();
   // Controller1.Screen.setCursor(1, 2);
    Controller1.Screen.print("heading: %f", Inertial.heading(degrees));
    Controller1.Screen.newLine();
   // Controller1.Screen.setCursor(1, 3);
    Controller1.Screen.print("rotation: %f", Inertial.rotation());

    // turn forward pid distance, if at target, pid should stop
    FrontLeft.spinFor(reverse, error * kp + integral * ki + (error - lasterror) * kd, degrees);
    MiddleLeft.spinFor(reverse, error * kp + integral * ki + (error - lasterror) * kd, degrees);
    BackLeft.spinFor(reverse, error * kp + integral * ki + (error - lasterror) * kd, degrees);
    FrontRight.spinFor(forward, error * kp + integral * ki + (error - lasterror) * kd, degrees);
    MiddleRight.spinFor(forward, error * kp + integral * ki + (error - lasterror) * kd, degrees);
    BackRight.spinFor(forward, error * kp + integral * ki + (error - lasterror) * kd, degrees);


    if (error < 3) {
      FrontLeft.stop();
      MiddleLeft.stop();
      BackLeft.stop();
      FrontRight.stop();
      MiddleRight.stop();
      BackRight.stop();
    }


    // rightdrive.move_velocity(error * kp + integral * ki +(error - lasterror) * kd);
    lasterror = error;
    wait(10, msec);
  }
}

void auton1 (){
  /*
  1. Intake Alliance triball
  2. Move forward two and a half tiles
  3. Turn 90 degrees right
  4. Move forward a half tile
  5. Outtake Alliance triball
  */



  moveDistance(7000);

  turnDegrees(300);
  moveDistance(1000);
  Intake.spinFor(forward, 720, degrees);
  moveDistance(-100);
  // turnDegrees(180);
 // moveDistance(-12);
  // moveDistance(100);
}
 
void auton2(){
  /*
  1. Intake Alliance triball
  2. Move forward two and a half tiles
  3. Turn 90 degrees left
  4. Move forward a half tile
  5. Outtake Alliance triball
  */

  moveDistance(-5000);
  moveDistance(300);

}

void openWings(){
  WingRight.set(true);
  WingLeft.set(true);
}

void closeWings(){
  WingRight.set(false);
  WingLeft.set(false);
}

void lessVelocity(){
  FrontLeft.setVelocity(80, pct);
  FrontRight.setVelocity(80, pct);
  MiddleLeft.setVelocity(80, pct);
  MiddleRight.setVelocity(80, pct);
  BackLeft.setVelocity(80, pct);
  BackRight.setVelocity(80, pct);
}

void normalVelocity(){
  FrontLeft.setVelocity(100, percent);
  MiddleLeft.setVelocity(100, percent);
  BackLeft.setVelocity(100, percent);
  FrontRight.setVelocity(100, percent);
  MiddleRight.setVelocity(100, percent);
  BackRight.setVelocity(100, percent);
}

void auton3 (){
  /*
  1. Intake Alliance triball
  2. Move forward two and a half tiles
  3. Turn 90 degrees right
  4. Move forward a half tile
  5. Outtake Alliance triball
  */
  wait(200, msec);//going to goal and turning
  moveDistance(382.165*2.5);
  wait(200, msec);
  turnDegrees(200);
  Controller1.Screen.clearScreen();
  Controller1.Screen.print(Inertial.rotation());
  wait(200, msec);
  
  Intake.spinFor(reverse, 700, degrees, false);//outake to score triball 
  wait(200, msec);
  moveDistance(63.695*4);
  wait(200, msec);
  moveDistance(-63.695*4);
  wait(200, msec);
  lessVelocity();
  //turn and move to 2nd triball
  turnDegrees(425);
  Controller1.Screen.clearScreen();
  Controller1.Screen.print(Inertial.rotation());
  wait(200, msec);
  Intake.setVelocity(100, pct);
  Intake.spin(forward);

  wait(1, sec);
  moveDistance(382.165*1.5);
  
  wait(2, sec);
  // Intake.stop();
  normalVelocity();
  wait(200,msec);
  
  moveDistance(-63.695*2.5);
  wait(200, msec);
  turnDegrees(470);
  Controller1.Screen.clearScreen();
  Controller1.Screen.print(Inertial.rotation());
  Intake.stop();
  WingLeft.set(true);
  WingRight.set(true);

  wait(200, msec);
  
  Intake.spinFor(reverse, 900, degrees, false);
  moveDistance(382.165*1.5);
  wait(200, msec);
  moveDistance(-63.695*6);
  wait(200, msec);
  moveDistance(63.695*7);
  wait(200, msec);
}

void auton4(){
  //score a preloaded triball and touch the elevation pole after (left side) hi
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
 // wait(200, msec);//going to goal and turning
 // turnPID(90);
 //wait(1, sec);
 //moveDistance(100);
  moveDistance(382.165*2.5);
 // wait(200, msec);
  normalVelocity();
  turnPID(180);
  Controller1.Screen.clearScreen();
  Controller1.Screen.print("The error is : %f", error);
 // wait(200, msec);
  Controller1.Screen.print(Inertial.heading());
  Controller1.Screen.print(Inertial.rotation());
  //wait(200, msec);
  
  Intake.spinFor(reverse, 1500, degrees, false);//outake to score triball 
 // wait(200, msec);
  moveDistance(63.695*4);
 // wait(200, msec);
  moveDistance(-63.695*5);
  //wait(200, msec);
  moveDistance(63.695*5);
 // wait(200, msec);
  moveDistance(-63.695*4);         
  //wait(200, msec);
  
  //turn and move to 2nd triball
  turnPID(315);
  Controller1.Screen.clearScreen();
  Controller1.Screen.print("The error is : %f", error);
 // wait(200, msec);
  Controller1.Screen.print(Inertial.rotation());
 // wait(200, msec);
  Intake.setVelocity(100, pct);
  Intake.spin(forward);
  wait(200, msec);
  moveDistance(382.165*1.6);
  wait(1, sec);
  normalVelocity();
  wait(200,msec);
 //  moveDistance(63.695*5);
  wait(200, msec);
  moveDistance(63.695*-3);
  wait(200, msec);
  Intake.stop();
  turnPID(190);
  Controller1.Screen.clearScreen();
  Controller1.Screen.print(Inertial.rotation());
  
  wait(200, msec);
  
  Intake.spinFor(reverse, 900, degrees, false);
  moveDistance(382.165*1.3);
  wait(200, msec);
  moveDistance(-63.695*6);
  wait(200, msec);
  moveDistance(63.695*7);
  wait(200, msec);
  moveDistance(-63.695*6);
  /*Intake.spinFor(forward, 540, degrees, true);
  wait(200, msec);
  moveDistance(-382.165/2);
  wait(200, msec);*/
  
}

void auton7(void){

  //input 235 = 90 degrees turnnig

  moveDistance(382.165*2.2); // fwd
  wait(200, msec);
  normalVelocity();
  Right(80); 
  
  Controller1.Screen.clearScreen();
  // Controller1.Screen.print("The error is : %f", error);
  wait(100, msec);
  Controller1.Screen.print(Inertial.rotation());
  Controller1.Screen.print(Inertial.heading());
  wait(100, msec);
  Intake.setVelocity(100, pct);
  Intake.spinFor(reverse, 1500, degrees, false);//outake to score triball 
  
  wait(200, msec);
  moveDistance(63.695*2.4); //63.695 increase this one
  wait(500, msec);
  
  moveDistance(-63.695*1.3);// old was 63.595
          
  //wait(200, msec);
  Intake.stop();
  wait(100, msec);
  //turn and move to 2nd triball
  lessVelocity();
  Right(120);//turn to center spot
  moveDistance(63.695*3.7);
  Right(95);
  
  wait(200, msec);
  Intake.spinFor(fwd, 1500, degrees, false);
  moveDistance(63.695*4);
  Intake.setVelocity(100, pct);
  Intake.spinFor(fwd, 1500, degrees, false);//outake to score triball 
  moveDistance(63.695*3.3);
  wait(1000, msec);
  
  Left(30);
  wait(200, msec);
  WingLeft.set(true);
  WingRight.set(true);
  wait(200, msec);
  moveDistance(-63.695*8);

  WingLeft.set(false);
  WingRight.set(false);
  wait(250,msec);
  moveDistance(63.695*1.5);
  wait(250,msec);
  Left(180);
  Intake.setVelocity(100, pct);
  Intake.spinFor(reverse, 1500, degrees, false);
  wait(200, msec);
  moveDistance(63.695*2);
  moveDistance(-63.695*1.5);
  

  /*
  wait(200, msec);
  Right(3);
  Controller1.Screen.print(Inertial.rotation());
  Controller1.Screen.print(Inertial.heading());
  moveDistance(382.165);
  
  
  Right(270);//faces 2nd triball
  // Controller1.Screen.clearScreen();
  // Controller1.Screen.print("The error is : %f", error);
  // wait(200, msec);
 
  Controller1.Screen.print(Inertial.rotation());
 // wait(200, msec);
  Intake.setVelocity(100, pct);
  Intake.spin(forward);
  wait(100, msec);
  moveDistance(382.165*1.25);//go to 2nd triball
  wait(0.5, sec);
  
  normalVelocity();
  wait(100, msec);
  Intake.stop();
  
  moveDistance(-63.695);//move wawy so dont hit wall
  Right(270);//face away from goal
  WingLeft.set(true);
  moveDistance(-382.165*1.5);//push 3rd triball into goal with wing
  wait(100, msec);
  moveDistance(63.695*3);
  wait(100, msec);
  Right(70);//turn toward goal
  wait (100, msec);
  Intake.setVelocity(100, pct);
  Intake.spinFor(reverse, 1800, degrees, false);
  
  moveDistance(63.695*3);
  wait(100, msec);
  moveDistance(-63.695*3);
  wait(100, msec);
  Intake.stop();
  moveDistance(63.695*4.5);
  wait(100, msec);
  moveDistance(-63.695*3);
  //go to 3rd triball section
  */
  
  
  /*
  turnPID(230);//turn to 3rd triball
  
  wait(100, msec);
  Intake.spin(fwd);//nom
  moveDistance(382.165*1.8);//go to 3rd triball
  wait(500, msec);
  Intake.stop();
  Controller1.Screen.clearScreen();
  Controller1.Screen.print(Inertial.rotation());
  
  turnDegrees(10);
  wait(100, msec);
  Intake.spinFor(reverse, 900, degrees, false);
  wait(100, msec);
  moveDistance(382.165*2.5);
  moveDistance(382.165*-1);
  moveDistance(382.165*1.5);
  moveDistance(-63.695*4);
  */
  
 
    
}

void betterAuton(void){
  moveDistance(382.165*2.35);
 // wait(200, msec);
  normalVelocity();
  turnPID(80);
  Controller1.Screen.clearScreen();
  // Controller1.Screen.print("The error is : %f", error);
  wait(100, msec);
  Controller1.Screen.print(Inertial.rotation());
  Controller1.Screen.print(Inertial.heading());
  wait(100, msec);
  Intake.setVelocity(100, pct);
  Intake.spinFor(reverse, 1500, degrees, false);//outake to score triball 
 
 // wait(200, msec);
  moveDistance(63.695*2.5);  
  wait(500, msec);
  moveDistance(-63.695*4);
           
  //wait(200, msec);
  Intake.stop();
  wait(100, msec);
  //turn and move to 2nd triball
  lessVelocity();
  turnPID(1);//turn to center spot
  moveDistance(0.5);
  turnPID(21);//faces 2nd triball
  // Controller1.Screen.clearScreen();
  // Controller1.Screen.print("The error is : %f", error);
 // wait(200, msec);
  Controller1.Screen.print(Inertial.rotation());
 // wait(200, msec);
  Intake.setVelocity(100, pct);
  Intake.spin(forward);
  wait(100, msec);
  moveDistance(382.165*0.8);//go to 2nd triball
  wait(0.5, sec);
  normalVelocity();
  wait(100, msec);
  Intake.stop();
  //moveDistance(63.695*-0.1);//move wawy so dont hit wall
  turnPID(360);//face away from goal
  WingLeft.set(true);
  moveDistance(-600);//push 3rd triball into goal with wing
  wait(100, msec);
  moveDistance(63.695*3);
  wait(100, msec);
  turnPID(187);//turn toward goal
  wait (100,msec);
  Intake.setVelocity(100, pct);
  Intake.spinFor(reverse, 1500, degrees, false);
  
  moveDistance(63.695*3);
  wait(100, msec);
  moveDistance(-63.695*3);
  wait(100, msec);
  Intake.stop();
  moveDistance(63.695*4.5);
  wait(100, msec);
  moveDistance(-63.695*3); 
    
}
//current test/trial: get the motors to spin and work up until simiplr to auton
//next test/trial: make each motor spin induvidually
//other options: put wait time to prevent overrides
void testAuton(){
  // moveDistance(-63.695*3);
  // Right(30);
  WingRight.set(true);
  WingLeft.set(true);
  moveDistance(-63.695*4);
  wait(500, msec);
  WingLeft.set(false);
  WingRight.set(false);

  moveDistance(63.695*5);
  
  Left(30);

  moveDistance(63.695*9.65);
  Intake.setVelocity(100, pct);
  Intake.spinFor(reverse, 1500, degrees, false);//outake to score triball 
  
}



void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
  if (slctauton == 1) {
    auton2();
  }

  if (slctauton == 2) {
    testAuton();
  }

  if (slctauton == 3) {
    auton7();
  }

  if (slctauton == 4) {
    auton6();
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

  if (slctauton == 8){
    auton1();
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
  int numofautons = 8;
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
    Controller1.Screen.print("1 triball auton");
  }

  else if (slctauton == 2) {
    Controller1.Screen.clearScreen();
    Controller1.Screen.setCursor(1,1);
    Controller1.Screen.print("AWP - matchload side");
  }

  else if (slctauton == 3) {
    Controller1.Screen.clearScreen();
    Controller1.Screen.setCursor(1,1);
    Controller1.Screen.print("3 Triball Auton");
  }

  else if (slctauton == 4) {
    Controller1.Screen.clearScreen();
    Controller1.Screen.setCursor(1,1);
    Controller1.Screen.print("2 triball auton");
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

  else if (slctauton == 8) {
    Controller1.Screen.clearScreen();
    Controller1.Screen.setCursor(1,1);
    Controller1.Screen.print("Auton 1");
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
    
    
    double rightspeed = (Controller1.Axis3.position()) + (Controller1.Axis1.position() * -1);
    double leftspeed = (Controller1.Axis3.position()) - (Controller1.Axis1.position() * -1);
    FrontLeft.spin(fwd,leftspeed,pct);
    MiddleLeft.spin(fwd,leftspeed,pct);
    BackLeft.spin(fwd,leftspeed,pct);
    
    FrontRight.spin(fwd,rightspeed,pct);
    MiddleRight.spin(fwd,rightspeed,pct);
    BackRight.spin(fwd,rightspeed,pct);


    //Intake code
    Intake.setVelocity(200, percent);
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
      Catapult.spin(fwd);

    }
    else{
      Catapult.stop();
    }
    // cata down
    if (Controller1.ButtonDown.pressing()){
      Catapult.spin(forward);
    }
    // wing
    if (Controller1.ButtonX.pressing()){
      WingLeft.set(true);
      WingRight.set(true);
    }
    else if (Controller1.ButtonY.pressing()){
      WingLeft.set(false);
      WingRight.set(false);
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


