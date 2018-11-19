/*
 * Excerpt from Arduino.h for mocking purposes
 */

#ifndef MOCKS_ARDUINO_H
#define MOCKS_ARDUINO_H

#include <stdbool.h>
#include <stdint.h>

#include "unity_fixture.h"


#define HIGH 0x1
#define LOW  0x0

#define INPUT 0x0
#define OUTPUT 0x1
#define INPUT_PULLUP 0x2

#define LSBFIRST 0
#define MSBFIRST 1

typedef bool boolean;
typedef uint8_t byte;

void pinMode(uint8_t, uint8_t);
void digitalWrite(uint8_t, uint8_t);
int digitalRead(uint8_t);

unsigned long millis(void);

void shiftOut(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder, uint8_t val);
uint8_t shiftIn(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder);

typedef enum {
  mocks_pinMode,
  mocks_digitalWrite,
  mocks_digitalRead,
  mocks_millis,
  mocks_shiftOut,
  mocks_shiftIn,
} mocks_kind_e;

typedef struct {
  uint8_t pin;
  uint8_t mode;
} mocks_pinMode_t;

typedef struct {
  uint8_t pin;
} mocks_digitalRead_t;

#endif /* MOCKS_ARDUINO_H */


