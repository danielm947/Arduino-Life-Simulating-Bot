//  ***************************
//  *      Daniel Moreno      *
//  *      Monday 1pm Lab     *
//  *   Lab 8 - Communication *
//  ***************************
//hello
int wheel = 8;

void setup()

  pinMode(wheel,OUTPUT);
}

void loop()
{
  digitalWrite(wheel, HIGH);
  delay(1000);
  digitalWrite(wheel,LOW);
  delay(2000);
}


