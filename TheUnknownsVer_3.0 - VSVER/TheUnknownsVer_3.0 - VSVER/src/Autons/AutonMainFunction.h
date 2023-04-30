
#include "Autons.h"
using namespace ButtonControls;
using namespace ButtonControls::AutonControls;
 /*! ****************************************************************************************************
 @brief A library of functions for autonomous and programming skills
 ******************************************************************************************************/
namespace Auton{
   /*! ****************************************************************************************************
 @brief The main function for the autonomous event NOTE: DO NOT CALL THIS FUNCTION IT CALLS IT FOR YOU IN MAIN.CPP
 ******************************************************************************************************/
  void autonomous(){
    Brain.resetTimer();
    if(ButtonControls::AutonControls::selectedauton == 0){
     Auton::Autons::LeftSpin();
    }
    else{
      if(ButtonControls::AutonControls::selectedauton == 1){
        Auton::Autons::WinPointLeft();
      }
      else{
        if(ButtonControls::AutonControls::selectedauton == 2){
          Auton::Autons::WinPointRight();
        }
        else {
            if (ButtonControls::AutonControls::selectedauton == 3)
            {
                Auton::Autons::Skills();
            }
            else {
                if (ButtonControls::AutonControls::selectedauton == 5) {
                    Auton::Autons::TestOdom();
                }
                else{
                  if(ButtonControls::AutonControls::selectedauton == 6){
                    Auton::Autons::Backupskills();
                  }
                  else if(ButtonControls::AutonControls::selectedauton ==7){
                    Auton::Autons::WinPointLeftAccurate();
                  }
                }
            }
        }
      }
    }
  }
}