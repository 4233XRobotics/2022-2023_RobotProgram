#include <cmath>
/*! ****************************************************************************************************
 @brief A Library of functions for odometry
 ******************************************************************************************************/
namespace Odometry{
  /*! ****************************************************************************************************
 @brief A libray of untity functions for odometry and PID
 ******************************************************************************************************/
  inline namespace cmath2{
    /*! ****************************************************************************************************
 @brief A Function that gets the absoulute value of a number that could be a decimal
 @param a The the decimal that it finds the absoulute value of 
 ******************************************************************************************************/
double absd(double a ){
  if(a<0){
    a = a*-1;
  }
  return a;
}
/*! ****************************************************************************************************
 @brief A function that uses the absolute value of both args to return a product out of  the minimum  range used for PID
 @param double1 This is the number that we are trying to keep out of the range
 @param double2 This is the number that is the minimum and maximum of the range

 ******************************************************************************************************/
double keepoutofrange(double double1,double double2){
  double product;
  bool isnegative = double1 < 0;
  double m = 1;
  if(isnegative) m = -1;
  if(absd(double1) < absd(double2)){
    product = absd(double2) * m;
  }
  else{
    product = double1;
  }
  return product;
}
/*! ****************************************************************************************************
 @brief This function keeps the first argument with in a range
 @param double1 This is the number that we are trying to keep within a range 
 @param double2 the Maximum of the range if  double1 is greater than it it returns this argument
 @param double3 The Minumum of the range if double1 is less than this it returns double3
 ******************************************************************************************************/
double keep_within_a_range(double double1,double double2,double double3){
double product;
if (double2 < double1){
  product = double2;
  
}
else{
  if(double3 > double1){
    product = double3;
  }
  else{
  product = double1;
  }
}


  return product;

}
/*! ****************************************************************************************************
 @brief Returns the heading for the robot to turn to the point using the arctan of the change of the x and y
 @param x1 the X position of the robot
 @param y1 the Y position of the robot 
 @param x2 the Desired X position to turn to 
 @param y2 the Desired Y position the robot needs to turn to 
 ******************************************************************************************************/
double getDesiredHeadingforRotate(double x1,double y1,double x2, double y2 ){
double deltaX = x2-x1;
double deltaY = y2-y1;
if(deltaX ==0){
  deltaX = 0.1;
}
if (deltaY == 0){
  deltaY = 0.1;
}

double theta = (std::atan(deltaX/deltaY) * 180) / 3.14159265;

double desiredRotation = 0;
if(x2>x1 && y2>y1){
  desiredRotation = theta;
}
if(x2<x1&& y2<y1){
  desiredRotation = theta + 180;
}if(y2 == y1){
  if (deltaX < 0){
desiredRotation = 270;
  }
  else{

  
  desiredRotation = 90;
  }
}
if(x2>x1 && y2<y1){desiredRotation = 180+theta;}if(x2<x1 && y2>y1){desiredRotation = theta;}desiredRotation = fmod(desiredRotation,360);
while(desiredRotation<0){
  desiredRotation = 360+desiredRotation;
}
if(x2 == x1){
  desiredRotation = -1;
}
return (desiredRotation);
}


  }}