#include <Servo.h>

Servo myservo;  

// Ultrasonic pins
const int trigPin = 2;
const int echoPin = 3;

// Bin level
const int binLevelPin = A0;  
int binLevel;
int threshold = 700;  

// LEDs
const int greenLED = 8;
const int blueLED  = 9;
const int redLED   = 12;

// Buzzer
const int buzzerPin = 10;

long duration;
int distance;

void setup() 
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  
  pinMode(buzzerPin, OUTPUT);

  myservo.attach(7);
  myservo.write(3); 

  Serial.begin(9600);
}

void loop() 
{
  // Read bin level
  binLevel = analogRead(binLevelPin);

  if(binLevel > threshold) {
    digitalWrite(redLED, HIGH);
    digitalWrite(greenLED, LOW);
    digitalWrite(blueLED, LOW);
    myservo.write(3); 
    
    digitalWrite(buzzerPin, HIGH);
    delay(500);
    digitalWrite(buzzerPin, LOW);
    delay(500);
    return;
  } 
  else {
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, HIGH);
    digitalWrite(buzzerPin, LOW);
  }

  // Ultrasonic
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  int D = map(distance, 10, 1095, 2, 400);

  if(D < 60) {
    myservo.write(93);
    digitalWrite(blueLED, HIGH);
    digitalWrite(greenLED, LOW);
    delay(1000);
  } 
  else {
    myservo.write(3);
    digitalWrite(blueLED, LOW);
    digitalWrite(greenLED, HIGH);
  }

  delay(200);
}
