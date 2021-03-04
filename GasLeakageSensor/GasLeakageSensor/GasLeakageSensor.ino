int redLed = 13;
int greenLed = 12;

int buzzer = 11;
int smokeA0 = A0;


void setup()
{
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);

  pinMode(buzzer, OUTPUT);
  pinMode(smokeA0, INPUT);
  Serial.begin(9600);
}

void loop()
{
  int analogSensor = analogRead(smokeA0);

  Serial.print("Gas Level: ");
  Serial.println(analogSensor);
  // Checks if it has reached the threshold value
if(analogSensor > 400)
  {
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
   
    tone(buzzer, 3000, 200);
  }
   
  else
  {
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);
    
    noTone(buzzer);
  }
    
  delay(100);
}
