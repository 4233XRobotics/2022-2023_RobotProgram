# 2022-2023_RobotProgram
This is a vex robotics program for a vex v5 robot. This is coded for the season 2022-2023  Spin Up on 4233X's robot. As long as you mention us, you  may use some of the code on your own robot.This is organized in folders named "ButtonControls","AutonControls",and "Odometry". Each with their own namespaces, her is the general file structrure:
include-
------->files included into main.cpp
src-
------>main.cpp Responsible for initalizing the robot
------>usercontrol.h Responsible for controling the robot
------>Display.h Controls Display Functions
------>ButtonControls
-------> Important files for the specific game Spin Up(kinda useless for other seasons)
------>AutonControls
------->AutonFunctions.h Contains Our Pid auton files along with some simple functions that control the robot
------->AutonMainFunction Uses the auton selection variable (in button controls) to see which auton the user wants to run and uses the functions neccesary to do it 
------->Autons.h A main file for the Auton namespace that is included for the including chain for the Auton Namespace to the main.cpp file
------->The rest are auton files for this game (AutonTemplate.h for basic structure
------>Odometry
------->MainOdom.h Includes all of the other odomfiles and hosts the function that tracts the robot on the field using 1 right side encoder and 1 middle encoder with a inertial sensor tuned heading with constants
------->Orientation.h Constantly Updates a correct heading for the robot
------->SetOdom.h A File that makes a display for the start of the program(Easily Removed in main.cpp)
Now that you understant the general structure of the files
Consider the following:
-> This code is built for a SPECIFIC ROBOT for the 2022-2023 SPIN UP GAME so this might not work for your robot
-> The odometry may not work for future challenges
-> Some things may be inefficent because it is done by a middle school student.
Knowing all that you can now freely use my code with mentions!
