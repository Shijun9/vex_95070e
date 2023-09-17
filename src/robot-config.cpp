#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor FrontLeft = motor(PORT19, ratio18_1, true);
motor FrontRight = motor(PORT15, ratio18_1, false);
motor MiddleLeft = motor(PORT13, ratio18_1, true);
motor MiddleRight = motor(PORT14, ratio18_1, false);
motor BackRight = motor(PORT11, ratio18_1, false);
motor BackLeft = motor(PORT18, ratio18_1, true);
controller Controller1 = controller(primary);
inertial Inertial21 = inertial(PORT21);
motor Intake = motor(PORT20, ratio18_1, false);
motor Catapult = motor(PORT16, ratio36_1, true);
digital_out WingLeft = digital_out(Brain.ThreeWirePort.A);

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