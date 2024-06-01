/* This code received angles for the servos, coresponding to the mouse position, and asigns these angles to the servos */

#include <Servo.h>

Servo servoX;
Servo servoY;

void setup() {
  // put your setup code here, to run once:
  servoX.attach(7);
  servoY.attach(8);
  Serial.begin(9600);
  Serial.setTimeout(10); // updates the commands send every 10 ms .Default is 1 second
  // This previous line is required for the system to work
}

void loop() {
  // put your main code here, to run repeatedly:
  
  if (Serial.available() > 0){
    String angle = Serial.readString(); // receive data from python
    
    Serial.println(angle); // doesn't let you access the port, says it's too busy
    
    int X = returnX(angle);
    int Y = returnY(angle);

    servoX.write(180-X); // servoX was turning the opposite direction for some reson. 180-X reverses the direction
    servoY.write(Y);

  }
}

int returnX(String angle){
  angle.remove(angle.indexOf("Y"));
  angle.remove(angle.indexOf("X"), 1);

  return angle.toInt(); // returns X angle
}

int returnY(String angle){ 
  angle.remove(0, angle.indexOf("Y") + 1);

  return angle.toInt(); // returns Y angle
}



