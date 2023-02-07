#include <Arduino.h>

class Display_GFX {

public:
  Display_GFX(int16_t w, int16_t h);

protected:
    uint8_t *buffer;
};
