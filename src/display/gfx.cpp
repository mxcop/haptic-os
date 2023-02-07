#include "gfx.h"

Display_GFX::Display_GFX(int16_t w, int16_t h) {
    uint32_t bytes = ((w + 7) / 8) * h;
    if ((buffer = (uint8_t *)malloc(bytes))) {
        memset(buffer, 0, bytes);
    }
}