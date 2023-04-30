using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor Intake;
extern motor FlywheelMainMotor;
extern motor Indexer3498348923;
extern motor LF;
extern motor LR;
extern motor RF;
extern motor RR;
extern motor ColorSpinner2;
extern optical ColorSensor;
extern encoder LeftEncoderY;
extern encoder RightEncoderY;
extern inertial Inertial1;
extern digital_out Pnematics;
extern digital_out SmallEndgame;
extern encoder EncoderX;
extern optical ColorSensorRight;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );