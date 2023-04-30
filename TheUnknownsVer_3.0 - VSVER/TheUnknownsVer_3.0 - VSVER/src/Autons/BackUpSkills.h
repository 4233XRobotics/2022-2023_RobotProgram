#include "TestOdom.h"
#include "robot-config.h"
#include <string.h>
using namespace Auton::AutonFunctions;
using namespace ButtonControls;
namespace Auton{
  namespace Autons{
                 /*! ****************************************************************************************************
 @brief This is the backup skills auton just in case the 152 point scoring skills does not work

 ******************************************************************************************************/
    void Backupskills(){
       LF.spin(reverse, 30, percent);
         
            ColorSpinnerFunctions::SpinUntilRed(false);
            stopallmotors();
            old_Drive(3, 150);
            old_Turn(false, 310,50);
            IntakeFunctions::StartIntake();
            old_Drive(6.5, 100,fwd,hold);

            old_Turn(false, 184,40);
            
                       thread d(IntakeFunctions::StartIntake);
            LF.spin(reverse,30,percent);
            LR.stop(coast);
            RF.spin(reverse, 30, percent);
         RR.stop(coast);
             task::sleep(300);
            ColorSpinnerFunctions::SpinUntilRed(false,true);
            stopallmotors();
                  /* Time to turn and shoot at the goal */
            old_Drive(3,150);
            old_Turn(false, 300,50);
                   ShootingPower = 73;
                thread e(Shoot);
            old_Drive(44, 150);

            old_Turn(true,6.5,40);
   
            Shoot();
            task::sleep(350);
                Shoot();
            task::sleep(450);
               Shoot();
            task::sleep(350);
   old_Turn(false,358,25);
            
            old_Drive(40.5, 150,reverse);
            old_Turn(true,35,50);
            selectedauton = 4;
            endgame();
            old_Drive(6,150,reverse);
    }
  }
}