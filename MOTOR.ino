//Define sensors and servos

#include <Servo.h> //Includes servo library

Servo finger1, finger2, finger3, finger4, finger5;

int servoPin1 = 5;
int servoPin2 = 6;
int servoPin3 = 9;
int servoPin4 = 10;
int servoPin5 = 3;

int flexPin1 = A0;
int flexPin2 = A1;
int flexPin3 = A2;
int flexPin4 = A3;
int flexPin5 = A4;

void setup()
{
  
  /* set each servo pin to output; I'm not acutally sure if this is
  even necessary, but I did just in case it is */
  pinMode(servoPin1, OUTPUT);
  pinMode(servoPin2, OUTPUT);
  pinMode(servoPin3, OUTPUT);
  pinMode(servoPin4, OUTPUT);
  pinMode(servoPin5, OUTPUT);
  
  //Set each flex sensor pin to input: this is necessary
  pinMode(flexPin1, INPUT);
  pinMode(flexPin2, INPUT);
  pinMode(flexPin3, INPUT);
  pinMode(flexPin4, INPUT);
  pinMode(flexPin5, INPUT);

    //Attach the servo objects to their respective pins
  finger1.attach(servoPin1);
  finger2.attach(servoPin2);
  finger3.attach(servoPin3);
  finger4.attach(servoPin4);
  finger5.attach(servoPin5);
 Serial.begin(9600);
  
  
}

  


void loop()
{
  //Defines analog input variables
  int flex1 = analogRead(flexPin1);
  int flex2 = analogRead(flexPin2);
  int flex3 = analogRead(flexPin3);
  int flex4 = analogRead(flexPin4);
  int flex5 = analogRead(flexPin5);
  Serial.println(flex1);
  Serial.println(flex2);
  Serial.println(flex3);
  Serial.println(flex4);
  Serial.println(flex5);  
  Serial.println("--");
  delay(750);
  
  
  /* Defines "pos" variables as being proportional to the flex inputs.
  The 400 to 700 value range seemed adequate for my sensors, but you can change
  yours accordingly. */
  int pos1 = map(flex1, 0, 500, 0, 360);
  pos1 = constrain(pos1, 0, 360);
  int pos2 = map(flex2, 200, 500, 0, 360);
  pos2 = constrain(pos2, 0, 360);
  int pos3 = map(flex3, 200, 300, 0, 360);
  pos3 = constrain(pos3, 0, 360);
  int pos4 = map(flex4, 200, 500, 0, 360);
  pos4 = constrain(pos4, 0, 360);
  int pos5 = map(flex5, 200, 300, 0, 360);
  pos5 = constrain(pos5, 0, 360);


//pos 5 = index
//pos 3 = middle
//pos 2 = 
//pos 4 = thumb
//pos 1 = 

//receiver 3 = index
//receiver 5 = pinky
//receiver 6 = ring
//receiver 9 = middle
//receiver 10 = thumnb
  Serial.print(pos1);
  Serial.print(" : ");
  Serial.print(pos2);
  Serial.print(" : ");
  Serial.print(pos3);
  Serial.print(" : ");
  Serial.print(pos4);
  Serial.print(" : ");
  Serial.println(pos5);

  finger1.write(pos1);
  finger2.write(pos2);
  finger3.write(pos3);
  finger4.write(pos4);
  finger5.write(pos5);
}

