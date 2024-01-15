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
// Inertial             inertial      7               
// Intake               motor         6               
// Catapult             motor         5               
// WingLeft             digital_out   A               
// WingRight            digital_out   H               
// ---- END VEXCODE CONFIGURED DEVICES ----


#include "vex.h"
#include <cmath>

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
  Catapult.setVelocity(80, pct);
  Intake.setVelocity(80, pct);

  WingLeft.set(false);
  WingRight.set(false);

  Inertial.calibrate();

  while (Inertial.isCalibrating()){
    Controller1.Screen.print("DON'T MOVE!");
  }
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
void turnDegrees(float targetDegrees){
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
  
}

void turnPID (float targetDegrees){
  float integral = 0;
  float error = targetDegrees - Inertial.heading(degrees);
  float derivative = 0;
  float lastError = error;
  float motorSpeed = 0;
  while (fabs(error) > 1){
    error = targetDegrees - Inertial.heading(degrees);
    integral += error;
    if (fabs(error) < 1){
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
 // wait(200, msec);//going to goal and turning
 // turnPID(90);
 //wait(1, sec);
 //moveDistance(100);
  moveDistance(382.165*2.6);
 // wait(200, msec);
  normalVelocity();
  turnDegrees(90);
  Controller1.Screen.clearScreen();
  Controller1.Screen.print("The error is : %f", error);
 // wait(200, msec);
  Controller1.Screen.print(Inertial.rotation());
  //wait(200, msec);
  
  Intake.spinFor(reverse, 700, degrees, false);//outake to score triball 
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
  turnDegrees(235);
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
  moveDistance(63.695*5);
  wait(200, msec);
  moveDistance(63.695*-5);
  wait(200, msec);
  Intake.stop();
  turnDegrees(60);
  Controller1.Screen.clearScreen();
  Controller1.Screen.print(Inertial.rotation());
  
  wait(200, msec);
  
  Intake.spinFor(reverse, 900, degrees, false);
  moveDistance(382.165*1.5);
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
  moveDistance(382.165*3);
 // wait(200, msec);
  normalVelocity();
  turnPID(90);
  Controller1.Screen.clearScreen();
  Controller1.Screen.print("The error is : %f", error);
  wait(100, msec);
  Controller1.Screen.print(Inertial.rotation());
  wait(100, msec);
  Intake.setVelocity(100, pct);
  Intake.spinFor(reverse, 900, degrees, false);//outake to score triball 
 
 // wait(200, msec);
  moveDistance(63.695*6);  
  wait(500, msec);
  moveDistance(-63.695*5);         
  //wait(200, msec);
  Intake.stop();
  wait(100, msec);
  //turn and move to 2nd triball
  turnDegrees(287);
  Controller1.Screen.clearScreen();
  Controller1.Screen.print("The error is : %f", error);
 // wait(200, msec);
  Controller1.Screen.print(Inertial.rotation());
 // wait(200, msec);
  Intake.setVelocity(100, pct);
  Intake.spin(forward);
  wait(100, msec);
  moveDistance(382.165*0.75);//go to 2nd triball
  wait(0.5, sec);
  normalVelocity();
  wait(100, msec);
  moveDistance(63.695*-1);//move wawy so dont hit wall
  wait(100, msec);
  Intake.stop();
  turnPID(97);//turn toward goal
  wait (100,msec);
  Intake.spin(reverse);
  
  moveDistance(382.165*1.5);
  wait (100,msec);
  Intake.stop();
  wait(100, msec);
  moveDistance(-63.695*3);
  wait(100, msec);
  //go to 3rd triball section
  turnPID(230);//turn to 3rd triball
  
  wait(100, msec);
  Intake.spin(fwd);//nom
  moveDistance(382.165*1.8);//go to 3rd triball
  wait(500, msec);
  Intake.stop();
  Controller1.Screen.clearScreen();
  Controller1.Screen.print(Inertial.rotation());
  
  turnDegrees(60);
  wait(100, msec);
  Intake.spinFor(reverse, 900, degrees, false);
  wait(100, msec);
  moveDistance(382.165*2.5);
  moveDistance(382.165*-1);
  moveDistance(382.165*1.5);
  moveDistance(-63.695*4);
  
  
 
    
}
//current test/trial: get the motors to spin and work up until simiplr to auton
//next test/trial: make each motor spin induvidually
//other options: put wait time to prevent overrides
void testAuton(){
  //move 1 tile ~ 382.165 degrees input
  //63.695 degrees for 1 inch
  //220 degrees for 90 degree rotation
  // moveDistance(382.165)
  // wait(200, msec);
  // Intake.spin(forward);//up to here its good but then it doesnt go all the way in
  // wait(200, msec);
  moveDistance(-382.165*0.6);
  wait(200, msec);
 // moveDistance(-63.695*2);
  turnPID(45);
  wait(200, msec);
  moveDistance(-382.165*1.3);
  wait(200, msec);
  turnPID(90);
  wait(200, msec);
  moveDistance(-63.695*3);
  wait(200, msec);
  

  moveDistance(382.165/2.2);
  wait(200, msec);
  turnPID(45); 
  wait(200, msec);
  moveDistance(63.695);
  wait(200, msec);
  openWings();
  wait (1.5,sec);
  
  moveDistance(382.165*1.4);
  wait(200, msec);
  moveDistance(63.695);
  wait(200, msec);
  closeWings();
  turnPID(0);
  wait(200, msec);

  
  
  wait(200, msec);
  moveDistance(382.165*1.2);
  wait(200, msec);
 // moveDistance(191.0825);
 Intake.spinFor(reverse, 540, degrees, true);
  //wait(200, msec); 
  

 



  /*this may need tweaking cuz it might move the triball whilst turning
  moveDistance(-382.17);//6 inches
  wait(50,msec);
  turnDegrees(220);
  Intake.spinFor(forward, 540, degrees, true);
  wait(50, msec);

  
  moveDistance(63.695);
  wait(50, msec);
  moveDistance(-63.695);
  wait(50, msec);
  turnDegrees(-200);
  wait(50, msec);
  moveDistance(573.25);

  wait(50, msec);
  
  
  //outake into goal hopefully
  Intake.spinFor(reverse, 540, degrees, true);
  wait(50, msec);
  moveDistance(127.39);
  */
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


