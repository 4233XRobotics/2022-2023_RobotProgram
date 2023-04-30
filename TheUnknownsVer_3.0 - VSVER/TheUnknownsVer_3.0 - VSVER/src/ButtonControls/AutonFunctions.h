#include "robot-config.h"
#include "vex.h"

using namespace vex;
using namespace std;
/*! ****************************************************************************************************
 @brief A Library of functions that tell the robot what to do if a button is pressed
 ******************************************************************************************************/
namespace ButtonControls{
  /*! ****************************************************************************************************
 @brief A Library of functions that select the auton NOTE: THIS IS CALLED IN USERCONTROL.h dont call it 
 ******************************************************************************************************/
  inline namespace AutonControls{
     int selectedauton = 0; 
  const char* AutonStrings[8] = {"Left Spin","Left WinPoint","Right WinPoint","Skills","No wait endgame ","Test Odom","Backup Skills","LeftWinpointAcc"};
  int numberofautons = 8;

    bool Cooldown54 = false;
    /*! ****************************************************************************************************
 @brief A function that swithes the auton -> in the index called when R1 is pressed
 ******************************************************************************************************/
     void SwitchAuton(){
         if(Cooldown54 == false){
           if((selectedauton +1) == numberofautons){
             selectedauton = 0;
             Cooldown54 = true;
             task::sleep(300);
             Cooldown54 = false;
           }
           else{
             selectedauton = selectedauton + 1;
             Cooldown54 = true;
             task::sleep(300);
             Cooldown54 = false;
           }
         }
     }
  



  }
}