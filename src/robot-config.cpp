#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor FrontLeft = motor(PORT1, ratio18_1, true);
motor FrontRight = motor(PORT10, ratio18_1, false);
motor MiddleLeft = motor(PORT2, ratio18_1, true);
motor MiddleRight = motor(PORT9, ratio18_1, false);
motor BackRight = motor(PORT8, ratio18_1, false);
motor BackLeft = motor(PORT3, ratio18_1, true);
controller Controller1 = controller(primary);
inertial Inertial = inertial(PORT4);
motor Intake = motor(PORT21, ratio18_1, false);
motor Catapult = motor(PORT5, ratio36_1, true);
digital_out WingLeft = digital_out(Brain.ThreeWirePort.A);
digital_out WingRight = digital_out(Brain.ThreeWirePort.H);

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