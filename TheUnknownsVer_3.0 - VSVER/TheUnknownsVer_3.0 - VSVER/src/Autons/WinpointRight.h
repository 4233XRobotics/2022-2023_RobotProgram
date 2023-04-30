#include "WinPointLeft.h"
#include "robot-config.h"
using namespace Auton::AutonFunctions;
using namespace ButtonControls;
namespace Auton{
  namespace Autons{
        /*! ****************************************************************************************************
 @brief This makes sure that the auton ends at the right time

 ******************************************************************************************************/
      void StopAt15() {
        
              Brain.Timer.reset();
              waitUntil(Brain.Timer.time(timeUnits::sec) >= 15);
              printf("You ran out of time!"); // Tells me that we ran out of time
          
      }
          /*! ****************************************************************************************************
 @brief This is the auton function for the Right Winpoint NOTE: DO NOT CALL THIS THIS IS ALREADY CALLED IN THE MAIN.CPP

 ******************************************************************************************************/
    void WinPointRight(){
      Brain.Timer.reset();
        thread uwu(IntakeFunctions::StartIntake);
     double PastShooterPower = ShootingPower;
     
       old_Drive(19,150);
      task::sleep(500);
      SpinningPower = 75;
      turnToHeadingDeg(29);
task::sleep(1000);
       old_Drive(2, 100); 
      thread uwu2(IntakeFunctions::StartIntake);
      ShootingPower = 88;
      Shoot();
      task::sleep(1000);
      SpinningPower = -75;
      IntakeFunctions::StartIntake();
         Indexer3498348923.setVelocity(190,velocityUnits::rpm);
      Indexer3498348923.spinFor(reverse, 1, rev);
      ChangeShooterPower_While_Running(90);
      task::sleep(750);   
         Indexer3498348923.spinFor(reverse, 1, rev);
      task::sleep(750);
               Indexer3498348923.spinFor(reverse, 1, rev);
      task::sleep(100);
      STOPShoot();
     turnToHeadingDeg(330);
           old_Drive(21,150,reverse);
     


           old_Turn(true, 18);

          LF.spin(reverse, 40, percent);

          LR.spin(reverse, 40, percent);

          RF.spin(reverse, 40, percent);
          RR.spin(reverse, 40, percent);


  ColorSpinnerMainFunction();
          ButtonControls::stopallmotors();
          ShootingPower = PastShooterPower;
          SpinningPower = 75;
          IntakeFunctions::StartIntake();
      /*
     thread uwu(IntakeFunctions::StartIntake);
     double PastShooterPower = ShootingPower;
     
       old_Drive(19,150);
      task::sleep(500);
      SpinningPower = 75;
       old_Turn(true,14.8);
task::sleep(1000);
       old_Drive(2, 150); 
      thread uwu2(IntakeFunctions::StartIntake);
      ShootingPower = 83.5;
      Shoot();
      task::sleep(1000);
      SpinningPower = -75;
      IntakeFunctions::StartIntake();
         Indexer3498348923.setVelocity(190,velocityUnits::rpm);
      Indexer3498348923.spinFor(reverse, 1, rev);
      task::sleep(750);   
         Indexer3498348923.spinFor(reverse, 1, rev);
      task::sleep(750);
               Indexer3498348923.spinFor(reverse, 1, rev);
      task::sleep(100);
      STOPShoot();
       old_Turn(false, 330, 50);
           old_Drive(21,150,reverse);
     


           old_Turn(true, 18);

          LF.spin(reverse, 40, percent);

          LR.spin(reverse, 40, percent);

          RF.spin(reverse, 40, percent);
          RR.spin(reverse, 40, percent);


  ColorSpinnerMainFunction();
          ButtonControls::stopallmotors();
          ShootingPower = PastShooterPower;
          SpinningPower = 75;
          IntakeFunctions::StartIntake();
*/
    // UWUds adadadada
    }
  }

}