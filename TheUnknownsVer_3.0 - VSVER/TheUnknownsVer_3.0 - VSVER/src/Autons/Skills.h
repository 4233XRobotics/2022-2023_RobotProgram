#include "WinpointRight.h"
#include "robot-config.h"
using namespace Auton::AutonFunctions;
using namespace ButtonControls;
namespace Auton {
    namespace Autons {
               /*! ****************************************************************************************************
 @brief This makes sure that the skills is on time
 ******************************************************************************************************/
       void TimerHeheheh() {
            waitUntil(Brain.Timer.time(sec) >= 60);
          
        }
         /*! ****************************************************************************************************
 @brief The FirstPart of skills 
 ******************************************************************************************************/

       void FirstPartofSkills(){
        EnableBlooper = false;
LF.spin(reverse, 30, percent);
         
            ColorSpinnerFunctions::SpinUntilRed(false);
            stopallmotors();
            old_Drive(2, 150);
            turnToHeadingDeg(291);
        
            IntakeFunctions::StartIntake();
            old_Drive(8, 100,fwd,hold);

            old_Turn(false, 184,40);
            
                       thread d(IntakeFunctions::StartIntake);
                                          
            LF.spin(reverse,30,percent);
            LR.stop(coast);
            RF.spin(reverse, 30, percent);
         RR.stop(coast);    
         task::sleep(1000);
            LF.spin(reverse,10,percent);
            LR.stop(coast);
            RF.spin(reverse, 10, percent);
         RR.stop(coast);
             task::sleep(300);
            ColorSpinnerFunctions::SpinUntilRed(false,true);
            stopallmotors();
                  /* Time to turn and shoot at the goal */
            old_Drive(3,150);
            turnToHeadingDeg(355);
                   ShootingPower = 75;
                thread e(Shoot);
            old_Drive(42, 150);
                        
          turnToHeadingDeg(7);
   
   
            Shoot();
            task::sleep(350);
                Shoot();
            task::sleep(450);
               Shoot();
            task::sleep(350);
            /* Get line of 3 */
            turnToHeadingDeg(0);

            old_Drive(27.5, 150,reverse);
                        thread jw(IntakeFunctions::StartIntake);
            old_Turn(true, 29.5,40); 
            task::sleep(500);
            old_Drive(16, 100); 
            task::sleep(250);
                old_Drive(16, 100); 
                         task::sleep(250);
                    old_Drive(19, 100); 
                             ChangeShooterPower_While_Running(75);
           turnToHeadingDeg(317);
            thread e7(IntakeFunctions::addpower);
            old_Drive(0.9,100);
   
            task::sleep(500);
            Shoot();
            task::sleep(375);
              Shoot();
            task::sleep(505);
              Shoot();
              IntakeFunctions::StartIntake();
            task::sleep(375);
       }
       void SecondPartSkills(){
            /* Get three disks in the middle */
        
            old_Turn(true,102,50);
        Intake.spin(reverse,SpinningPower,percent);
            old_Drive(6, 150);
            old_Turn(true, 86,40,1.5);
             
            old_Drive(22, 150);
                 ShootingPower= 75;
               FlywheelMainMotor.spin(vex::forward, ((12.5 * ShootingPower) * 0.01), voltageUnits::volt);
            old_Turn(false,320,50);
            old_Drive(11, 150);
          turnToHeadingDeg(125);
          task::sleep(100);
            IntakeFunctions::addpower();
            task::sleep(350);
               Shoot();
            task::sleep(750);
                Shoot();
            task::sleep(350);
               Shoot();
            task::sleep(350);
                 thread e(IntakeFunctions::StartIntake);
                 old_Drive(0.5,80,reverse);
            turnToHeadingDeg(45);
            task::sleep(750);
            Spinning = false;
            thread e2(IntakeFunctions::StartIntake);
            old_Drive(20,100);
            task::sleep(300);
             old_Drive(20,100);
            task::sleep(300);
             old_Drive(20,100);
            task::sleep(300);
        
            turnToHeadingDeg(183);
               turnToHeadingDeg(183);
            addpower();
            old_Drive(15, 150);
      ChangeShooterPower_While_Running(79);
                 task::sleep(350);
               Shoot();
            task::sleep(650);
                Shoot();
            task::sleep(350);
               Shoot();
            task::sleep(350);
            old_Turn(false,359,20);
            old_Drive(24,150,reverse);
            old_Turn(true,73,50);
                   LF.spin(reverse,30,percent);
            RF.spin(reverse,30,percent);
            LR.stop(coast);
            RR.stop(coast);
            task::sleep(1000);
            SpinUntilRed(true,true);
            stopallmotors();
            
    
       }
                /*! ****************************************************************************************************
 @brief This is the skills main auton function NOTE: THERE IS NO NEED TO CALL THIS IT IS AUTOMATICLY CALLED IN THE MAIN.CPP
 ******************************************************************************************************/
        void Skills() {
          
          thread timethread(TimerHeheheh);
            FirstPartofSkills();
            SecondPartSkills();

           thread d(addpower);


            old_Drive(7,100);
            old_Turn(false,284,50);
            old_Drive(2,75,reverse);
            old_Turn(true,3,25,0.5);
             LF.spin(reverse,30,percent);
            RF.spin(reverse,30,percent);
            LR.stop(coast);
            RR.stop(coast);
            task::sleep(1000);
            SpinUntilRed(true,false);
            stopallmotors();
            old_Drive(7,100);


            old_Turn(true,22.5,20);
            old_Drive(2,100);
            Pnematics.set(true);
            SmallEndgame.set(true);
            task::sleep(3000);
            Pnematics.set(false);
            SmallEndgame.set(false);
            old_Drive(2,100,reverse);
        }
                 /*! ****************************************************************************************************
 @brief This is the milford skills
 ******************************************************************************************************/
         void Archive(){
          /* Milford Skills*/
                  LF.spin(reverse, 30, percent);
         
            ColorSpinnerFunctions::SpinUntilRed(false);
            stopallmotors();
            old_Drive(6, 150);
            ShootingPower = 83;
            thread e(Shoot);
                        old_Turn(true, 62, 50);
            old_Drive(15, 150);
           
            task::sleep(500);
            Shoot();
            task::sleep(1000);
            Shoot();
            task::sleep(1000);

            STOPShoot();
            old_Turn(false, 272, 50);

            ShootingPower = 83;
            SpinningPower = -85;
            IntakeFunctions::StartIntake();
            old_Drive(8, 150);
                    SpinningPower = 85;
                  Intake.spin(reverse,SpinningPower,percent);
             old_Drive(15, 20);
            Shoot();
            old_Turn(true, 111, 50);
            IntakeFunctions::StartIntake();
            task::sleep(500);
            SpinningPower = -75;
            IntakeFunctions::StartIntake();
            ShootingPower = 92;
            
                        Shoot();
            task::sleep(1000);
            Shoot();
            task::sleep(1000);
            Shoot();
            task::sleep(1000);
            thread f42342342e(STOPShoot);
            thread e23(IntakeFunctions::StartIntake);
             old_Drive(4, 100);
            task::sleep(1000);
             old_Turn(false, 292, 50);
            SpinningPower = 75;
            IntakeFunctions::StartIntake();
             old_Drive(51, 130);
            ShootingPower = 82 ;
            Shoot();
            IntakeFunctions::StartIntake();
            SpinningPower = -75;
            IntakeFunctions::StartIntake();
             old_Turn(true, 111, 50);

            Shoot();
            task::sleep(1000);
            Shoot();
            task::sleep(1000);
                Shoot();
            task::sleep(1000);
            STOPShoot();
            StartIntake();
             old_Turn(true, 3, 50);
             old_Drive(20.5, 150, reverse);
             old_Turn(true,38);
            LF.spin(reverse, 30, percent);
            LR.spin(reverse, 30, percent);
            RF.spin(reverse, 30, percent);
            RR.spin(reverse, 30, percent);
             task::sleep(300);
            ColorSpinnerFunctions::SpinUntilRed(true);
            stopallmotors();
             old_Drive(11, 150);
             old_Turn(false, 275,50);
             
            LF.spin(reverse, 30, percent);
            LR.spin(reverse, 30, percent);
            RF.spin(reverse, 30, percent);
            RR.spin(reverse, 30, percent);
             task::sleep(300);
            ColorSpinnerFunctions::SpinUntilRed(true);
            
             old_Drive(14,150);
              old_Turn(true,35,50);
             Pnematics.set(true);
             task::sleep(1000);
                Pnematics.set(false);
                 old_Drive(1,150,reverse);

            stopallmotors(coast);
        }
    }
}