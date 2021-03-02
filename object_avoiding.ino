//Created By: Aditya Bangalore
//Date: March 25, 2020
//This code was uploaded to the Arduino Uno for running the obstacle avoiding robot.

#include <AFMotor.h>  //Imports library for running the motor shield - download this library if not previously installed

#define enablepin 5   //Defines the enable pin on the KY-032 as pin 5 on Arduino
#define IR 4          //Defines the output pin on the KY-032 as pin 4 on Arduino. Renames the pin to "IR".

AF_DCMotor backright(1);  //Assigns the back right motor to the M1 pins on the motor shield
AF_DCMotor frontright(2); //Assigns the front right motor to the M2 pins on the motor shield
AF_DCMotor frontleft(3);  //Assigns the front left motor to the M3 pins on the motor shield
AF_DCMotor backleft(4);   //Assigns the back left motor to the M4 pins on the motor shield

void Stop() {             //Creates a Stop() function that stops the robot's wheels
  backright.run(RELEASE);
  backleft.run(RELEASE);
  frontright.run(RELEASE);
  frontleft.run(RELEASE);
}

void Forward() {          //Creates a Forward() function that drives the robot forward
  backright.run(FORWARD);
  backleft.run(FORWARD);
  frontright.run(FORWARD);
  frontleft.run(FORWARD);
}

void Backward() {         //Creates a Backward() function that drives the robot backward
  backright.run(BACKWARD);
  backleft.run(BACKWARD);
  frontright.run(BACKWARD);
  frontleft.run(BACKWARD);
}

void Right() {            //Creates a Right() function that turns the robot to the right
  backright.run(BACKWARD);
  frontright.run(BACKWARD);
  backleft.run(FORWARD);
  frontleft.run(FORWARD);  
}

void Left() {             //Creates a Left() function that turns the robot to the left
  backright.run(FORWARD);
  frontright.run(FORWARD);
  backleft.run(BACKWARD);
  frontleft.run(BACKWARD);
}

void setup() {            //Setup function: sets the speed of each motor to the maximum value of 255. Begins the serial monitor.
  backright.setSpeed(255);
  frontright.setSpeed(255);
  frontleft.setSpeed(255);
  frontleft.setSpeed(255);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(enablepin, HIGH);    //Send a HIGH signal to the enable pin of the KY-032
  if(digitalRead(IR) == LOW) {      //If the reading on the IR pin is low...
    Serial.println("Object Detected");  //Print to the serial monitor that there was an object detected
    Stop();                         //Stop the car
    Right();                        //Turn right
    delay(2000);                    //Keep turning for two seconds
    if(digitalRead(IR) == LOW) {    //If the reading on the IR pin is still low...
      Stop();                       //Stop the car
      Left();                       //Turn left
      delay(4000);                  //Keep turning for four seconds
    }
  }
  else {                            //If the reading on the IR pin is high or something else...
    Serial.println("No Object");    //Print to the serial monitor that there was no object detected
    Forward();                      //Continue moving forward
  }
}
