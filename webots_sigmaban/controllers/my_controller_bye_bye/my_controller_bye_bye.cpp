// File:          my_controller_bye_bye.cpp
// Date:
// Description:
// Author:
// Modifications:

// You may need to add webots include files such as
// <webots/DistanceSensor.hpp>, <webots/Motor.hpp>, etc.
// and/or to add some other includes
#include <webots/Robot.hpp>
#include <webots/Motor.hpp>
#include <webots/PositionSensor.hpp>

#define TIME_STEP 64

// All the webots classes are defined in the "webots" namespace
using namespace webots;

// This is the main program of your controller.
// It creates an instance of your Robot instance, launches its
// function(s) and destroys it at the end of the execution.
// Note that only one instance of Robot should be created in
// a controller program.
// The arguments of the main function can be specified by the
// "controllerArgs" field of the Robot node
int main(int argc, char **argv) {
  // create the Robot instance.
  Robot *robot = new Robot();


  // You should insert a getDevice-like function in order to get the
  // instance of a device of the robot. Something like:
  Motor *ID_1 = robot->getMotor("right_shoulder_roll");
  Motor *ID_2 = robot->getMotor("left_shoulder_roll");
  Motor *ID_3 = robot->getMotor("right_shoulder_pitch");
  Motor *ID_4 = robot->getMotor("left_shoulder_pitch");
  Motor *ID_5 = robot->getMotor("right_elbow");
  Motor *ID_6 = robot->getMotor("left_elbow");
  Motor *ID_7 = robot->getMotor("right_hip_yaw");
  Motor *ID_8 = robot->getMotor("left_hip_yaw");
  Motor *ID_9 = robot->getMotor("right_hip_roll");
  Motor *ID_10 = robot->getMotor("left_hip_roll");
  Motor *ID_11 = robot->getMotor("right_hip_pitch");
  Motor *ID_12 = robot->getMotor("left_hip_pitch");
  Motor *ID_13 = robot->getMotor("right_knee");
  Motor *ID_14 = robot->getMotor("left_knee");
  Motor *ID_15 = robot->getMotor("right_ankle_pitch");
  Motor *ID_16 = robot->getMotor("left_ankle_pitch");
  Motor *ID_17 = robot->getMotor("right_ankle_roll");
  Motor *ID_18 = robot->getMotor("left_ankle_roll");
  Motor *ID_19 = robot->getMotor("head_yaw");
  Motor *ID_20 = robot->getMotor("head_pitch");
  
  ID_11->setVelocity(0.3);
  ID_12->setVelocity(0.3);
  ID_13->setVelocity(0.1);
  ID_14->setVelocity(0.1);
  ID_15->setVelocity(0.1);
  ID_16->setVelocity(0.1);
  
  PositionSensor *ps_elbowR = robot->getPositionSensor("right_elbow_sensor");
  ps_elbowR->enable(TIME_STEP);

  // Main loop:
  // - perform simulation steps until Webots is stopping the controller
  while (robot->step(TIME_STEP) != -1) {
    // Read the sensors:
    // Enter here functions to read sensor data, like:
    

    // Process sensor data here.

    // Enter here functions to send actuator commands, like:
    ID_3->setPosition(-1.35);
    ID_1->setPosition(-1.55);
    
    ID_6->setPosition(-1.5);
    ID_4->setPosition(0.3);
    
    ID_11->setPosition(0.3);
    ID_12->setPosition(-0.3);        
    ID_13->setPosition(0.5);
    ID_14->setPosition(0.5);
    ID_15->setPosition(-0.3);
    ID_16->setPosition(-0.3);
    
    //motorRightElbow->setPosition(-1);
  
    int val = ps_elbowR->getValue();
    if (val == 0){
       ID_5->setPosition(-2);}
    else if (val == -2){
       ID_5->setPosition(-1);}
       
     std::cout << val << "\n";
       //motorRightElbow->setPosition(-2);
  };

  // Enter here exit cleanup code.

  delete robot;
  return 0;
}
