// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Intake               motor         18              
// FlywheelMainMotor    motor         1               
// Indexer3498348923    motor         8               
// LF                   motor         12              
// LR                   motor         13              
// RF                   motor         14              
// RR                   motor         15              
// LeftEncoderY         encoder       E, F            
// RightEncoderY        encoder       C, D            
// Inertial1            inertial      11              
// Pnematics            digital_out   G               
// EncoderX             encoder       A, B            
// ColorSensorRight     optical       6               
// ---- END VEXCODE CONFIGURED DEVICES ----
#include "vex.h" // Includes the vex libray
#include"NameSpaceGlobal.h" // Includes My Ligbrary
using namespace vex; // Exports All of the functions and types in namespace "vex"
using namespace DisplayControls; // Exports All of the functions and types in namespace "DisplayControls"
using namespace UserControl;// Exports All of the functions and types in namespace "UserControl"
using namespace Odometry;
using namespace Auton;
/*
        
                               QUICK CODING TUTORIAL
       First when you want to edit a autonomous THE AUTONOMOUS FOLDER IS THE ONLY THING YOU NEED TO WORRY ABOUT
       to edit a auton simply press the file with the autonname with .h at the end
       It will teach you how to tell the robot to do things
       lastly dont forget a ;!
*/
competition Competition; // Delcares the Competion
int main() { // The Main Function
    Inertial1.calibrate();
  while(Inertial1.isCalibrating()){
 wait(15, msec);
}// Boom Bam Bop Bada Boom POW!
  ButtonControls::ShooterFunctions::IndexerHold(IndexerHoldFunction);
 Odometry::Set::setInit();
  thread thread1(Odometry::Orientation::OrientationInit);
  thread thread2(Odometry::odomInit);
  thread thread3(ButtonControls::ShooterFunctions::BlooperInit);
  ColorSensor.setLight(ledState::on);
      ColorSensorRight.setLight(ledState::on);
  Competition.drivercontrol(UserControl::usercontrol); // Delcares User Control
  Competition.autonomous(Auton::autonomous);

 DisplayControls::  DisplayMain(); // Displays Things on the screen
}
/*
Why I did this: 
I decided to reorganize my code because of a long main file and to better organize it.
*/
