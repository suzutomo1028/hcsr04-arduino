#include "HCSR04.h"

#define SPEED_OF_SOUND(T) (331.5 + 0.6 * T)  // m/sec

void HCSR04::begin(int trigPin, int echoPin)
{
  this->trigPin = trigPin;
  this->echoPin = echoPin;

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  digitalWrite(trigPin, LOW);
}

float HCSR04::measureDistance(float temp)
{
  float distance = 0;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  unsigned long duration = pulseIn(echoPin, HIGH);  // usec

  if (0 < duration) {
    duration /= 2;
    distance = duration * SPEED_OF_SOUND(temp) * 100 / 1000000;  // cm
  }

  return distance;
}
