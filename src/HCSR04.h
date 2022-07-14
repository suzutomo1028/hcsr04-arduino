#ifndef HCSR04_h
#define HCSR04_h

#include <Arduino.h>

class HCSR04
{
private:
  int trigPin;
  int echoPin;

public:
  void begin(int, int);
  float measureDistance(float);
};

#endif // HCSR04_h
