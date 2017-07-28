  //Define sensors and servos

#include <Servo.h> //Includes servo library
 //Includes servo library
 #include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


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

int pos1;
int pos2;
int pos3;
int pos4;
int pos5;
int START;

int Hand;
int personScore = 0;
int compScore = 0;
int type;
// rock= 2 paper= 1 scissor=3
 void setup(){
  //Attach the servo objects to their respective pins
  finger1.attach(servoPin1);
  finger2.attach(servoPin2);
  finger3.attach(servoPin3);
  finger4.attach(servoPin4);
  finger5.attach(servoPin5);

    pos1= 00;
    pos2= 00;
    pos3= 430;
    pos4= 0;
    pos5= 400;
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
 Serial.begin(9600);
 {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("START GAME!");
  delay(3000);
}

  // put your setup code here, to run once:
 // set up the LCD's number of columns and rows:
 // lcd.begin(16, 2);
  // Print a message to the LCD.
  //lcd.print("CLICK TO START!");

 }

void loop() {
  Serial.println("Begin");
  
  
  int flex1 = analogRead(flexPin1);
  int flex2 = analogRead(flexPin2);
  int flex3 = analogRead(flexPin3);
  int flex4 = analogRead(flexPin4);
  int flex5 = analogRead(flexPin5);
Serial.print (pos1);
  
  Serial.println("START");
    lcd.clear();
    lcd.print("3");
    delay (1000);
    lcd.print("2");
    delay (1000);
    lcd. print ("1");
delay (1000);
   lcd.print ("SHOOT");
   delay(1000);
 type= random(1,4);

 Serial.print(type);  
  if (type == 1) {
    pos1 =0;
    pos2 =0;
    pos3 =0;
    pos4 =500;
    pos5 =0;
  
  }
  else if (type == 2) {
    pos1 =500;
    pos2 =500;
    pos3 =500;
    pos4 =0;
    pos5 =500;
  
  }
  else if (type == 3) {
    pos1= 00;
    pos2= 00;
    pos3= 430;
    pos4= 430;
    pos5= 400;
  }
  else{
  pos1= 00;
    pos2= 00;
    pos3= 430;
    pos4= 0;
    pos5= 400;
  }
   finger1.write(pos1);
  finger2.write(pos2);
  finger3.write(pos3);
  finger4.write(pos4);
  finger5.write(pos5);

  if (flex1>=960 && flex1<=1023, flex2>=797 && flex2<=880, flex3>=288 && flex3<=303, flex4>=340 && flex4<=360, flex5>=260 && flex5<=280)
{Serial.println("R"); 
Hand = 2;
//2 = rock
}
else if (flex1>=970 && flex1<=1023, flex2>=970 && flex2<=1020, flex3>=490 && flex3<=510, flex4>=330 && flex4<=370, flex5>= 410 && flex5<=432) //scissors
{Serial.println("S");
Hand = 3;
//3 = scissor
}
else if (flex1>=960 && flex1<=1040, flex2>=970 && flex2<=1040, flex3>=460 && flex3<=490, flex4>=290 && flex4<=310, flex5>=400 && flex5<=460) //paper
{Serial.println("P");
Hand = 1;
//1 = paper
}

//rock= 2 paper= 1 scissor=3

if  (Hand == type) {
  lcd. clear ();
  lcd. print ("TIE");
}
else if ((Hand ==2 && type == 3) || (Hand == 1 && type == 2) || (Hand == 3 && type == 1)){
  personScore += 1;
}
 else if ((type ==2 && Hand == 3) || (type == 1 && Hand == 2) || (type == 3 && Hand == 1)){
  compScore += 1;
}



lcd.clear();
lcd. print ("YOU:" + String(personScore) + "   " +  "COMP:" + String(compScore));
    pos1= 00;
    pos2= 00;
    pos3= 430;
    pos4= 0;
    pos5= 400;
     delay (7000);
     Serial.println(personScore);
  


}

