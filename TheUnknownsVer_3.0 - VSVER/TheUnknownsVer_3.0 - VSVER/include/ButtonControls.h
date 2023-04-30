// This is a namespace file that compiles all of these files into a namespace named "ButtonControls"
#include "../src/ButtonControls/ColorSpinnerFunctions.h"
#include "../src/ButtonControls/ShooterFunctions.h"
#include "../src/ButtonControls/IntakeFunctions.h"
#include "../src/ButtonControls/EndGameFunctions.h"
namespace ButtonControls{
   /*! ****************************************************************************************************
 @brief A function that stops all mototers on the drive train
 @param type This is the type of brake it stops the motors with
 choices:
 coast
 brake and 
 hold
 ******************************************************************************************************/
  void stopallmotors(brakeType type = coast){
    LF.stop(type);
    LR.stop(type);
    RF.stop(type);
    RR.stop(type);
  }
}
