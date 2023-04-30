#include "AutonFunctions.h"
#include "robot-config.h" 
using namespace Auton::AutonFunctions;
using namespace ButtonControls::ColorSpinnerFunctions;
using namespace ButtonControls::ShooterFunctions;
using namespace ButtonControls::IntakeFunctions;
using namespace ButtonControls;
 /*! ****************************************************************************************************
 @brief A library of functions for autonomous and programming skills
 ******************************************************************************************************/
namespace Auton{
   /*! ****************************************************************************************************
 @brief A library of autons
 ******************************************************************************************************/
  namespace Autons{
     /*! ****************************************************************************************************
 @brief The function for the LeftSpin auton 
 ******************************************************************************************************/
    void LeftSpin(){
      
      LF.spin(reverse,40,percent);
      LR.spin(reverse,40,percent);
      RF.spin(reverse,40,percent);
      RR.spin(reverse,40,percent);

if(ButtonControls::IsBlue == true){
  SpinUntilBlue();
}
else{
  SpinUntilRed();
}
     ButtonControls::stopallmotors();

    }
  }
}