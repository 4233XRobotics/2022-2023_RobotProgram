#include "robot-config.h"
#include "UserControl.h"
using namespace ButtonControls;
using namespace ButtonControls::AutonControls;
/*! ****************************************************************************************************
 @brief A libray of functions  holding all of the Display Functions Like Printing the logo on the screen addressed with DisplayControls::
 ******************************************************************************************************/
namespace DisplayControls{
/*! ****************************************************************************************************
 @brief A Function for drawing the logo on the screen NOTE:DO NOT CALL THIS THIS SHOULD BE CALLED FOR YOU
 ******************************************************************************************************/

  void Display(){
      Brain.Screen.clearScreen();
  Brain.Screen.setFillColor(white);
  Brain.Screen.setPenColor(black);
  Brain.Screen.drawRectangle(0,0,479,100);
  Brain.Screen.setCursor(2,7);
  Brain.Screen.setFont(propL);
  Brain.Screen.setPenColor(black);
  Brain.Screen.print("4     2     3     3     X");
    Brain.Screen.setFont(propM);
  Brain.Screen.setCursor(1,15);
  Brain.Screen.print("MainEngine2");
  Brain.Screen.setCursor(4,12);
  Brain.Screen.print("The Unknowns(The Unthinkable)");
  Brain.Screen.setFillColor(red);
       Brain.Screen.drawRectangle(0,1,70,30);
    Brain.Screen.drawRectangle(0,70,70,30);
    Brain.Screen.drawRectangle(409,0,70,30);
        Brain.Screen.drawRectangle(409,70,70,30);
        Brain.Screen.setFont(monoM);
        Brain.Screen.setFillColor(white);
        Brain.Screen.setCursor(5,16);
        Brain.Screen.print("Brain Ouput:");
  }
  /*! ****************************************************************************************************
 @brief A Function that displayed the high contrast of the Display funcion 
 ******************************************************************************************************/
  void DisplayInverse(){
    Brain.Screen.clearScreen();
  Brain.Screen.setFillColor(black);
  Brain.Screen.setPenColor(white);
  Brain.Screen.drawRectangle(0,0,479,100);
  Brain.Screen.setCursor(2,7);
  Brain.Screen.setFont(propL);
  Brain.Screen.setPenColor(white);
  Brain.Screen.print("4     2     3     3     X");
    Brain.Screen.setFont(propM);
  Brain.Screen.setCursor(1,15);
  Brain.Screen.print("MatchesEngine2");
  Brain.Screen.setCursor(4,12);
  Brain.Screen.print("The Unknowns(The Unthinkable)");
  Brain.Screen.setFillColor(blue);
  Brain.Screen.drawRectangle(0,1,7,30);
    Brain.Screen.drawRectangle(0,70,70,30);
    Brain.Screen.drawRectangle(1,0,70,30);
        Brain.Screen.drawRectangle(409,70,70,30);
        Brain.Screen.setFont(monoM);
        Brain.Screen.setFillColor(black);
        Brain.Screen.setCursor(5,16);
        Brain.Screen.print("Brain Ouput:");
  }
  /*! ****************************************************************************************************
 @brief Flashes the logo from high contrast to no contrast
 ******************************************************************************************************/
  void DisplayFlash(){
    Display();
     while (true){
       task::sleep(50);
       Display();
       task::sleep(50);
       DisplayInverse();
     }
  }
  /*! ****************************************************************************************************
 @brief A function for displaying output and the logo NOTE: DO NOT CALL THIS THIS SHOULD BE CALLED FOR YOU
 ******************************************************************************************************/
  void DisplayMain(){
  Display();
  Brain.Screen.setFillColor(black);
  Brain.Screen.setFont(monoS);
  Brain.Screen.setPenColor(white);
  Brain.Screen.setPenWidth(10);
  while(true && ShooterFunctions::TerminateDisplay == false){
    Brain.Screen.setCursor(8,1);
    Brain.Screen.clearLine();
    Brain.Screen.print("Intake Spinning Power:");
    Brain.Screen.print(ButtonControls::IntakeFunctions::SpinningPower);
    Brain.Screen.setCursor(
      9, 1);
      Brain.Screen.clearLine();
      Brain.Screen.print("Shooting Power:");
    Brain.Screen.print(ButtonControls::ShooterFunctions::ShootingPower);
    Brain.Screen.setCursor(10, 1);
    Brain.Screen.clearLine();
    Brain.Screen.print("Selected Auton:");
    Brain.Screen.print(ButtonControls::AutonControls::AutonStrings[ButtonControls::AutonControls::selectedauton]);
    Brain.Screen.setCursor(11, 1);
    Brain.Screen.clearLine();
    Brain.Screen.print("X:");
    Brain.Screen.print(Odometry::xPos);

    Brain.Screen.print(" Y:");
    Brain.Screen.print(Odometry::yPos);
     Brain.Screen.setCursor(12, 1);
    Brain.Screen.clearLine();
    Brain.Screen.print("Orientation Deg:");
    Brain.Screen.print(Odometry::Orientation::CalulatedHeadingDeg);
    Brain.Screen.setCursor(13, 1);
    Brain.Screen.clearLine();
    Brain.Screen.print("Turn Amount:");
    Brain.Screen.print(Odometry::getDesiredHeadingforRotate(0, 1, 90,0));
    Controller1.Screen.clearScreen();
    Controller1.Screen.setCursor(1,1); 
    Controller1.Screen.print("Color:");
    if(ButtonControls::ColorSpinnerFunctions::IsBlue){
    Controller1.Screen.print("Blue");
    }
    else{
      Controller1.Screen.print("Red");
    }
    Controller1.Screen.setCursor(2,1);
    Controller1.Screen.print("InSpinPower:");
    Controller1.Screen.print(ButtonControls::IntakeFunctions::SpinningPower);
      Controller1.Screen.setCursor(3,1);
    Controller1.Screen.print("ShotPower:");
    Controller1.Screen.print(ButtonControls::ShooterFunctions::ShootingPower);
    task::sleep(25);
  }
  }
}