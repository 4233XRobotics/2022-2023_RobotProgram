#include "robot-config.h"
#include "odometry.h"
#include <stdexcept>
using namespace vex;
 /*! ****************************************************************************************************
 @brief A Library of functions that tell the robot what to do if a button is pressed
 ******************************************************************************************************/
namespace ButtonControls{
   /*! ****************************************************************************************************
 @brief A Library of functions that control the Shooter
 ******************************************************************************************************/
  inline namespace ShooterFunctions{
    bool Shooting = false;
      /*! ****************************************************************************************************
 @brief The speed that the flywheel spins at in percent
 @attention DO NOT SET THIS BELOW 0 OR ABOVE 100 IT COULD BURN UP THE MOTOR
 ******************************************************************************************************/
    double ShootingPower = 90;
bool Cooldown1 = false;
 /*! ****************************************************************************************************
 @brief A function that adds power to the shooter in increments of 10 or 5
 @attention NOTE:I would not recommend using this function to set the shooter power instead i would use
 ShootingPower = desiredshootingpower and be done with it
 ******************************************************************************************************/
void  AddPower(){
 if((ShootingPower+ 10) >= 110 && !Cooldown1){
   
 }
 else{
  if(Cooldown1== false && Controller1.ButtonA.pressing() == false){
      if(ShootingPower == 75 || ShootingPower == 70 || ShootingPower == 65){
          ShootingPower = ShootingPower + 5;
          if (Shooting) {
              FlywheelMainMotor.spin(vex::forward, ((12.5 * ShootingPower) * 0.01), voltageUnits::volt);
          }
          Cooldown1 = true;
          vex::task::sleep(300);
          Cooldown1 = false;
  
      }
      else {
          ShootingPower = ShootingPower + 10;
          if (Shooting) {
              FlywheelMainMotor.spin(vex::forward, ((12.5 * ShootingPower) * 0.01), voltageUnits::volt);
          }
          Cooldown1 = true;
          vex::task::sleep(300);
          Cooldown1 = false;
      }
  }
 }
}
bool Cooldown2 = false;
 /*! ****************************************************************************************************
 @brief A function that removes power to the shooter in increments of 10 or 5
 @attention NOTE:I would not recommend using this function to set the shooter power instead i would use
 ShootingPower = desiredshootingpower and be done with it
 ******************************************************************************************************/
void RemovePower(){
    if((ShootingPower - 5) <= 60 && !Cooldown2){

   
 }
 else{
  if(Cooldown2 == false){
      if (ShootingPower == 80 || ShootingPower == 75 ||ShootingPower == 70) {
          ShootingPower = ShootingPower - 5;
          if (Shooting) {
              FlywheelMainMotor.spin(vex::forward, ((12.5 * ShootingPower) * 0.01), voltageUnits::volt);
          }
          Cooldown2 = true;
          vex::task::sleep(300);
          Cooldown2 = false;
      }
      else {
          ShootingPower = ShootingPower - 10;
          if (Shooting) {
              FlywheelMainMotor.spin(vex::forward, ((12.5 * ShootingPower) * 0.01), voltageUnits::volt);
          }
          Cooldown2 = true;
          vex::task::sleep(300);
          Cooldown2 = false;
      }
  }
 }
}

bool TerminateDisplay = false;
void CreateError(){
      TerminateDisplay = true;
      LF.stop();
      LR.stop();
      RF.stop();
      RR.stop();
      FlywheelMainMotor.stop();
      ColorSpinner2.stop();
      Indexer3498348923.stop();
      Intake.stop();
  Brain.Screen.setFillColor(red);
  Brain.Screen.drawRectangle(0,0,500,500);
}
 /*! ****************************************************************************************************
 @brief A function that makes changing the shooterpower while the flywheel is on easy!
 @param desiredPower the Desired power of the shooter that you want to be at 
 ******************************************************************************************************/
void ChangeShooterPower_While_Running(double desiredPower){
  if (desiredPower >= 101){
    CreateError();
    task::sleep(500);
    Brain.Screen.setPenColor(black);
                    Brain.Screen.setCursor(7,1);
    Brain.Screen.print("ShooterPower Error  : Changed the shooter power to a number ");
    Brain.Screen.print("greater than 100 when calling ");
     Brain.Screen.setCursor(8,1);
        Brain.Screen.print("ChangeShooterPower_While_Running");
    wait(.5,sec);
    throw std::invalid_argument( "ShooterPower Error  : Changed the shooter power to a number greater than 100 when calling ChangeShooterPower_While_Running" );
  }
   if (desiredPower <0){
    
     CreateError();
     wait(0.5,sec);
         Brain.Screen.setPenColor(black);
         Brain.Screen.setCursor(6,1);
    Brain.Screen.print("ShooterPower Error  : Changed the shooter power to a number ");
        Brain.Screen.setCursor(7,1);
    Brain.Screen.print("less than 0 when calling");
    Brain.Screen.setCursor(8,1);
        Brain.Screen.print("ChangeShooterPower_While_Running");
          wait(.5,sec);
    throw std::invalid_argument( "ShooterPower Error  : Changed the shooter power to a number less than 0 when calling ChangeShooterPower_While_Running" );
  }
  ShootingPower = desiredPower;
  FlywheelMainMotor.spin(vex::forward,((12.5*ShootingPower)*0.01),voltageUnits::volt);
}
bool CoolingDownYourMom = false;
 /*! ****************************************************************************************************
 @brief A function that starts the shooter if it is not started or shoots the disk
 @attention If you want to change the shooter power while it is running call ChangeShooterPower_While_Running with the desired shooterpower
 ******************************************************************************************************/
void Shoot(){
  if(!Shooting && !CoolingDownYourMom){
    CoolingDownYourMom = true;
   Shooting = true;
   FlywheelMainMotor.spin(vex::forward,((12.5*ShootingPower)*0.01),voltageUnits::volt);
   // Now we are cool
   task::sleep(1000);
   CoolingDownYourMom = false;
  }
  else{
    if(!CoolingDownYourMom && !Controller1.ButtonL1.pressing()){
      CoolingDownYourMom = true;
      Indexer3498348923.setVelocity(180,velocityUnits::rpm);
      Indexer3498348923.spinFor(reverse, 1, rev);
      task::sleep(50);
      CoolingDownYourMom = false;
    }
  }
}
 /*! ****************************************************************************************************
 @brief Stops the shooter
 
 ******************************************************************************************************/
void STOPShoot(){
  if (Shooting){
    Shooting = false;
    FlywheelMainMotor.stop(coast);
  }
}
bool  CooldownHold = false;
bool EnableBlooper = true;
 /*! ****************************************************************************************************
 @brief This Monitors the Blooper and enables it if the power is less than 8o percent
 @attention DO NOT CALL THIS FUNCTION IT IS ALL READY CALLED FOR YOU IN THE MAIN.CPP
 ******************************************************************************************************/
void BlooperInit(){
   while(true){
    if(EnableBlooper){
    if(ShootingPower < 80){
      SmallEndgame.set(true);
    }
    else{
      SmallEndgame.set(false);
    }
    }
    else{
      SmallEndgame.set(false);
    }
    task::sleep(20);
   }
}
event IndexerHold = event();
void d(){
  if(EnableBlooper == false){
  Indexer3498348923.setStopping(coast);
      Indexer3498348923.spinFor(reverse, 1, rotationUnits::rev);
      task::sleep(200);
          Indexer3498348923.spinFor(reverse, 1, rotationUnits::rev);
      task::sleep(200);
          Indexer3498348923.spinFor(reverse, 1, rotationUnits::rev);
      task::sleep(200);
      Indexer3498348923.setStopping(hold);
  }
  else{
    double PreviousShooterPower = ShootingPower;
         Indexer3498348923.spinFor(reverse, 1, rotationUnits::rev);
        double  NShootingPower = ShootingPower+5;
        ChangeShooterPower_While_Running(NShootingPower);
        task::sleep(100);
          Indexer3498348923.spinFor(reverse, 1, rotationUnits::rev);
      NShootingPower = NShootingPower+5;
        ChangeShooterPower_While_Running(NShootingPower);
             task::sleep(100);
          Indexer3498348923.spinFor(reverse, 1, rotationUnits::rev);
        
        ChangeShooterPower_While_Running(PreviousShooterPower);
        Shooting = true;
  }
}
 /*! ***********************************
 *****************************************************************
 @brief Makes the indexer spin fast to shoot 3 disks
 @attention I DO NOT RECOMMEND USING THIS FUNCTION BECAUSE IT IS INCONSISTANT
 ******************************************************************************************************/
void IndexerHoldFunction(){
  if(!CooldownHold && Shooting){
    CooldownHold = true;
      Indexer3498348923.setVelocity(180,velocityUnits::rpm);
      double startingPosition = Indexer3498348923.position(rotationUnits::rev);
  thread d3(d);
  task::sleep(1800);
  CooldownHold = false;
  }
}
  }
}