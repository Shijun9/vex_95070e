using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor FrontLeft;
extern motor FrontRight;
extern motor MiddleLeft;
extern motor MiddleRight;
extern motor BackRight;
extern motor BackLeft;
extern motor_group L;
extern motor_group R;
extern controller Controller1;
extern inertial Inertial;
extern motor Intake;
extern motor Catapult;
extern digital_out WingLeft;
extern digital_out WingRight;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );