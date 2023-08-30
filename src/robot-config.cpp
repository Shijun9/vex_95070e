#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor FrontLeft = motor(PORT12, ratio18_1, false);
motor FrontRight = motor(PORT18, ratio18_1, false);
motor MiddleLeft = motor(PORT13, ratio18_1, false);
motor MiddleRight = motor(PORT19, ratio18_1, false);
motor BackRight = motor(PORT16, ratio18_1, true);
motor BackLeft = motor(PORT15, ratio18_1, false);
inertial Inertial = inertial(PORT21);
motor Intake = motor(PORT14, ratio18_1, false);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}