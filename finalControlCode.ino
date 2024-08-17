#include "Servo.h"
#include "math.h"

// servo objects
Servo servo1;   //shoulder servo
Servo servo2;   //elbow servo
Servo servo3;   //wrist servo 
Servo servo4;   //gripper servo

//ultrasonic pins
const int trigPin = 2 ;   
const int echoPin = 4 ;

float theta1_rad ;   //angle in radian
float theta1_deg ;   //angle in degrees
float theta2_rad ;   //angle in radian
float theta2_deg ;   //angle in degrees

//values for for loops
int increasing_val ;
int decreasing_val ;


//final angles calculations
float m3 ;
float m4 ;
float m5 ;

float duration;    //the travel duration for the wave between trigger and echo
int distance;      //from ultrasonic
int x = 0;
void setup() {
  servo1.attach(9);    //shoulder pin
  servo2.attach(10);   //elbow pin
  //servo3.attach(3);
  servo4.attach(11);   //gripper pin
  pinMode(trigPin, OUTPUT);  
  pinMode(echoPin, INPUT);  
  Serial.begin(9600); 
  servo4.write(180);

  //servo3.write(0);
  servo2.write(180);   //elbow initial
  servo1.write(0);     //shoulder initial
}
void loop() {
  //servo3.write(0);
  servo2.write(180);   //elbow initial
  servo1.write(0);     //shoulder initial

  //ultrasonic code
  delayMicroseconds(2);  
  digitalWrite(trigPin, HIGH);  
  delayMicroseconds(10);  
  digitalWrite(trigPin, LOW); 

  //measuring the distance
  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;    //divide the distance by 2 because the wave travels back and forth
  distance = distance+11;           // base radius + distance between base and ultrasonic = 11
  Serial.print("Distance: ");
  Serial.println(distance);
  
  delay(2000);
  if(distance<24&&distance>5)       //in a range the arm can reach
  {
    theta1_rad = (.5*distance)/12;           //trigometry calculations
    theta1_deg  =acos(theta1_rad)*180/PI;     
    m3=90-theta1_deg;
  
    for( increasing_val =0 ; increasing_val < m3 ;increasing_val ){         //shoulder elbow has a high torque value so this loop is needed
      servo1.write(increasing_val);             //increasing theta1 by one until it equals shoulder angle
      delay(50);
      increasing_val = increasing_val+1;
    }
    Serial.println(increasing_val);
    //Serial.println(m3);
    theta2_rad = (.5*distance)/12;          //theta2 in radian through trigmotery calculations
    theta2_deg =(asin(theta2_rad)*180/PI)*2;   
    m4 = theta2_deg;
    for( decreasing_val =180 ; decreasing_val>m4 ;decreasing_val ){          //small previous for loop except the initial value of the elbow is 180
      servo2.write(decreasing_val);
      delay(50);
      decreasing_val=decreasing_val-1;
    }
    Serial.println(decreasing_val);
    servo2.write(decreasing_val);
    m5=180-theta1_deg;
    Serial.println(m5);
    if(x<1)
    {
      Serial.print("open");
      servo4.write(0); 
      x=1;
    }
    else if (x>0){
    Serial.print("close");
    servo4.write(180); 
    x=0;
    }
    //servo3.write(20);
    delay(5000);

    for( increasing_val  ; increasing_val>0 ; increasing_val-- ){
      servo1.write(increasing_val);
      delay(50);
    }  
    for(decreasing_val  ; decreasing_val < 180 ; decreasing_val ++ ){
      servo2.write(decreasing_val);
      delay(50);
    }
  }
}
