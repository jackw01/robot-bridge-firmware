// robot-bridge-firmware
// Copyright 2018 jackw01. Released under the MIT License (see LICENSE for details).

#pragma once

// Type for 3D vector data - taken from Adafruit Unified Sensor with some fields removed
typedef struct{
  union {
    float v[3];
    struct {
      float x;
      float y;
      float z;
    };
    struct {
      float roll;
      float pitch;
      float heading;
    };
  };
} vec3;

// Fast power of 10 for low numbers
static uint8_t pow10(uint8_t n) {
  switch (n) {
    case 0:
      return 1;
    case 1:
      return 10;
    case 2:
      return 100;
    default:
      return 1;
  }
}

// Get free RAM - found somewhere on Stackoverflow
static int getFreeRAM() {
  extern int __heap_start, *__brkval;
  int v;
  return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval);
}
