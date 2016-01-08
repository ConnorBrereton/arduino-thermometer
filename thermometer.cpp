//analog pin
const int sensorPin = A0;
//initial temp
const float baselineTemp = 20.0;

void setup() {
  Serial.begin(9600);
  for(int pinNumber = 2; pinNumber < 5; pinNumber ++)
  {
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }

}

void loop() 
{
  int sensorVal = analogRead(sensorPin);
  Serial.print("Sensor Value: ");
  Serial.print(sensorVal);

  float voltage = (sensorVal/1024.0) * 5.0;
  Serial.print("Volts: ");
  Serial.print(voltage);

  Serial.print("degrees C: ");
  float temperature = (voltage - .5) * 100;
  Serial.println(temperature);

  //no change -- no lights
  if(temperature < baselineTemp)
  {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
  //small change -- 1 light
  else if(temperature >= baselineTemp+2 && temperature < baselineTemp+4)
  {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
  //medium change -- 2 lights
  else if(temperature >= baselineTemp+2 && temperature < baselineTemp+6)
  {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  }
  //lots of change -- 3 lights
  else if(temperature >=  baselineTemp+6)
  {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }
  //units are ms
  delay(50);

  
}
