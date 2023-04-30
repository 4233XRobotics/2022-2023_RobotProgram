#include "robot-config.h"
#include "ButtonControls.h"
using namespace ButtonControls;
/*! ****************************************************************************************************
 @brief A library of functions for activly controlling the robot
 ******************************************************************************************************/
namespace UserControl{
/*! ****************************************************************************************************
 @brief A Function for the usercontrol event NOTE: DO NOT CALL THIS FUNCTION IT SHOULD BE CALLED FOR YOU IN THE MAIN.CPP
 ******************************************************************************************************/
    void usercontrol(){
  double LeftV = 0;
  double RightV = 0;
  double PreviousLeftV = 0;
  double PreviousRightV = 0;
  CoolDownyumyum = false;
  ButtonControls::IntakeFunctions::Cooldown1 = false;
  Shooting = false;
  Spinning = false;
  ButtonControls::IntakeFunctions::Cooldown2 = false;
  ShootingPower = 75;
  SpinningPower = 85;
  while(true){
    Controller1.ButtonLeft.pressed(ButtonControls::IntakeFunctions::StartIntake);
    Controller1.ButtonRight.pressed(ButtonControls::EndgameControls::endgame);
    Controller1.ButtonR1.pressed(ButtonControls::AutonControls::SwitchAuton);
        Controller1.ButtonR1.pressed(ButtonControls::AutonControls::SwitchAuton);
            Controller1.ButtonR2.pressed(ButtonControls::IntakeFunctions::FixDisk);
    Controller1.ButtonUp.pressed(ButtonControls::IntakeFunctions::addpower);
    Controller1.ButtonDown.pressed(ButtonControls::ColorSpinnerFunctions::ChangeColor);
    Controller1.ButtonA.pressed(ButtonControls::ShooterFunctions::Shoot);
    Controller1.ButtonB.pressed(ButtonControls::ShooterFunctions::STOPShoot);
    Controller1.ButtonL1.pressed(ButtonControls::ShooterFunctions::AddPower);
    Controller1.ButtonL2.pressed(ButtonControls::ShooterFunctions::RemovePower);
    Controller1.ButtonX.pressed(ButtonControls::ColorSpinnerFunctions::ColorSpinnerMainFunction);
    Controller1.ButtonY.pressed(ButtonControls::ColorSpinnerFunctions::STOPSpinner);
    if(Controller1.Axis2.value() >= 80){
      IndexerHold.broadcast();
    }
    if(Controller1.Axis1.value() >=80){
      EnableBlooper = false;
    }
    if(Controller1.Axis1.value() <=-80){
      EnableBlooper = true;
    }
    double moveamount = Controller1.Axis3.position(percentUnits::pct);  // Delcares the Left Vertical axis on the joystick
    double turnamount = Controller1.Axis4.position(percentUnits::pct); // Delcares the Left Horizational axis on the joystick
   LeftV = ((moveamount/2) + (turnamount/2))/1.25; // Delares the LeftV by calulating it using the joystick
    RightV = ((moveamount/2) - (turnamount/2))/1.25;// Delares the RightV by calulating it using the joystick
    if (PreviousLeftV == 0 && PreviousRightV == 0){ // Checks if it is  stopped 
  LF.spin(directionType::fwd,LeftV,percentUnits::pct); // Spins the Left Front Motor with the calulated Velocity
       LR.spin(directionType::fwd,LeftV,percentUnits::pct); // Spins the Left Rear Motor with the calulated Velocity
       RF.spin(directionType::fwd,RightV,percentUnits::pct);// Spins the Right Front Motor with the calulated Velocity
       RR.spin(directionType::fwd,RightV,percentUnits::pct);// Spins the Right Rear Motor with the calulated Velocity
    }else{ // Else 
      LF.spin(directionType::fwd,(LeftV + PreviousLeftV) * 0.75 ,percentUnits::pct); // Caluates The Final Velocity  by Adding the left velocity with the previous and multipling it by 3 fourths
       LR.spin(directionType::fwd,(LeftV + PreviousLeftV) * 0.75,percentUnits::pct);// Caluates The Final Velocity  by Adding the left velocity with the previous and multipling it by 3 fourths
       RF.spin(directionType::fwd,(RightV +  PreviousRightV)* 0.75,percentUnits::pct);// Caluates The Final Velocity  by Adding the right velocity with the previous and multipling it by 3 fourths
       RR.spin(directionType::fwd,(RightV +  PreviousRightV)* 0.75,percentUnits::pct);}// Caluates The Final Velocity  by Adding the right velocity with the previous and multipling it by 3 fourths

    if (PreviousLeftV >= 0.0000000000000001 || PreviousLeftV <= -0.00000000000001){ // If the previous state was stopped
    LeftV = (LeftV + PreviousLeftV) * 0.75; // Delcares The Velocity
    }
     if (PreviousRightV >= 0.0000000000000001 || PreviousRightV <= -0.00000000000001){// If the previous state was stopped
    RightV =(RightV +  PreviousRightV) * 0.75;// Delcares The Velocity
      }
    
   PreviousLeftV = LeftV; // Sets the LeftV to the previous LeftV
   PreviousRightV = RightV; // Sets the RightV the previous RightV
   if (PreviousLeftV >= 0.000000000000000000000000000001){ // Checks If The Left V is greater than 0
     PreviousLeftV = PreviousLeftV - 0.09; // Decreases the Velocity
   }
   else{
     if (PreviousLeftV <= -0.000000000000000000000000000001){ // Checks If The Left V is less than 0
          PreviousLeftV = PreviousLeftV +0.09; // Decreases the Velocity
     }
   }
if (PreviousRightV >= 0.000000000000000000000000000001){ // Checks If The Right V is greater than 0 
     PreviousRightV = PreviousRightV - 0.09;// Decreases the Velocity
   }
   else{
     if (PreviousRightV <= -0.000000000000000000000000000001){// Checks If The Right V is less than 0 
        PreviousRightV = PreviousRightV+0.09;// Decreases the Velocity
     }
   }
    wait(25,msec); // A Small wait to save resources

  }

  }
}