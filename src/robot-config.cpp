#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor FrontLeft = motor(PORT20, ratio6_1, true);
motor FrontRight = motor(PORT11, ratio6_1, false);
motor MiddleLeft = motor(PORT19, ratio6_1, true);
motor MiddleRight = motor(PORT9, ratio6_1, false);
motor BackRight = motor(PORT1, ratio6_1, false);
motor BackLeft = motor(PORT10, ratio6_1, true);
motor_group L = motor_group(FrontLeft, MiddleLeft, BackLeft);
motor_group R = motor_group(FrontRight, MiddleRight, BackRight);
controller Controller1 = controller(primary);
inertial Inertial = inertial(PORT15);
motor Intake = motor(PORT18, ratio18_1, false);
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