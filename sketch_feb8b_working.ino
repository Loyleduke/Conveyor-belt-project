#include <Servo.h>

const int s2 = 6; const int s3 = 8; const int outPin = 7;  
const int enA = 5; const int in1 = 3; const int in2 = 4;          
const int servoPin = 10;    
Servo myServo;


int blueThreshold = 130; 
int redThreshold = 80;  

void setup() {
  Serial.begin(9600);
  pinMode(s2, OUTPUT); pinMode(s3, OUTPUT); pinMode(outPin, INPUT);
  pinMode(enA, OUTPUT); pinMode(in1, OUTPUT); pinMode(in2, OUTPUT);
  
  // Set direction once
  digitalWrite(in1, HIGH); digitalWrite(in2, LOW);
  
  // FORCE STOP at start
  stopConveyor(); 

  myServo.attach(servoPin);
  myServo.write(90); 
  
  Serial.println("--- SYSTEM INITIALIZED ---");
}

void loop() {
  // 1. READ SENSOR
  digitalWrite(s2, LOW); digitalWrite(s3, LOW);
  delay(30); // Extra time for sensor to stabilize
  int r = pulseIn(outPin, LOW, 20000); 

  digitalWrite(s2, LOW); digitalWrite(s3, HIGH);
  delay(30);
  int b = pulseIn(outPin, LOW, 20000);

  // 2. LOGIC: Is an object actually there? (Both R and B must be low)
  // prevents "ghosting" from room lights.
  if (r < 150 && b < 150) { 
    
    // BLUE CHECK: b must be the lowest AND under threshold
    if (b < blueThreshold && b < r - 30) {
      Serial.print("REAL BLUE DETECTED: "); Serial.println(b);
      executeMission("BLUE");
    } 
    // RED CHECK: r must be the lowest AND under threshold
    else if (r < redThreshold && r < b - 30) {
      Serial.print("REAL RED DETECTED: "); Serial.println(r);
      executeMission("RED");
    }
  }

  delay(100); 
}

void executeMission(String color) {
  // START
  analogWrite(enA, 255); 
  
  if (color == "BLUE") {
    Serial.println("Action: Moving to Servo...");
    delay(3500);           
    
    
    myServo.write(20);    
    delay(3500);           
    myServo.write(90);     
    delay(500);
    Serial.println("Action: Clearing Belt...");
    analogWrite(enA, 255); 
    delay(2000);
  } else {
    Serial.println("Action: Running Red to end...");
    delay(11500);          
  }

  stopConveyor(); // FINAL FORCE STOP
  Serial.println("--- MISSION COMPLETE: SENSOR IDLE ---");
  delay(3000); 
}

// Dedicated function to make sure the motor driver gets the message
void stopConveyor() {
  analogWrite(enA, 0);
  digitalWrite(in1, LOW); // Pulling both pins LOW acts as a brake
  digitalWrite(in2, LOW);
  delay(100);
  digitalWrite(in1, HIGH); // Reset direction for next time
}
 