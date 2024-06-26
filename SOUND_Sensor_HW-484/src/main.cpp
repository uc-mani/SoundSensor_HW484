#include <Arduino.h>

#define analogPin 4
#define digitalPin 21
#define LED_PIN 22

void setup() {
  Serial.begin(9600);
  pinMode(digitalPin, INPUT);
  pinMode(analogPin, INPUT);
  pinMode(LED_PIN,OUTPUT);
}

void loop() {
  //Read digital interface
  bool sensor_state = digitalRead(digitalPin);
  int sensor_value = analogRead(analogPin);
  Serial.println("\nSensor State: " + String(sensor_state));
  Serial.println("\nSensor Value: " + String(sensor_value));

  //When output is digital
  if(sensor_state)
  {
    digitalWrite(LED_PIN, HIGH);
    Serial.println("\nDigital Sound Detected");
  }
  else{
    digitalWrite(LED_PIN, LOW);
    //Serial.println("\nSound Not Detected");
  }
  delay(500);

  //When Output is Analog
  if(sensor_value > 1900)
  {
    digitalWrite(LED_PIN, HIGH);
    Serial.println("\nAnalogue Sound Detected");
  }
  else{
    digitalWrite(LED_PIN, LOW);
    //Serial.println("\nSound Not Detected");
  }
  delay(1000);

}
