#include "../Display.h"
#include <cmath>
using namespace ButtonControls;
using namespace vex;
using namespace Odometry;
 /*! ****************************************************************************************************
 @brief A library of functions for autonomous and programming skills
 ******************************************************************************************************/
namespace Auton{
 /*! ****************************************************************************************************
 @brief A Library of functions for driving in auton
 ******************************************************************************************************/
  inline namespace AutonFunctions{
     /*! ****************************************************************************************************
 @brief Sets the position to a certian orientation and x and y
 @param cx This is the x position you want to change it to 
 @param cy This is the y position you want to change it to 
 @param orientation This is the orientation you want to start with 
 ******************************************************************************************************/
    void SetInPos(double cx, double cy,double orientation = 0){
    xPosGlobal  = xPosGlobal + (cx/1.04166666667);
    yPosGlobal = yPosGlobal + (cy/0.91466203237);
    OrientationStart +=orientation;
    } 
     /*! ****************************************************************************************************
 @brief A simple function drives the robot forward or backwards a certian number of inches
 @param distance the Distance in Inches you want the robot to travel if you want to travel backwards PLEASE DO NOT SET THIS TO NEGATIVE NOTE: THESE DISTANCES ARE NOT EXACT IT WILL OVER SHOOT WHAT YOU TELL IT TO
 @param velocity the Speed of the motors in RPM NOTE: THE HIGHER THIS IS THE MORE OVERSHOOT and VARIBILITY
 @param direction that you want it to travel backwards to drive you use reverse to travel the distance backwards in arg1 and fwd to travel the distance in arg1 forwards
 @param bt the Type of brake you want the robot to stop with 
 @param UsesInchesSytem I recommend seting this to true unless you want to use degrees of the encoder!
 ******************************************************************************************************/
      void old_Drive(float distance, float velocity, directionType direction = fwd, brakeType bt = hold,bool UsesInchesSystem = true) {
          if (UsesInchesSystem) {
              distance = distance / 0.02181661564;
          }
          double PastPositionLeft = LeftEncoderY.position(degrees);
          double PastPositionRight = RightEncoderY.position(degrees);
          LF.spin(direction, velocity, velocityUnits::rpm);
          LR.spin(direction, velocity, velocityUnits::rpm);
          RF.spin(direction, velocity, velocityUnits::rpm);
          RR.spin(direction, velocity, velocityUnits::rpm);
          bool Continue = true;
          LeftEncoderY.setPosition(0, degrees);
          RightEncoderY.setPosition(0, degrees);
          
          while (Continue) {
              if (direction == fwd) {
                  if ((LeftEncoderY.position(degrees) > (distance)) && ((RightEncoderY.position(degrees)/* * -1 */) > (distance))) {
                      Continue = false;
                  }
              }
              else {
                  if ((LeftEncoderY.position(degrees) < (-distance)) &&
                      ((RightEncoderY.position(degrees) /* *-1*/) < (-distance))) {
                      Continue = false;
                  }
              }
              /*
              double m =((1-LeftEncoderY.position(degrees)/distance)+(1-RightEncoderY.position(degrees)/distance))/2;
              if (m<0.7){
                m = 0.7;
              }
                LF.spin(direction,velocity*m,velocityUnits::rpm);
      LR.spin(direction,velocity*((1-LeftEncoderY.position(degrees)/distance)+(1-RightEncoderY.position(degrees)/distance))/2,velocityUnits::rpm);
           RF.spin(direction,velocity*((1-LeftEncoderY.position(degrees)/distance)+(1-RightEncoderY.position(degrees)/distance))/2,velocityUnits::rpm);
            RR.spin(direction,velocity*((1-LeftEncoderY.position(degrees)/distance)+(1-RightEncoderY.position(degrees)/distance))/2,velocityUnits::rpm);

*/
          }
          ButtonControls::stopallmotors(bt);
      }
       /*! ****************************************************************************************************
 @brief The function to tell the robot to turn 
 @param Right True if you want to spin to the right and false if you want to spin to the left
 @param degreesofturn if you want to go lets say 90 degrees to the right you use 90 here but if you want to go 90 deg to the left
 you use 360-90 as the degreesofturn
 @param speedofturn the speed of the motors in RPM when turning the higher it is the more over shoot and more chance of going around in a circle and back
 @param rangeoferror the range of error you allow when it stops at default it is 1 
 ******************************************************************************************************/
     void old_Turn(bool Right,double degreesofturn,double speedofturn = 67,double rangeoferror = 1){
        
  double multiplier = 1;
  
  if(Right == false){
    multiplier = -1;
  }
  if (degreesofturn <= 0){
    degreesofturn = degreesofturn *-1;
    multiplier = multiplier * -1;
  }

   speedofturn = multiplier*speedofturn;
  LF.spin(fwd,speedofturn,percentUnits::pct);
LR.spin(fwd,speedofturn,percent);
RF.spin(reverse,speedofturn,percentUnits::pct);
RR.spin(reverse, speedofturn, percentUnits::pct); // adkdasldkjasdlakdkjsaldsklsakdjaldjasdjadjadjadjkadjawdjlkawdlkjawdlkadjkadjkaldADADDADADADA
double pastHeading = CalulatedHeadingDeg;


   double degminus5 = degreesofturn-rangeoferror;
double degplus5 = degreesofturn+rangeoferror;
bool Exit = true;
while(Exit){
 task::sleep(5);
 double heading = fmod((CalulatedHeadingDeg-pastHeading),360);
while(heading < 0){
  heading = heading+360;
}
 
if((degminus5 <=  heading && degplus5 >= heading )){
 Exit = false;
}

}
   LF.stop();
      LR.stop();
      RF.stop();
      RR.stop();
  }
  }



double 

smallturnKp = .1,
smallturnKi = 0.00,
smallturnKd =0.02;

 /*! ****************************************************************************************************
 @brief This is a pid for small turns AUTOMATICLY USED BY THE TURN TO HEADING DEG FUNCTION DO NOT CALL THIS
 @param desiredheading the desired heading of the robot at the end
 @param Right Does the robot go right?
 @param SmallTurn is this a small turn?
 @param Smallest is this the smallest turn?
 @param motorPower the speed of the motors while turning 
 ******************************************************************************************************/
void smallturnToHeadingDeg(double desiredheading,bool Right,bool SmallTurn,bool Smallest,  double motorPower = 50){
directionType leftdirection, rightdirection;
if (Right){leftdirection = fwd;rightdirection = reverse;}else{leftdirection = reverse;rightdirection = fwd;}
double error, prevError, derivative,totalError,f,d,simulatedCurrent,simulatedDesired;
bool enableTurnPID = true;
double pastMotorPower = 4;
if(SmallTurn == false){
  smallturnKp = .2,
smallturnKi = 0.00,
smallturnKd =0.055;

}
else{
  if(SmallTurn  == true && !Smallest){
    smallturnKp = .15,
smallturnKi = 0.00,
smallturnKd =0.035;  }
else{
smallturnKp = .1,
smallturnKi = 0.00,
smallturnKd =0.02;
}
}
while (enableTurnPID){

 simulatedCurrent = 360-CalulatedHeadingDeg;

  simulatedDesired = 360-desiredheading;


  /* Calulate the Error */
error = simulatedDesired-simulatedCurrent;
//////////////////////////////////////////////////////
  /* Calulate the  Derivative */
  derivative = error-prevError;
  
  /* Calulate The Inegral*/
  if(absd(pastMotorPower) < 3){
  totalError = totalError + error;
  }
  /* Declare Variables*/
  motorPower  = error * smallturnKp + derivative *smallturnKd + totalError * smallturnKi;
  motorPower = keepoutofrange(motorPower, 0.05);
  LF.spin(leftdirection,motorPower,percent);
  LR.spin(leftdirection,motorPower,percent);
  RF.spin(rightdirection,motorPower,percent);
  RR.spin(rightdirection,motorPower,percent);
  prevError = error;pastMotorPower = motorPower;

  
if(Right == true){
  if((desiredheading+1) >=Odometry::CalulatedHeadingDeg && (desiredheading-.5) <=Odometry::CalulatedHeadingDeg ){
    enableTurnPID = false;
  }
}
else{
  if((desiredheading+.5) >=Odometry::CalulatedHeadingDeg && (desiredheading-1) <=Odometry::CalulatedHeadingDeg ){
    enableTurnPID = false;
  }
}
  task::sleep(10);

}
}
void RemoveHold(){
  task::sleep(500);
  stopallmotors(coast);
}
/* Turn Pd Settings*/
double 

        turnKp = 1.5,
turnKd =0.3;
 /*! ********************************Z*******************************************************************
 @brief Turn to heading deg turns to the desired heading 
 @param desiredheading The desiredheading of the turn
 @param motorPower the power of the motor when turning
 @param rotationwhenpid At what rotation does the real pid strart
 @attention I would use this for correcting angles but not for every single ancgle becasue it is kinda slow
 ******************************************************************************************************/
void turnToHeadingDeg(double desiredheading, double motorPower = 20,double rotationwhenpid =20) {
    double error, prevError = 0, derivative, turnRotation, simulatedCurrent, simulatedDesired, startingRotation;
    bool enableTurnPID = true, Right = true, NearTarget, CurrentHeadingGreater, DesiredHeadingGreater;
    directionType leftdirection, rightdirection;

    if (desiredheading == CalulatedHeadingDeg) {
        enableTurnPID = false;
        return;
    }

    double difference = desiredheading - CalulatedHeadingDeg;
    difference = fmod(difference + 180, 360) - 180;
    double signofrotation;
    if(difference <0){
      signofrotation = -1;
    }
    else{
      signofrotation = 1;
    }
    Right = (signofrotation <0);
    if (Right) {
        leftdirection = fwd;
        rightdirection = reverse;
    } else {
        leftdirection = reverse;
        rightdirection = fwd;
    }

    startingRotation = Inertial1.rotation(deg)*1.01773114*1.01136664*0.988717633;
    double heading = CalulatedHeadingDeg;
    turnRotation = absd(difference);
double count = 0;
    while (enableTurnPID) {
      count++;
        simulatedCurrent = fmod((CalulatedHeadingDeg- startingRotation) + 360, 360);
        simulatedDesired = fmod((desiredheading - startingRotation) + 360, 360);
        error = simulatedDesired - simulatedCurrent;

        if (error < -180) {
            error += 360;
        } else if (error > 180) {
            error -= 360;
        }

     
     
    Right = (error >0);
    if (Right) {
        leftdirection = fwd;
        rightdirection = reverse;
        error = absd(error);
    } else {
        leftdirection = reverse;
        rightdirection = fwd;
        error = absd(error);
    }
    
       double normalizedError = error / absd(difference);
     derivative = normalizedError - prevError;
      difference = desiredheading - CalulatedHeadingDeg;
    difference = fmod(difference + 180, 360) - 180;
        turnRotation = absd(difference);
if(turnRotation > 180){
  turnRotation = turnRotation-180;
}
        if (absd(turnRotation) <= absd(rotationwhenpid)) {
            motorPower = normalizedError * turnKp + derivative * turnKd;
        }
       if(absd(motorPower < 5)) motorPower = 8;
       if(count>=75){
        break;
       }
        LF.spin(leftdirection, motorPower, percent);
        LR.spin(leftdirection, motorPower, percent);
        RF.spin(rightdirection, motorPower, percent);
        RR.spin(rightdirection, motorPower, percent);

        prevError = error;
        Brain.Screen.setCursor(7,1);
        Brain.Screen.clearLine();
        Brain.Screen.print("MP:%f",motorPower);
        Brain.Screen.print("TR:%f",turnRotation);
        if (Right == true) {
            if ((desiredheading + 1) >= CalulatedHeadingDeg && (desiredheading - 0.5) <= CalulatedHeadingDeg) {
                enableTurnPID = false;
                Controller1.rumble("...._...._.._..._...");
                break;
            }
        } else {
            if ((desiredheading + 0.5) >= CalulatedHeadingDeg && (desiredheading - 1) <= CalulatedHeadingDeg) {
                enableTurnPID = false;
                            Controller1.rumble("...._...._.._..._...");
                break;
            }
        }

        task::sleep(20);
    }

stopallmotors(hold);

}

 /*! ****************************************************************************************************
 @brief Turns to the point at the x and y provided
 @param x the x of the point you want it to turn towards
 @param y the y of the point you want it to turn towards
 @param add180 set to true if you want it to turn its back to the point
 @param iscorection set this to true if it is most likely to be a small angle
 ******************************************************************************************************/
void TurntoPoint(double x, double y ,bool add180 = false,bool iscorection = false){
 double desiredheading = Odometry::getDesiredHeadingforRotate(Odometry::xPos,Odometry::Main::yPos,x,y);
 if(desiredheading<0){
   desiredheading = fmod(360+CalulatedHeadingDeg,360);
 }
 if(add180){
   desiredheading = fmod(180+desiredheading, 360);
 }
 double rotation = desiredheading-Odometry::CalulatedHeadingDeg;
rotation = 360- absd(rotation);
if(rotation <=2.5 && !iscorection){
  return;
}
 Brain.Screen.print(desiredheading);
 turnToHeadingDeg(desiredheading);
}
double calculatedistance(double x0,double x1,double y0,double y1){
double d = sqrt(
 ( (x1-x0)*(x1-x0)) + ((y1-y0)*(y1-y0))
);
return d;
}
 double 
 /* Distance Pid Settings */
 kP = 6.5,
 kI = 0.0,
 kD = 0.4,

/* Straight Pid Settings*/
 skD = 0.08,
 skI = 0.0,
 skP = 0.3,

 /* Encoder to In Multipliers */
 EncoderToInL = 0.03305785123,
 EncoderToInR=0.03280929596;
 /*! ****************************************************************************************************
 @brief Drives to the point using a pid control and the turn to point funciton
 @param desiredX the X that you want the robot to move to 
 @param desiredY the Y that you want the robot to move to 
 @param startingmotorpower the power that the robot starts at 
 @param tolerance The amount of error in inches it allows
 @attention This is because the turnToHeading function does not work I do not recommend to do use this
 ******************************************************************************************************/
void DriveToPointPid(double desiredX,double desiredY,double startingmotorpower  = 50,double tolerence = 0.2){
TurntoPoint(desiredX,desiredY);
double distance = calculatedistance(xPos,desiredX, yPos,desiredY);
int startingLeftValue = LeftEncoderY.position(deg);
int startingRightValue = RightEncoderY.position(deg);
bool enablePD = true;
double startingY = yPos,startingX = xPos,Lerror= 0,LprevError = 0,Lderivative = 0,Lintegral = 0, Rerror = 0, RprevError = 0,Rderivative = 0,Rintegral = 0, LmotorPower = startingmotorpower,
 RmotorPower = startingmotorpower,
 Rabsoluteposition = 0,
 Labsoluteposition = 0;
int i = 0;
while ((( calculatedistance(startingX, xPos ,startingY, yPos)<=  (distance)-0.2))){
if(!(i>=50)){
RmotorPower = startingmotorpower * (i*.02);
}
Rabsoluteposition =(RightEncoderY.position(deg) - startingRightValue) * EncoderToInR;
Rerror = (distance- calculatedistance(startingX, xPos ,startingY, yPos)) ;
Rderivative = Rerror - RprevError;
Rintegral = Rintegral + Rerror;
if((( distance-calculatedistance(startingX, xPos ,startingY, yPos)<=10 ))){
RmotorPower =  (Rerror * kP + Rderivative * kD + Rintegral *kI);// error will be 5 or less so Kp should be between 0 and 16 to keep power less than 80
}

Labsoluteposition = (LeftEncoderY.position(deg) - startingLeftValue)*EncoderToInL;
Lerror = (Rabsoluteposition/ EncoderToInR)-(Labsoluteposition/ EncoderToInL*0.99055514211);
Lderivative = Lerror - LprevError;
Lintegral = Lintegral + Lerror;
LmotorPower = RmotorPower + (Lerror * skP + Lderivative* skD + Lintegral* skI);
stopallmotors(coast);


LF.spin(fwd,LmotorPower,percent);
LR.spin(fwd,LmotorPower,percent);
RF.spin(fwd,RmotorPower,percent);
RR.spin(fwd,RmotorPower,percent);


Brain.Screen.clearLine(7);
Brain.Screen.setCursor(7,1);
Brain.Screen.print("LE:%f",Lerror);
Brain.Screen.print("RE:%f",Rerror);
Brain.Screen.print("CD:%f",calculatedistance(startingX, xPos ,startingY, yPos));
Brain.Screen.print("D:%f",distance);
LprevError = Lerror;RprevError= Rerror;
task::sleep(8);
Rabsoluteposition =(RightEncoderY.position(deg) - startingRightValue) *  EncoderToInR;
Labsoluteposition = (LeftEncoderY.position(deg) - startingLeftValue)* EncoderToInL;
i+=1;
}
stopallmotors(brake);

}

 /*! ****************************************************************************************************
 @brief A function that Drives backwards to a point
 @param desiredX the X that you want the robot to move to 
 @param desiredY the Y that you want the robot+
  to move to 
 @param startingmotorpower the power that the robot starts at 
 @param tolerance The amount of error in inches it allows
 @attention This is because the turnToHeading function does not work I do not recommend to do use this
 ******************************************************************************************************/
void InverseDriveToPointPid(double desiredX,double desiredY,double startingmotorpower  = 50,double tolerence = 0.2){
TurntoPoint(desiredX,desiredY,true);
double distance = calculatedistance(xPos,desiredX, yPos,desiredY);
int startingLeftValue = LeftEncoderY.position(deg);
int startingRightValue = RightEncoderY.position(deg);
bool enablePD = true;
double startingY = yPos,startingX = xPos,Lerror= 0,LprevError = 0,Lderivative = 0,Lintegral = 0, Rerror = 0, RprevError = 0,Rderivative = 0,Rintegral = 0, LmotorPower = startingmotorpower,
 RmotorPower = startingmotorpower,
 Rabsoluteposition = 0,
 Labsoluteposition = 0;
/*
if (distance < 0){
  distance =  distance * -1;
}
*/
int i = 0;
while ((( calculatedistance(startingX, xPos ,startingY, yPos)<=  (distance)))){
if(!(i>=50)){
RmotorPower = startingmotorpower * (i*.02);
}
Rabsoluteposition =(RightEncoderY.position(deg) - startingRightValue) * EncoderToInR;
Rerror = (distance- calculatedistance(startingX, xPos ,startingY, yPos)) ;
Rderivative = Rerror - RprevError;
Rintegral = Rintegral + Rerror;
if((( distance-calculatedistance(startingX, xPos ,startingY, yPos)<=10 ))){
RmotorPower =  (Rerror * kP + Rderivative * kD + Rintegral *kI);// error will be 5 or less so Kp should be between 0 and 16 to keep power less than 80
}

Labsoluteposition = (LeftEncoderY.position(deg) - startingLeftValue)*EncoderToInL;
Lerror = (Rabsoluteposition/ EncoderToInR)-(Labsoluteposition/ EncoderToInL*0.99055514211);
Lerror = Lerror * -1;
Lderivative = Lerror - LprevError;
Lintegral = Lintegral + Lerror;
LmotorPower = RmotorPower + (Lerror * skP + Lderivative* skD + Lintegral* skI);
/*if (distance < 0) {d
    if (Labsoluteposition < distance) {
        LmotorPower = 0;
    }
}
else {*/


//}
//if (distance < 0) {
//    if (Rabsoluteposition < distance) {
   //     RmotorPower = 0;
  //  }
//}
//else {

// } 
//if (distance < 0) {
  //  if ((Rabsoluteposition < distance) && (Labsoluteposition < distance)) {
//        enablePD = false;
  //  }
//}
//else {
    
//}




LF.spin(reverse,LmotorPower,percent);
LR.spin(reverse,LmotorPower,percent);
RF.spin(reverse,RmotorPower,percent);
RR.spin(reverse,RmotorPower,percent);




LprevError = Lerror;RprevError = Rerror;
task::sleep(8);
Rabsoluteposition =(RightEncoderY.position(deg) - startingRightValue) *  EncoderToInR;
Labsoluteposition = (LeftEncoderY.position(deg) - startingLeftValue)* EncoderToInL;
i+=1;
}
stopallmotors(brake);

}
float MturnError;
float Mturnkp;
float Mturnkd;
float MturnPrevError;
float MturnDerivative;
int exitwhileloop = 1;
float turnslewarray[9] = {33,42,50,58,67,75,83,92,100};
   float Ad;
void MarshallTurnpid (float desiredValue, float Iturnkp, float Iturnkd, float minrpm) {

Mturnkp = Iturnkp;
Mturnkd = Iturnkd;
 exitwhileloop = 1;
 int count = 0;  //reset count each time turnpid is ran
 float slewvoltage = minrpm;




 MturnPrevError = MturnError;
directionType leftdirection, rightdirection;
bool Right;
double signofrotation = (desiredValue-CalulatedHeadingDeg)/(desiredValue-CalulatedHeadingDeg);
double desiredheadinginverserotation = 360-desiredValue;
double currentheadinginverserotation = 360-CalulatedHeadingDeg;
if(desiredValue > CalulatedHeadingDeg){
  signofrotation = (desiredheadinginverserotation-CalulatedHeadingDeg)/(desiredheadinginverserotation-CalulatedHeadingDeg)*-1;
}
if(desiredValue<CalulatedHeadingDeg){
    signofrotation = (CalulatedHeadingDeg-desiredValue)/(CalulatedHeadingDeg-desiredValue)*-1;
  if(desiredValue<180){
     signofrotation = (CalulatedHeadingDeg-desiredValue)/(CalulatedHeadingDeg-desiredValue);
  }

  
}
Right = signofrotation>0;
if (Right){leftdirection = fwd;rightdirection = reverse;}else{leftdirection = reverse;rightdirection = fwd;}
 while (exitwhileloop == 1) {
 
  //Brain.Screen.printAt(10,20, "heading at stop :%f", turnheading);
  //Brain.Screen.printAt(10,40, "turn error :%f", turnError);
  //Brain.Screen.clearScreen();
  //Brain.Screen.setCursor(1,1);
  //Brain.Screen.print("count loop :%d", count);
 
  //Derivative
  MturnDerivative = (MturnError - MturnPrevError);

signofrotation = (desiredValue-CalulatedHeadingDeg)/(desiredValue-CalulatedHeadingDeg);
 desiredheadinginverserotation = 360-desiredValue;
currentheadinginverserotation = 360-CalulatedHeadingDeg;
if(desiredValue > CalulatedHeadingDeg){
  signofrotation = (desiredheadinginverserotation-CalulatedHeadingDeg)/(desiredheadinginverserotation-CalulatedHeadingDeg)*-1;
}
if(desiredValue<CalulatedHeadingDeg){
    signofrotation = (CalulatedHeadingDeg-desiredValue)/(CalulatedHeadingDeg-desiredValue)*-1;
  if(desiredValue<180){
     signofrotation = (CalulatedHeadingDeg-desiredValue)/(CalulatedHeadingDeg-desiredValue);
  }
}
signofrotation=signofrotation*-1;
Ad = CalulatedHeadingDeg;
  MturnError = signofrotation*(desiredValue-Ad);
  float lateralMotorPower = ( (MturnError * Mturnkp) + (MturnDerivative * Mturnkd) );  //calculate motor power


  if (count < 10) {
   slewvoltage = turnslewarray[count];// hi, how are you
  }
  else{
   slewvoltage = 100;  //max voltage
  }
 Brain.Screen.print("LatPower:%f",lateralMotorPower);
 int signoflat = lateralMotorPower/fabs(lateralMotorPower);
  if (fabs(lateralMotorPower) > slewvoltage){        //if it's greater than 10 volts, reduce to max of 10 volts
   lateralMotorPower=slewvoltage*signofrotation ;
  }
  
  if (fabs(lateralMotorPower) < minrpm){ //if its less than 1.5 volts, make it 1.5 volts - minimum volts
   lateralMotorPower=minrpm*signofrotation;
  }
 
  /////////////////////////////////////////////////////////////////////
  //Start Driving
  

  LF.spin(leftdirection,lateralMotorPower,rpm);
  LR.spin(leftdirection,lateralMotorPower,rpm);
  RF.spin(rightdirection,lateralMotorPower,rpm);
  RR.spin(rightdirection,lateralMotorPower,rpm);
  MturnPrevError = MturnError;
 
  vex::task::sleep(20);


signofrotation = (desiredValue-CalulatedHeadingDeg)/(desiredValue-CalulatedHeadingDeg);
 desiredheadinginverserotation = 360-desiredValue;
currentheadinginverserotation = 360-CalulatedHeadingDeg;
if(desiredValue > CalulatedHeadingDeg){
  signofrotation = (desiredheadinginverserotation-CalulatedHeadingDeg)/(desiredheadinginverserotation-CalulatedHeadingDeg)*-1;
}
if(desiredValue<CalulatedHeadingDeg){
    signofrotation = (CalulatedHeadingDeg-desiredValue)/(CalulatedHeadingDeg-desiredValue)*-1;
  if(desiredValue<180){
     signofrotation = (CalulatedHeadingDeg-desiredValue)/(CalulatedHeadingDeg-desiredValue);
  }
}signofrotation=signofrotation*-1;
Ad = CalulatedHeadingDeg;
  MturnError = signofrotation*(desiredValue-Ad);



  count++;
  if(count>75) {
      exitwhileloop = 0;
      stopallmotors();
      //Brain.Screen.printAt(10,60, "heading at stop :%f", turnheading);
      //Brain.Screen.printAt(10,80, "turn error :%f", turnError);
   }
 


   //calculate if we leave while loop
  if (fabs(MturnError) < 0.35){
      stopallmotors();
   task::sleep(100);

signofrotation = (desiredValue-CalulatedHeadingDeg)/(desiredValue-CalulatedHeadingDeg);
 desiredheadinginverserotation = 360-desiredValue;
currentheadinginverserotation = 360-CalulatedHeadingDeg;
if(desiredValue > CalulatedHeadingDeg){
  signofrotation = (desiredheadinginverserotation-CalulatedHeadingDeg)/(desiredheadinginverserotation-CalulatedHeadingDeg)*-1;
}
if(desiredValue<CalulatedHeadingDeg){
    signofrotation = (CalulatedHeadingDeg-desiredValue)/(CalulatedHeadingDeg-desiredValue)*-1;
  if(desiredValue<180){
     signofrotation = (CalulatedHeadingDeg-desiredValue)/(CalulatedHeadingDeg-desiredValue);
  }
}signofrotation=signofrotation*-1;
Ad = CalulatedHeadingDeg;
  MturnError = signofrotation*(desiredValue-Ad);
   if (fabs(MturnError) < 0.35){
    exitwhileloop = 0;
    Brain.Screen.printAt(10,60, "heading at stop :%f", CalulatedHeadingDeg);
    Brain.Screen.printAt(10,80, "turn error :%f", MturnError);


   




   }


  }
 }
}















}
