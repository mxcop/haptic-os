#include <Arduino.h>
#include "HardwareSerial.h"
#include "display/display.h"

#include "perf/core.h"
#include "time.h"

extern "C" {
  #include <bl_gpio.h>
  #include <bl_uart.h>
}

#define SPI_PORT 0
/* Serial Clock */
#define SHARP_SCLK 3
/* Serial Input */
#define SHARP_SI 4
/* Serial Chip Select */
#define SHARP_SCS 14

#define BLACK 0
#define WHITE 1

// LED pins for on-board RGB LED
// 17 = R, 14 = G, B = 11
// schematics for "Pine 64" board: https://files.pine64.org/doc/Pinenut/Pine64%20BL602%20EVB%20Schematic%20ver%201.1.pdf
#define LED_PIN 11

SharpMem display(SHARP_SCLK, SHARP_SI, SHARP_SCS, 230, 303);

void setup() {
  bl_uart_init(0, 16, 7, 255, 255, 115200);

  display.begin();

  printf("Setup complete");
}

void loop() {

  display.refresh();

  delay(5000);
}