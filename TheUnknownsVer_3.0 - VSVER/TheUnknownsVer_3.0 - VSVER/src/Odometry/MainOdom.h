#include "../Odometry/Orientation.h"
/*! ****************************************************************************************************
 @brief A Library of functions for odometry
 ******************************************************************************************************/
namespace Odometry{
  /*! ****************************************************************************************************
 @brief A Library of MAIN functions for odometry NOTE: DO NOT CALL THESE THESE ARE CALLED IN MAIN.CPP
 ******************************************************************************************************/
  inline namespace Main{
//CONSTANTS / Hard-Coded Values
//Radius of tracking wheels in inches
double WHEEL_RADIUS = 1.375; //was 1.379 //1.43

//Starting angle (relative to field) (RADIANS)
double THETA_START = M_PI; //imagine the field is a unit circle

//The starting x and y coordinates of the bot (INCHES)
  //These distances are relative to some point (0,0) on the field
  //Relative to: BOTTOM LEFT CORNER
double X_START = 0; //19.1
double Y_START = 0; //8.5

//Distances of tracking wheels from tracking center (INCHES)
double LTrackRadius = 2.25; //was 6.87
double RTrackRadius = 2.25; //6.8335
double STrackRadius = 0.75;

//Calculated Values (every loop)
//Angles (DEGREES) *NEEDS TO BE CONVERTED TO RADIANS FOR MATH*
double LPos = 0;
double RPos = 0;
double SPos = 0;

double LPrevPos = 0;
double RPrevPos = 0;
double SPrevPos = 0;

//Distances traveled by tracking wheels each loop (INCHES)
double deltaDistL = 0;
double deltaDistR = 0;
double deltaDistS = 0;

//Distance summations (since last reset)
double totalDeltaDistL = 0;
double totalDeltaDistR = 0;

//The current angle of the bot (RADIANS)
double currentAbsoluteOrientation = THETA_START;
//The previous angle of the bot (RADIANS)
double previousTheta = THETA_START;

//The change in Theta each loop (RADIANS)
double deltaTheta = 0;

//The Average angle Theta (In RADIANS) throughout the arc
  //currentAbsoluteOrientation + (deltaTheta / 2)
double avgThetaForArc = currentAbsoluteOrientation + (deltaTheta / 2);

//The changes in the X and Y positions (INCHES)
/*These are calculated on a local basis each loop,
then converted to global position changes */
double deltaXLocal = 0;
double deltaYLocal = 0;

//The X and Y offsets converted from their local forms (INCHES)
double deltaXGlobal = 0;
double deltaYGlobal = 0;

//The global position of the bot (INCHES)
double xPos =  0;
double yPos = 0;
double xPosGlobal = 0;
double yPosGlobal = 0;
/*! ****************************************************************************************************
 @brief The Main Tracking Loop function called in  ODOMETRY INIT
 ******************************************************************************************************/
void positionTrackingInit() {
  LeftEncoderY.setPosition(0, deg);
    RightEncoderY.setPosition(0, deg);
    EncoderX.setPosition(0, deg);
    xPosGlobal = X_START;
    yPosGlobal = Y_START;
  while(1) {
    //Get encoder values (DEGREES)
    
    LPos = LeftEncoderY.position(rotationUnits::deg);
    RPos = RightEncoderY.position(rotationUnits::deg);
    SPos = EncoderX.position(rotationUnits::deg);

    //Calculate distance traveled by tracking each wheel (INCHES)
      //Converts degrees to radians
    deltaDistL = ((LPos - LPrevPos) * M_PI / 180) * WHEEL_RADIUS;
    deltaDistR = ((RPos - RPrevPos) * M_PI / 180) * WHEEL_RADIUS;
    deltaDistS = ((SPos - SPrevPos) * M_PI / 180) * WHEEL_RADIUS;

    //Update previous values to be used next loop (DEGREES)
    LPrevPos = LPos;
    RPrevPos = RPos;
    SPrevPos = SPos;

    //Total change in each of the L and R encoders since last reset (INCHES)
    //These are used to calculate the absolute orientation of the bot
    totalDeltaDistL += deltaDistL;
    totalDeltaDistR += deltaDistR;

    //Calculate the current absolute orientation (RADIANS)
    //currentAbsoluteOrientation = THETA_START - ( (totalDeltaDistL - totalDeltaDistR) / (LTrackRadius + RTrackRadius) );
    currentAbsoluteOrientation = CalulatedHeadingRad;

    //Calculate the change in the angle of the bot (RADIANS)
    deltaTheta = currentAbsoluteOrientation - previousTheta;

    //Update the previous Theta value (RADIANS)  
    previousTheta = currentAbsoluteOrientation;

    //If we didn't turn, then we only translated
    if(deltaTheta == 0) {
      deltaXLocal = deltaDistS;
      // could be either L or R, since if deltaTheta == 0 we assume they're =
      deltaYLocal = deltaDistL;
    }
    //Else, caluclate the new local position
    else {
      //Calculate the changes in the X and Y values (INCHES)
      //General equation is:
        //Distance = 2 * Radius * sin(deltaTheta / 2)
      deltaXLocal = 2 * sin(deltaTheta / 2.0) * ((deltaDistS / deltaTheta) + STrackRadius);
      deltaYLocal = 2 * sin(deltaTheta / 2.0) * ((deltaDistR / deltaTheta) - RTrackRadius);

    }

    //The average angle of the robot during it's arc (RADIANS)
    avgThetaForArc = currentAbsoluteOrientation - (deltaTheta / 2);

    deltaXGlobal = (deltaYLocal * cos(avgThetaForArc)) - (deltaXLocal * sin(avgThetaForArc));
    deltaYGlobal = (deltaYLocal * sin(avgThetaForArc)) + (deltaXLocal * cos(avgThetaForArc));

    //Wraps angles back around if they ever go under 0 or over 2 pi
    while(currentAbsoluteOrientation >= 2 * M_PI) {
      currentAbsoluteOrientation -= 2 * M_PI;
    }
    
    while(currentAbsoluteOrientation < 0) {
      currentAbsoluteOrientation += 2 * M_PI;
    }

    //Update global positions
    yPosGlobal += deltaXGlobal*1.07829181495*1.00806452;
    xPosGlobal += deltaYGlobal;


    // Brain.Screen.setCursor(4,8);
    // Brain.Screen.print(deltaDistS/deltaTheta);
    // Brain.Screen.setCursor(5,8);
    // Brain.Screen.print((deltaDistL+deltaDistR)/2);
    // Brain.Screen.setCursor(6,8);
    // Brain.Screen.print(deltaDistS);
    // Brain.Screen.setCursor(7,8);
    // Brain.Screen.print(deltaTheta);


    //loop every 20 milliseconds
    task::sleep(20);

  }
  
}

double startXPos = 0;
double startYPos = 0;
/*! ****************************************************************************************************
 @brief Makes sure the xPos and the Ypos are correct
 ******************************************************************************************************/
void keep(){
  while(true){
    xPos = (xPosGlobal-4.5)*1.04166666667+startXPos;
    yPos = (yPosGlobal-1.5)*0.91466203237*1.02127659574+startYPos;
    task::sleep(15);
  }
}
/*! ****************************************************************************************************
 @brief The main init for odometry tracking
 ******************************************************************************************************/
void odomInit(){
thread t1(positionTrackingInit);
thread t2(keep);
}
  }
}