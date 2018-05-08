//using with putty for pressing without enter on serial moniter 

int dir1PinA = 2;
int dir2PinA = 3;
int speedPinA = A0; // Needs to be a PWM pin to be able to control motor speed
// Motor 2
int dir1PinB = 4;
int dir2PinB = 5;
int speedPinB = A1; // Needs to be a PWM pin to be able to control motor speed
// Motor 3
int dir1PinC = 6;
int dir2PinC = 7;
int speedPinC = A2;// Needs to be a PWM pin to be able to control motor speed
bool stayMotor = false;

void setup() {  // Setup runs once per reset
    Serial.begin(9600);
//Define L298N Dual H-Bridge Motor Controller Pins
    pinMode(dir1PinA,OUTPUT);
    pinMode(dir2PinA,OUTPUT);
    pinMode(speedPinA,OUTPUT);
    pinMode(dir1PinB,OUTPUT);
    pinMode(dir2PinB,OUTPUT);
    pinMode(speedPinB,OUTPUT);    
    pinMode(dir1PinC,OUTPUT);
    pinMode(dir2PinC,OUTPUT);
    pinMode(speedPinC,OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
      char inByte = Serial.read();
      switch (inByte) {
        case 'f' :
          up();
        break;
        
        case 'g' :
          down();
        break;
        
        case ' ' :
          stopAll();
        break;

        case 'w' :
          forward();
        break;

        case 's' :
          back();
        break;

        case 'a' :
          turnLeft();
        break;

        case 'd' :
          turnRight();
        break;

        case 'z' :
          turnLeftBACK();
        break;  

        case 'c' :
          turnRightBACK();
        break;  

        case 'q' :
          turnLeftForward();
        break;

        case 'e' :
          turnRightForward();
        break;
      }    
  }
}

void turnRight(){
    analogWrite(speedPinA, 150);  
    analogWrite(speedPinB, 200);
    digitalWrite(dir1PinA, LOW);
    digitalWrite(dir2PinA, HIGH);
    digitalWrite(dir1PinB, HIGH);
    digitalWrite(dir2PinB, LOW);
    Serial.println("TURN R");
    Serial.println("   ");     
}
void turnRightBACK(){
    analogWrite(speedPinA, 0);  
    analogWrite(speedPinB, 200);
    digitalWrite(dir1PinA, LOW);
    digitalWrite(dir2PinA, HIGH);
    digitalWrite(dir1PinB, LOW);
    digitalWrite(dir2PinB, HIGH);
    Serial.println("TURN R B");
    Serial.println("   ");    
}

void turnRightForward(){
    analogWrite(speedPinA, 0);  
    analogWrite(speedPinB, 200);
    digitalWrite(dir1PinA, LOW);
    digitalWrite(dir2PinA, HIGH);
    digitalWrite(dir1PinB, HIGH);
    digitalWrite(dir2PinB, LOW);
    Serial.println("TURN R B");
    Serial.println("   ");    
}

void turnLeft(){
    analogWrite(speedPinA, 200);  
    digitalWrite(dir1PinA, HIGH);
    digitalWrite(dir2PinA, LOW);
    analogWrite(speedPinB, 150);
    digitalWrite(dir1PinB, LOW);
    digitalWrite(dir2PinB, HIGH);
//     digitalWrite(dir1PinB, HIGH);
//     digitalWrite(dir2PinB, LOW); 
     Serial.println("TURN L");
     Serial.println("   ");
}

void turnLeftBACK(){
  
    analogWrite(speedPinA, 200);  
    digitalWrite(dir1PinA, LOW);
    digitalWrite(dir2PinA, HIGH);
    analogWrite(speedPinB, 0);
    digitalWrite(dir1PinB, HIGH);
    digitalWrite(dir2PinB, LOW); 
    Serial.println("TURN L B");
    Serial.println("   ");
}

void turnLeftForward(){
    
    analogWrite(speedPinA, 200);  
    digitalWrite(dir1PinA, HIGH);
    digitalWrite(dir2PinA, LOW);
    analogWrite(speedPinB, 0);
    digitalWrite(dir1PinB, HIGH);
    digitalWrite(dir2PinB, LOW); 
    Serial.println("TURN L B");
    Serial.println("   ");
}

void forward(){
  analogWrite(speedPinA, 255);
  digitalWrite(dir1PinA, HIGH);
  digitalWrite(dir2PinA, LOW);
  analogWrite(speedPinB, 255);
  digitalWrite(dir1PinB, HIGH);
  digitalWrite(dir2PinB, LOW);
  Serial.println("Forward");
  Serial.println("   ");
}

void back(){
  analogWrite(speedPinA, 150);
  digitalWrite(dir1PinA, LOW);   
  digitalWrite(dir2PinA, HIGH);
  analogWrite(speedPinB, 150);
  digitalWrite(dir1PinB, LOW);
  digitalWrite(dir2PinB, HIGH);
  Serial.println("BACKKKK!!!");
  Serial.println("   ");
}

void up(){
   analogWrite(speedPinC, 255);
   digitalWrite(dir1PinC, LOW);
   digitalWrite(dir2PinC, HIGH);
   Serial.println("Motor Up");
   Serial.println("   ");
}

void down(){
  analogWrite(speedPinC, 150);
  digitalWrite(dir1PinC, HIGH);
  digitalWrite(dir2PinC, LOW);
  Serial.println("Motor Down");
  Serial.println("   ");
}

void stopAll(){
  analogWrite(speedPinA, 0);
  digitalWrite(dir1PinA, LOW);
  digitalWrite(dir2PinA, HIGH);
  
  analogWrite(speedPinB, 0);
  digitalWrite(dir1PinB, LOW);
  digitalWrite(dir2PinB, HIGH);
  
  analogWrite(speedPinC, 0);
  digitalWrite(dir1PinC, LOW);
  digitalWrite(dir2PinC, HIGH);
  Serial.println("Motor Stopped");
}

