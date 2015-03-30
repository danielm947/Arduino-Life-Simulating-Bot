// LIGHT SENSOR TEST

// THE LIGHT THAT BRIGHTENS UP DISPLAYS THE DIRECTION OF TRAVEL. IF THE SHADOW IS IN THE FRONT THE WHEELS SHOULD REVERSE.
// IF THE SHADOW IS IN THE BACK THEN THE CAR SHOULD GO. IF THE CAR IS IN ALL DARK IT SHOULD FREEZE AND NOT MOVE. IF ITS
// ENTIRELY IN LIGHT IT SHOULD RESUME WHATEVER STATE IT WAS IN (i.e. GO TO REPRODUCE OR GROW)

int go = 9;        //REPLACE WITH MOVE FORWARD METHOD IN FINAL VERSION
int halt = 8;      //HALT IS USED TO STOP THE CAR, OR AS A PLACE HOLDER TO CHECK READINGS AGAIN 
int reverse = 7;   //REPLACE WITH MOVE BACKWARDS METHOD IN FINAL VERSION
int frontSensor = A5;  //PHOTORESISTOR IN FRONT OF CAR
int backSensor = A0;   //PHOTORESISTOR IN BACK OF CAR

void setup()  
{
  pinMode(go, OUTPUT);
  pinMode(halt, OUTPUT);
  pinMode(reverse, OUTPUT);
  pinMode(frontSensor, INPUT);   //POSITIONED by 0 ON BREADBOARD
  pinMode(backSensor, INPUT);    //POSITIONED by 60 ON BREADBOARD
  Serial.begin(9600);    //setup for printing to serial monitor
}

void loop()
{
 int frontReading = analogRead(frontSensor);
 int backReading = analogRead(backSensor);
 
 /* DEBUG
 Serial.print("Front: ");
 Serial.println(frontReading);
 Serial.print("Back: ");
 Serial.println(backReading);
 delay(500);
*/
 if(frontReading>400 && backReading<=399)  //DARK IN FRONT
  {
   digitalWrite(go,LOW);
   digitalWrite(halt,HIGH);
   delay(1000);
   digitalWrite(halt,LOW);
   digitalWrite(reverse,HIGH);
  }
 
 else if(frontReading<=399 && backReading>400) //DARK IN THE BACK
  {
   digitalWrite(reverse,LOW);
   digitalWrite(halt,HIGH); 
   delay(1000);
   digitalWrite(halt,LOW);
   digitalWrite(go,HIGH);
  } 
  
  else if(frontReading>400 && backReading>400)  //COMPLTLY IN THE DARK --- FREEZE
  {
   digitalWrite(go,LOW);
   digitalWrite(reverse,LOW);
   digitalWrite(halt,LOW);
  } 
 
 else    //COMPLETLY IN THE LIGHT -- RESUME NORMAL ACTION
 {
    //resume action
   digitalWrite(go,HIGH);
   digitalWrite(reverse,HIGH);
   digitalWrite(halt,HIGH);
 }
}
