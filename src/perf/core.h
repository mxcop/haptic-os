#include <stdint.h>

int get_temp(
  float *temp,      //  Pointer to float to store the temperature
  uint8_t log_flag  //  0 to disable logging, 1 to enable logging
);