int potPin = A0;         
int motionSwitch = 2;    
int motorPin = 9;        
int greenLED = 3;        
int redLED = 4;          
int hazardLED = 5;       

int weightLimit = 700;   // 70% Overload Threshold
unsigned long overloadStartTime = 0;
bool isTimerRunning = false;
bool limpModeActive = false;

void setup() {
  pinMode(motionSwitch, INPUT);
  pinMode(motorPin, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(hazardLED, OUTPUT);
}

void loop() {
  int currentWeight = analogRead(potPin);
  bool isMoving = digitalRead(motionSwitch); 

  // STATE 1: SAFE WEIGHT
  if (currentWeight <= weightLimit) {
    digitalWrite(greenLED, HIGH);
    digitalWrite(redLED, LOW);
    digitalWrite(hazardLED, LOW);
    analogWrite(motorPin, 255); // Motor Full Speed
    
    isTimerRunning = false;
    limpModeActive = false;
  } 
  
  // STATE 2: OVERLOAD DETECTED
  else {
    digitalWrite(greenLED, LOW);

    // MODE A: STATIONARY (Hard Lock)
    if (isMoving == LOW) {
      digitalWrite(redLED, HIGH);
      digitalWrite(hazardLED, LOW);
      analogWrite(motorPin, 0); // Motor Stops
      
      isTimerRunning = false;
      limpModeActive = false;
    } 
    
    // MODE B: MOVING (Limp Mode Logic)
    else {
      if (!isTimerRunning) {
        overloadStartTime = millis();
        isTimerRunning = true;
      }

      // Check if 5 seconds have passed
      if (millis() - overloadStartTime > 5000) {
        limpModeActive = true;
      }

      if (limpModeActive) {
        digitalWrite(redLED, HIGH);
        analogWrite(motorPin, 60); // Motor Slows Down (Limp Mode)
        
        // Flash Hazard LED
        if ((millis() / 500) % 2 == 0) {
          digitalWrite(hazardLED, HIGH);
        } else {
          digitalWrite(hazardLED, LOW);
        }
      } 
      else {
        // Inside the 5-second grace period (Ignore bump)
        analogWrite(motorPin, 255); 
        digitalWrite(redLED, LOW);
      }
    }
  }
}