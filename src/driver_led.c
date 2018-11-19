//#include "driver_led.h"
#include "mocksArduino.h" // bug, should use real Arduino.h

void
driver_led_init(void)
{
  pinMode(10, OUTPUT);
}

