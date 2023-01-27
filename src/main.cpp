#include "perf/core.h"
#include "time.h"

extern "C" {
  #include <bl_gpio.h>
  #include <bl_uart.h>
}

// LED pins for on-board RGB LED
// 17 = R, 14 = G, B = 11
// schematics for "Pine 64" board: https://files.pine64.org/doc/Pinenut/Pine64%20BL602%20EVB%20Schematic%20ver%201.1.pdf
#define LED_PIN 14

void setup() {
  bl_uart_init(0, 16, 7, 255, 255, 115200);
}

unsigned char duty = 0;

void loop() {
  //  Temperature in Celsius
  float temp = 0;

  //  Read the Internal Temperature Sensor as Float
  get_temp(
      &temp, //  Temperature in Celsius
      0      //  0 to disable logging, 1 to enable logging
  );

  // Show the temperature
  printf("Core Temp: %f C\r\n", temp);

  // Wait for 1000 ms
  delay(1000);
}