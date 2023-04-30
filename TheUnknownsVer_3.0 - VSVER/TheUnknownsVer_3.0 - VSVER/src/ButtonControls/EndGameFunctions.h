#include "AutonFunctions.h"
#include "robot-config.h"
using namespace ButtonControls::AutonControls;
/*! ****************************************************************************************************
 @brief A Library of functions that tell the robot what to do if a button is pressed
 ******************************************************************************************************/
namespace ButtonControls{
  /*! ****************************************************************************************************
 @brief A Library of functions that manage controlling the nedgame
 ******************************************************************************************************/
   inline namespace EndgameControls{
     bool dijoasdijpiucaosHkjlfdsjkfjkldsjfsdhfskjfsjkfkjd = false;
    /*! ****************************************************************************************************
 @brief This function releases the endgame and adds a cooldown to the endgame using the Brain.Timer called when ButtonRight is presssed
 ******************************************************************************************************/
    void endgame(){
      if (AutonControls::selectedauton == 3){
       if(Brain.Timer.time(timeUnits::sec) >= 49 && !dijoasdijpiucaosHkjlfdsjkfjkldsjfsdhfskjfsjkfkjd){
          Pnematics.set(true);
           
          SmallEndgame.set(true);
        dijoasdijpiucaosHkjlfdsjkfjkldsjfsdhfskjfsjkfkjd = true;
          task::sleep(3000);
              Pnematics.set(false);
              SmallEndgame.set(false);
              dijoasdijpiucaosHkjlfdsjkfjkldsjfsdhfskjfsjkfkjd = false;
       } 
      }
      else{
          if (AutonControls::selectedauton == 4) {
              if (!dijoasdijpiucaosHkjlfdsjkfjkldsjfsdhfskjfsjkfkjd) {
                      Pnematics.set(true);
           
          SmallEndgame.set(true);
        dijoasdijpiucaosHkjlfdsjkfjkldsjfsdhfskjfsjkfkjd = true;
          task::sleep(3000);
              Pnematics.set(false);
              SmallEndgame.set(false);
              dijoasdijpiucaosHkjlfdsjkfjkldsjfsdhfskjfsjkfkjd = false;
              }
          }
          else {
              if (Brain.Timer.time(timeUnits::sec) >= 109 && !dijoasdijpiucaosHkjlfdsjkfjkldsjfsdhfskjfsjkfkjd) {
               Pnematics.set(true);
           
          SmallEndgame.set(true);
        dijoasdijpiucaosHkjlfdsjkfjkldsjfsdhfskjfsjkfkjd = true;
          task::sleep(3000);
              Pnematics.set(false);
              SmallEndgame.set(false);
              dijoasdijpiucaosHkjlfdsjkfjkldsjfsdhfskjfsjkfkjd = false;
              }
          }
      }
    }
   }
}