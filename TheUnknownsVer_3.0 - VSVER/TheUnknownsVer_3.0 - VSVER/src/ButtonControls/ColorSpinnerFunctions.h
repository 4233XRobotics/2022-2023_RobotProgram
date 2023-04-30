#include "robot-config.h"
/*! ****************************************************************************************************
 @brief A Library of functions that tell the robot what to do if a button is pressed
 ******************************************************************************************************/
namespace ButtonControls{
  /*! ****************************************************************************************************
 @brief A Library of functions that control the Spinner
 ******************************************************************************************************/
 inline namespace ColorSpinnerFunctions{
           /*! ****************************************************************************************************
 @brief Defines if the user wants the robot to go for blue or red: False is red, True is blue 
 ******************************************************************************************************/
   bool IsBlue = false;
   bool Cooldown4 = false;
   /*! ****************************************************************************************************
 @brief Switches the Color from red to blue or from blue to red when called
 ******************************************************************************************************/
   void ChangeColor(){
     if (Cooldown4 == false){
     IsBlue  = !IsBlue;
       Cooldown4 = true;
     task::sleep(300);
     Cooldown4 = false;
   }
   }
   int id = 0;
/*! ****************************************************************************************************
 @brief  Spinns the roller until it is turned to blue
 @param CompetitionStart Defualtly set to true determines if the robot turns the roller until it sees red and then turns until it sees blue
 @param SkillsBack Defaulty set to false determines if the robot turns the roller backwards to fix overshoot
 ******************************************************************************************************/
   void SpinUntilBlue(bool CompetitionStart = true,bool SkillsBack = false
){ // Define Fuction
  bool Con = true; // Defining The Continue While Loop Varible;
  ColorSpinner2.spin(vex::forward,60,percentUnits::pct); // Start Spin;ning the wheel
  ColorSensor.setLight(ledState::on);
  ColorSensorRight.setLight(ledState::on);
double sus = 1;
if (CompetitionStart) {
    sus = 1;
    while (Con) {
        if (ColorSensor.color() == red|| ColorSensorRight.color() == red) {
            Con = false;
        }
        if (sus >= 66.66666666666667) {
            Con = false;
        }
        task::sleep(15);
        sus = sus + 1;
       
    }
}
sus = 1;
  Con = true;
  while (Con){ // Define the while loop

    if (((ColorSensor.color() == blue)|| ColorSensorRight.color() == blue)){ // Check if the color of the sensor is blue
    task::sleep(100);

   Con = false; // Stops the while loop
    ColorSpinner2.stop(); // Stops The motor
    if(SkillsBack){
ColorSpinner2.setVelocity(60, percentUnits::pct);
   ColorSpinner2.spinFor(-.2,rotationUnits::rev);
    }
    
    }

  

  
 if (sus >= 150){  ColorSpinner2.stop();
    Con = false;
  }
  vex::task::sleep(20); // A Small Wait to save resoures 
  sus  = sus+1; 
  }
ColorSpinner2.stop();
}
    /*! ****************************************************************************************************
 @brief  Spinns the roller until it is turned to red
 @param CompetitionStart Defualtly set to true determines if the robot turns the roller until it sees blue and then turns until it sees red
 @param SkillsBack Defaulty set to false determines if the rbot turns the roller backwards to fix overshoot
 ******************************************************************************************************/
void SpinUntilRed( bool CompetitionStart = true,bool SkillsBack = false
){  
bool Con = true; // Defining The Continue While Loop Varible
    ColorSpinner2.setStopping(hold);
ColorSpinner2.spin(vex::forward,60,percentUnits::pct); // Start Spin;ning the wheel
double sus = 1;
if (CompetitionStart) {
    while (Con == true) {
        if ((ColorSensor.color() == blue) || ColorSensorRight.color() == blue) {
            Con = false;
        }
        if (sus >= 66.66666666666667) {
            Con = false;
        }
        task::sleep(15);
        sus = sus + 1;
    }
}

  Con = true;
  sus = 1;
  while (Con){ // Define the while loopdsadsadasdada


    if ((ColorSensor.color() == red|| ColorSensorRight.color() == red) ){ // Check if the color of the sensor is blue
      
        task::sleep(100);
      
   Controller1.rumble("___");
   Con = false; // Stops the while loop
    ColorSpinner2.stop(); // Stops The motor
    if(SkillsBack){
ColorSpinner2.setVelocity(60, percentUnits::pct);
   ColorSpinner2.spinFor(-.2,rotationUnits::rev);
    }
    
  }


  
    if (sus >= 150) {
        Con = false;
 }
  vex::task::sleep(20); // A Small Wait to save resoures 
  sus  = sus+1; 
  }

ColorSpinner2.stop();
}
/*! ****************************************************************************************************
 @brief  Stops the spinner when called
 ******************************************************************************************************/
void STOPSpinner(){
  ColorSpinner2.stop();
}
/*! ****************************************************************************************************
 @brief The main function for driving if the user has selected blue then it turns the roller to blue if red it turns it to red
 ******************************************************************************************************/
void ColorSpinnerMainFunction(){
  if (IsBlue){
    SpinUntilBlue();
  }else{
    SpinUntilRed();
  }
}
 }
}