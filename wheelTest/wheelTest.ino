
#define supplyVolts 6
#define motorVolts 5

int pwmleftWheelPin = 3;  
int pwmrightWheelPin = 11;  
int directionleftWheelPin = 12;  
int directionrightWheelPin = 13;  


void setup()  
{
  pinMode(pwmleftWheelPin, OUTPUT);
  pinMode(pwmrightWheelPin, OUTPUT);
  pinMode(directionleftWheelPin, OUTPUT);
  pinMode(directionrightWheelPin, OUTPUT);
  setMotors(0, 0);
}

void loop()
{
  
}

void moveForward
{
  setMotors(255, 255);
}

void moveBackward
{
  setMotors(-255, -255);
}

void moveStop
{
  setMotors(0, 0);
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
