#include "LeftSpin.h"
#include "robot-config.h"
using namespace Auton::AutonFunctions;
using namespace ButtonControls;
namespace Auton{

  namespace Autons{
    /*! ****************************************************************************************************
m @brief This is the auton function for the Left Winpoint NOTE: DO NOT CALL THIS THIS IS ALREADY CALLED IN THE MAIN.CPP

 ******************************************************************************************************/
    void WinPointLeft(){
        
    old_Drive(2.25,75);
    ShootingPower = 100;
    Shoot();
    wait(2,sec);
        Indexer3498348923.setVelocity(200,velocityUnits::rpm);
        Indexer3498348923.setBrake(hold);
      Indexer3498348923.spinFor(reverse, 1, rev);
    wait(750,msec);
    ChangeShooterPower_While_Running(100);
   Indexer3498348923.setVelocity(200,velocityUnits::rpm);
        Indexer3498348923.setBrake(hold);
      Indexer3498348923.spinFor(reverse, 1, rev);
    wait(300,msec);
  

  ChangeShooterPower_While_Running(80);
        LF.spin(reverse,40,percent);
      LR.stop(coast);
       RR.stop(coast);
      RF.spin(reverse,40,percent);
     ColorSpinnerMainFunction();
     stopallmotors();
     old_Drive(5, 150);
     SpinningPower = 95;
     thread e(StartIntake);
   turnToHeadingDeg(51.75,20,22);

     old_Drive(36, 120);
    ChangeShooterPower_While_Running(85);
       
task::sleep(200);
    
      turnToHeadingDeg(342.5);
 old_Drive(3,100);
task::sleep(200);
     thread f(IntakeFunctions::addpower);
     task::sleep(100);
     Shoot();
    wait(750,msec);
        ChangeShooterPower_While_Running(90);
    Shoot();
    wait(750,msec);
      Shoot();
    wait(750,msec);
    STOPShoot();
    SpinningPower = 85;

 /*  
  thread (StopAt15);
    old_Drive(2.25,75);
    old_Turn(false,359,18,0.5);
    ShootingPower = 100;
    Shoot();
    wait(2,sec);
    Shoot();
    wait(750,msec);
    ChangeShooterPower_While_Running(95);
    Shoot();
    wait(300,msec);
      old_Turn(true,1.5,18);
    STOPShoot();
        LF.spin(reverse,40,percent);
      LR.stop(coast);
       RR.stop(coast);
      RF.spin(reverse,40,percent);
     ColorSpinnerMainFunction();
     stopallmotors();
     old_Drive(3, 150);
     task::sleep(200);
     SpinningPower = 95;
     thread e(StartIntake);
     old_Turn(true,25,50);
     task::sleep(200);
     old_Drive(20, 150);
     task::sleep(200);
     ShootingPower = 90;
       Shoot();
     old_Drive(11, 40);
    
       old_Turn(false, 298.2,50);
 
task::sleep(200);
     thread f(IntakeFunctions::addpower);
    Shoot();
    wait(750,msec);
    Shoot();
    wait(750,msec);
    Shoot();
    wait(750,msec);
    STOPShoot();
    SpinningPower = 85;*/
    }
  } 
}