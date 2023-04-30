#include "../Odometry/MainOdom.h"
#include "robot-config.h"
/*! ****************************************************************************************************
 @brief A Library of functions for odometry
 ******************************************************************************************************/
namespace Odometry{
  /*! ****************************************************************************************************
 @brief A Library of functions for setting the starting position
 ******************************************************************************************************/
  inline namespace Set{
    double x = 0;
double y = 0;
double next = false;
double orientation = 0;

bool c1 = false;
/*! ****************************************************************************************************
 @brief A function that is a button control for settting the position NOTE: No need to worry about this
 ******************************************************************************************************/
void a1(){
  if (!c1 && orientation<360){
    c1 = true;
  orientation = orientation + 1;
task::sleep(200);
c1 = false;
  }
}
bool c2 = false;
/*! ****************************************************************************************************
 @brief A function that is a button control for settting the position NOTE: No need to worry about this
 ******************************************************************************************************/
void a2(){
  if(!c2){
    c2 = true;
 x = x+1;
 task::sleep(200);
c2 = false;
  }
}
bool c3 = false;
/*! ****************************************************************************************************
 @brief A function that is a button control for settting the position NOTE: No need to worry about this
 ******************************************************************************************************/
void a3(){
  if(!c3){
    c3 = true;
 x = x+10;
 task::sleep(200);
c3 = false;
  }
}
bool c4 = false;
/*! ****************************************************************************************************
 @brief A function that is a button control for settting the position NOTE: No need to worry about this
 ******************************************************************************************************/
void a4(){
  if(!c4){
    c4 = true;
 y = y+1;
 task::sleep(200);
c4= false;
  }
}
bool c5= false;
/*! ****************************************************************************************************
 @brief A function that is a button control for settting the position NOTE: No need to worry about this
 ******************************************************************************************************/
void a5(){
  if(!c5){
    c5 = true;
 y = y+10;
 task::sleep(200);
c5= false;
  }
}
bool c6= false;
/*! ****************************************************************************************************
 @brief A function that is a button control for settting the position NOTE: No need to worry about this
 ******************************************************************************************************/
void a6(){
  if(!c6 && orientation<360){
    c6 = true;
orientation = orientation + 10;
 task::sleep(200);
c6= false;
  }
}
bool c7= false;
/*! ****************************************************************************************************
 @brief A function that is a button control for settting the position NOTE: No need to worry about this
 ******************************************************************************************************/
void a7(){
  if(!c7){
    c7 = true;
x = x+10;
 task::sleep(200);
c7= false;
  }
}
bool c8= false;
/*! ****************************************************************************************************
 @brief A function that is a button control for settting the position NOTE: No need to worry about this
 ******************************************************************************************************/
void r1(){
  if(!c8 && orientation>0){
    c8 = true;
orientation = orientation -1;
 task::sleep(200);
c8= false;
  }
}
bool c9= false;
/*! ****************************************************************************************************
 @brief A function that is a button control for settting the position NOTE: No need to worry about this
 ******************************************************************************************************/
void r2(){
  if(!c9){
    c9 = true;
x = x -1;
 task::sleep(200);
c9= false;
  }
}bool c10= false;
/*! ****************************************************************************************************
 @brief A function that is a button control for settting the position NOTE: No need to worry about this
 ******************************************************************************************************/
void r3(){
  if(!c10){
    c10 = true;
x = x -10;
 task::sleep(200);
c10= false;
  }
}
bool c11= false;
/*! ****************************************************************************************************
 @brief A function that is a button control for settting the position NOTE: No need to worry about this
 ******************************************************************************************************/
void r4(){
  if(!c11 && orientation >9){
    c11 = true;
orientation  = orientation - 10;
 task::sleep(200);
c11= false;
  }
}
bool c12= false;
/*! ****************************************************************************************************
 @brief A function that is a button control for settting the position NOTE: No need to worry about this
 ******************************************************************************************************/
void r5(){
  if(!c12){
    c12 = true;
y = y-1;
 task::sleep(200);
c12= false;
  }
}
bool c13= false;
/*! ****************************************************************************************************
 @brief A function that is a button control for settting the position NOTE: No need to worry about this
 ******************************************************************************************************/
void r6(){
  if(!c13){
    c13 = true;
y = y-10;
 task::sleep(200);
c13= false;
  }
}
/*! ****************************************************************************************************
 @brief A function that is a button control for ending the setting positio gui
 ******************************************************************************************************/
void submit(){
 next = true;

}
 /*! ****************************************************************************************************
 @brief A function that is the user control for the setting position gui
 ******************************************************************************************************/
void settingusercontrol(){
  
while(next == false){

  if(Controller1.ButtonL2.pressing()){
    a1();
  }
  if(Controller1.ButtonL1.pressing()){
    a2();
  }
   if(Controller1.ButtonUp.pressing()){
     a3();
   }
if(Controller1.ButtonDown.pressing()){
  a4();
}
if(Controller1.ButtonRight.pressing()){
  a5();
}
if(Controller1.Axis3.position(percent) == 100){
  a6();
}
if(Controller1.ButtonLeft.pressing()){
  a7();
}




if(Controller1.ButtonR2.pressing()){
  r1();
}
if(Controller1.ButtonR1.pressing()){
  r2();
}
if(Controller1.ButtonX.pressing()){
  r3();
}
if(Controller1.Axis2.position(percent) == 100){
  r4();
}
if(Controller1.ButtonY.pressing()){
  r5();
}
if(Controller1.ButtonB.pressing()){
  r6();
}
if(Controller1.ButtonA.pressing()){
  submit();
}
task::sleep(20);
}
X_START = x;
Y_START = y;
OrientationStart = orientation;
}
 /*! ****************************************************************************************************
 @brief The function that initalizes the set postion UI to add this FIRST after
 int main() { // The Main Function
    Inertial1.calibrate();
  while(Inertial1.isCalibrating()){
    wait(15, msec);
  }
  Type Odometry::Set::setInit()
 ******************************************************************************************************/
void setInit() {
  // Initializing Robot Configuration. DO NOT REMOVE!
thread s(settingusercontrol);
while (next==false){
  Brain.Screen.clearScreen();
  Brain.Screen.setCursor(3,16);
  Brain.Screen.print("Set Odom Values:");
  Brain.Screen.setCursor(5,16);
  Brain.Screen.print("Starting X:");
  Brain.Screen.print(x);
  Brain.Screen.setCursor(6,16);
  Brain.Screen.print("Starting Y:");
  Brain.Screen.print(y);
  Brain.Screen.setCursor(4,1);
  Brain.Screen.print("Starting Orientation(DEG):");
  Brain.Screen.print(orientation);
  Brain.Screen.setCursor(1,13);
  Brain.Screen.setFillColor(white);
  Brain.Screen.setPenColor(red);
  Brain.Screen.setFont(propL);;
  Brain.Screen.print("4233X (R)");
  Brain.Screen.setFillColor(black);
  Brain.Screen.setFont(monoM);
  Brain.Screen.setPenColor(white);
  Brain.Screen.setCursor(9,1);
  Brain.Screen.print("See https://bit.ly/4233XC for  controls");
Brain.Screen.setCursor(12,9);
  Brain.Screen.setFont(monoL);
Brain.Screen.print("Press (A) to submit");
  Brain.Screen.setFont(monoM);
  wait(1,sec);
}


}

  }
}