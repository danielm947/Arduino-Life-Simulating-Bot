
#define supplyVolts 6
#define motorVolts 5

int pwmleftWheelPin = 3;  
int pwmrightWheelPin = 11;  
int directionleftWheelPin = 12;  
int directionrightWheelPin = 13;
int frontSensor = A5;  //PHOTORESISTOR IN FRONT OF CAR
int backSensor = A0;   //PHOTORESISTOR IN BACK OF CAR

void setup()  
{
  pinMode(pwmleftWheelPin, OUTPUT);
  pinMode(pwmrightWheelPin, OUTPUT);
  pinMode(directionleftWheelPin, OUTPUT);
  pinMode(directionrightWheelPin, OUTPUT);
  setMotors(0, 0);
  pinMode(frontSensor, INPUT);   //POSITIONED by 0 ON BREADBOARD
  pinMode(backSensor, INPUT);    //POSITIONED by 60 ON BREADBOARD
  Serial.begin(9600);    //setup for printing to serial monitor
}

void loop()
{
  int frontReading = analogRead(frontSensor);
 int backReading = analogRead(backSensor);
 
 if(frontReading>400 && backReading<=399)  //DARK IN FRONT
  {
    moveBackward();
    Serial.println("Dark in front:");
  }
 
 else if(frontReading<=399 && backReading>400) //DARK IN THE BACK
  {
    moveForward();
    Serial.print("Dark in back: ");
  } 
  
  else if(frontReading>400 && backReading>400)  //COMPLTLY IN THE DARK --- FREEZE
  {
    moveStop();
    Serial.print("All in darkness: ");
  } 
 
 else    //COMPLETLY IN THE LIGHT -- RESUME NORMAL ACTION
 {
    //resume action
    Serial.println("Resuming action");
 }
}

void moveForward
{
  setMotors(255, 255);
  Serial.println("Moving forward");
}

void moveBackward
{
  setMotors(-255, -255);
  Serial.println("Moving backward");
}

void moveStop
{
  setMotors(0, 0);
  Serial.println("Stopped");
}

void setMotors(int rightWheel, int rightWheel)
{
   int vleftWheel = abs(leftWheel) * motorVolts / supplyVolts;
   int vrightWheel = abs(rightWheel) * motorVolts / supplyVolts;
   int dleftWheel = (leftWheel > 0);
   int drightWheel = (rightWheel > 0);
   if (vleftWheel < 50)
   {
     vleftWheel = 0; 
   }
   if (vrightWheel < 50)
   {
     vrightWheel = 0; 
   }
   analogWrite(pwmleftWheelPin, vleftWheel);
   analogWrite(pwmrightWheelPin, vrightWheel);
   digitalWrite(directionleftWheelPin, dleftWheel);
   digitalWrite(directionrightWheelPin, drightWheel);
}
