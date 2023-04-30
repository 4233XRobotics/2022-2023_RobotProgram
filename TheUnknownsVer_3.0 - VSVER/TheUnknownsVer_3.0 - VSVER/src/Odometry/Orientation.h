#include "robot-config.h"
#include <cmath>
/*! ****************************************************************************************************
 @brief A Library of functions for odometry
 ******************************************************************************************************/
namespace Odometry{
  /*! ****************************************************************************************************
 @brief A Library of  functions to calculate the Orientation of the robot
 ******************************************************************************************************/
  inline namespace Orientation{
  double CalulatedHeadingRad = 0;
double CalulatedHeadingDeg = 0;
double OrientationStart = 0;
/*! ****************************************************************************************************
 @brief The initialization function for the Orientation of the robot using the Inertial rotation NOTE: DO NOT CALL THIS THIS IS DONE FOR YOU IN MAIN.CPP
 ******************************************************************************************************/
void OrientationInit(){
  
   
 
     while(true){
         CalulatedHeadingDeg = fmod(Inertial1.rotation(deg)*1.01773114*1.01136664*0.988717633+OrientationStart,360);
    if(CalulatedHeadingDeg < 0 ){
      while(CalulatedHeadingDeg< 0){
      CalulatedHeadingDeg = 360 + CalulatedHeadingDeg;
      }
    }
    CalulatedHeadingRad = CalulatedHeadingDeg *M_PI/180;

     }

 }

  }
}