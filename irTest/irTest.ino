

//define pins. I used pins 4 and 5
#define irLedPin 4          // IR Led on this pin
#define irSensorPin 5       // IR sensor on this pin

int irRead(int readPin, int triggerPin); //function prototype

void setup()
{
  pinMode(irSensorPin, INPUT);
  pinMode(irLedPin, OUTPUT);
  Serial.begin(9600); 
  // prints title with ending line break 
  Serial.println("Program Starting"); 
  // wait for the long string to be sent 
  delay(100); 
}

void loop()
{  
  Serial.println(digitalRead(irSensorPin)); //display the results
  digitalWrite(irLedPin, HIGH);
  delay(100); //wait for the string to be sent
}
