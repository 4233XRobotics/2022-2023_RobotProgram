#include "robot-config.h"
 using namespace vex;
 /*! ****************************************************************************************************
 @brief A Library of functions that tell the robot what to do if a button is pressed
 ******************************************************************************************************/
 namespace ButtonControls{
  /*! ****************************************************************************************************
 @brief A Library of functions that control the intake
 ******************************************************************************************************/
   inline namespace IntakeFunctions{
     bool Cooldown1 = false;
              /*! ****************************************************************************************************
 @brief The Speed that the Intake spins at when the StartIntake and addpower functions are called 
 @attention DO NOT SET THIS BELOW 0 OR ABOVE 100 IT COULD BURN UP THE MOTOR
 ******************************************************************************************************/
     double SpinningPower = 85;
bool Spinning = false;
bool Forward = false;
/*! ****************************************************************************************************
 @brief A function that starts the intake if it is stoped and starts the intake if it is spinning
 @attention if you want to change the Intake power you use SpinningPower = desiredpower and then call this function
 ******************************************************************************************************/
void StartIntake(){
  if(!Spinning && !Cooldown1){
    Spinning = true;
  Intake.spin(reverse,SpinningPower,percent);
  Cooldown1 = true;
  Forward = true;
  task::sleep(1000);
  Cooldown1 = false;
  }
  else{
    if(!Cooldown1 &&!Forward){
          Spinning = true;
  Intake.spin(reverse,SpinningPower,percent);
  Cooldown1 = true;
  Forward = true;
  task::sleep(1000);
  Cooldown1 = false;
    }
    else{
    if(!Cooldown1){
    Intake.stop(coast);
    Forward = false;
    Spinning = false;
       Cooldown1 = true;
  task::sleep(1000);
  Cooldown1 = false;
    }
  }
}
}


bool Cooldown2 = false;
  /*! ****************************************************************************************************
 @brief A function that runs the intake on reverse
 ******************************************************************************************************/
void addpower(){

  if(!Cooldown2 && !Spinning){
      Intake.spin(vex::forward, SpinningPower, percent);
    Cooldown2 = true;
    Forward = false;
    task::sleep(300);
    Cooldown2 = false;
  }
  else{
    if(!Cooldown2 && Forward){
    Intake.spin(vex::forward, SpinningPower, percent);
    Cooldown2 = true;
    Forward = false;
    task::sleep(300);
    Cooldown2 = false;
    }
    else{
      if(!Cooldown2){
         Intake.stop(coast);
    Spinning = false;
    Forward = false;
       Cooldown2= true;
  task::sleep(1000);
  Cooldown2 = false;
      }
    }
  }
  }

bool Cooldown3 = false;
void removepower(){
    if((SpinningPower - 10) <= -110 && !Cooldown3){

   
 }
 else{
  if(Cooldown3 == false){
    SpinningPower = SpinningPower-10;
      Cooldown3 = true;
    task::sleep(300);
    Cooldown3 = false;
  }
 }
}
bool CoolDownyumyum = false;
  /*! ****************************************************************************************************
 @brief A function that fixes the disk if it is stuck in the intake
 ******************************************************************************************************/
void FixDisk(){
  if(!CoolDownyumyum){
  CoolDownyumyum = true;
  Intake.spin(vex::forward,SpinningPower,percent);
  task::sleep(750);
  Intake.spin(reverse,SpinningPower,percent);
  
    if(!Spinning){
          task::sleep(750);
    Intake.stop();
    }
    else{
      if(!Forward){
          Intake.spin(vex::forward,SpinningPower,percent);
      }
    }
    CoolDownyumyum = false;
  }
}
   }
 }