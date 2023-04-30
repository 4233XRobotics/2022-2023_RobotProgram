#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;
// VEXcode device constructors
controller Controller1 = controller(primary);
motor Intake = motor(PORT18, ratio18_1, false);
motor FlywheelMainMotor = motor(PORT1, ratio6_1, false);
motor Indexer3498348923 = motor(PORT8, ratio18_1, false);
motor LF = motor(PORT12, ratio18_1, true);
motor LR = motor(PORT13, ratio18_1, false);
motor RF = motor(PORT14, ratio18_1, false);
motor RR = motor(PORT15, ratio18_1, true);
motor ColorSpinner2 = motor(PORT10, ratio36_1, true);
optical ColorSensor = optical(PORT19);
encoder LeftEncoderY = encoder(Brain.ThreeWirePort.E);
encoder RightEncoderY = encoder(Brain.ThreeWirePort.C);
inertial Inertial1 = inertial(PORT11);
digital_out Pnematics = digital_out(Brain.ThreeWirePort.G);
digital_out SmallEndgame = digital_out(Brain.ThreeWirePort.H);
encoder EncoderX = encoder(Brain.ThreeWirePort.A);
optical ColorSensorRight = optical(PORT6);

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