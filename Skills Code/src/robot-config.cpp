#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor FrontLeft = motor(PORT15, ratio18_1, true);
motor FrontRight = motor(PORT19, ratio18_1, false);
motor MiddleLeft = motor(PORT13, ratio18_1, true);
motor MiddleRight = motor(PORT10, ratio18_1, false);
motor BackLeft = motor(PORT20, ratio18_1, true);
motor BackRight = motor(PORT11, ratio18_1, false);
inertial Inertial21 = inertial(PORT21);
motor Intake = motor(PORT17, ratio18_1, false);

// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}