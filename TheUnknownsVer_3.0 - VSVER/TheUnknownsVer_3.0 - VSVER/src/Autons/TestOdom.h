#include "../Autons/Skills.h"
#include "robot-config.h"
#include <string.h>
using namespace Auton::AutonFunctions;
using namespace ButtonControls;
namespace Auton{
  
  namespace Autons{
             /*! ****************************************************************************************************
 @brief This is the auton function for a tutortial on how to code NOTE: DO NOT CALL THIS THIS IS ALREADY CALLED IN THE MAIN.CPP

 ******************************************************************************************************/
void TestOdom(){
  task::sleep(5000);
turnToHeadingDeg(180);
RemoveHold();
}
    void TestOdom2(){
      
      /* Drive Forward */
      // Distance in inches
      // velocity is in RPM
      old_Drive(10,150);
      /* Turn */
      // Left Heading : 360-how many degrees left9
      // Right Heading : how many degrees right
      old_Turn(false, 270,50);
      /* Intake */
      // Forward 999999999
      IntakeFunctions::StartIntake();
      // stop
      IntakeFunctions::StartIntake();

      // Reverse
      IntakeFunctions::addpower();

      //; stop      Intake.stop();
      /* Shooter */
      ShootingPower = 75;
      Shoot();
      wait(2,sec);
      Shoot();
      wait(375,msec);
      // Changing Power
      ShootingPower = 85;
            FlywheelMainMotor.spin(vex::forward, ((12.5 * ShootingPower) * 0.01), voltageUnits::volt);
            Shoot();
      wait(375,msec);
            Shoot();
      wait(375,msec);
      STOPShoot();
      /* Spinner */
      // Args
     // Competition Start 
      
      // Spin Back

      LF.spin(reverse,30,percent);
      LR.spin(reverse,30,percent);
      if(IsBlue){
       SpinUntilBlue(true);
      }
      else{
       SpinUntilRed(true);
      }
      stopallmotors();
      IsBlue = false;




    } 
  }
}