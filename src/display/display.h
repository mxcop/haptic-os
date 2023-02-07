#include "spi.h"
#include "gfx.h"
#include <Arduino.h>

#if defined(RAMSTART) && defined(RAMEND) && ((RAMEND - RAMSTART) < 4096)
#warning "Display may not work on devices with less than 4K RAM"
#endif

#define SHARPMEM_BIT_WRITECMD (0x01) // 0x80 in LSB format
#define SHARPMEM_BIT_VCOM (0x02)     // 0x40 in LSB format
#define SHARPMEM_BIT_CLEAR (0x04)    // 0x20 in LSB format

/**
 * @brief Class to control a Sharp memory display
 *
 */
class SharpMem : public Display_GFX {
public:
  SharpMem(uint8_t clk, uint8_t mosi, uint8_t cs, uint16_t w = 96,
                    uint16_t h = 96, uint32_t freq = 2000000);
  SharpMem(SPIClass *theSPI, uint8_t cs, uint16_t w = 96,
                    uint16_t h = 96, uint32_t freq = 2000000);
  boolean begin();
  //void drawPixel(int16_t x, int16_t y, uint16_t color);
  //uint8_t getPixel(uint16_t x, uint16_t y);
  //void clearDisplay();
  void refresh(void);
  //void clearDisplayBuffer();

private:
  SPIClass *spidev = NULL;
  uint8_t *sharpmem_buffer = NULL;
  uint8_t _cs;
  uint8_t _sharpmem_vcom;
};