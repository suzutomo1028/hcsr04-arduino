#include <Arduino.h>
#include "HCSR04.h"

#define TRIG_PIN 3  // D3 pin
#define ECHO_PIN 2  // D2 pin
#define TEMP 25.0   // degC

HCSR04 sensor;

void setup()
{
  Serial.begin(9600);
  while (!Serial) {
    ;
  }

  sensor.begin(TRIG_PIN, ECHO_PIN);
}

void loop()
{
  float distance = sensor.measureDistance(TEMP);

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(1000);
}
