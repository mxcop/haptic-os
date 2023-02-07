#include "display.h"

/**************************************************************************
    Sharp Memory Display Connector (Pins are flipped because my display faces forwards!)
    -----------------------------------------------------------------------
    Pin   Function        Notes
    ===   ==============  ===============================
     1    VSSA     (GND)
     2    VSS      (GND)
     3    EXTMODE  (5V)   COM Inversion Select (Low = SW clock/serial)
     4    VDD      (5V)   5.0V
     5    VDDA     (5V)   5.0V
     6    DISP            Display On(High)/Off(Low)
     7    EXTCOMIN        External COM Inversion Signal
     8    SCS             Serial Chip Select
     9    SI              Serial Data Input
     10   SCLK            Serial Clock

 **************************************************************************/

#define TOGGLE_VCOM                                                            \
  do {                                                                         \
    _sharpmem_vcom = _sharpmem_vcom ? 0x00 : SHARPMEM_BIT_VCOM;                \
  } while (0);

/**
 * @brief Construct a new Adafruit_SharpMem object with software SPI
 *
 * @param clk The clock pin
 * @param mosi The MOSI pin
 * @param cs The display chip select pin - **NOTE** this is ACTIVE HIGH!
 * @param width The display width
 * @param height The display height
 * @param freq The SPI clock frequency desired (unlikely to be that fast in soft
 * spi mode!)
 */
SharpMem::SharpMem(uint8_t clk, uint8_t mosi, uint8_t cs,
                                     uint16_t width, uint16_t height,
                                     uint32_t freq)
    : Display_GFX(width, height) {
  _cs = cs;
  if (spidev) {
    delete spidev;
  }
  spidev =
      new SPIClass(cs, clk, -1, mosi, freq, SPI_BITORDER_LSBFIRST);
}

/**
 * @brief Construct a new Adafruit_SharpMem object with hardware SPI
 *
 * @param theSPI Pointer to hardware SPI device you want to use
 * @param cs The display chip select pin - **NOTE** this is ACTIVE HIGH!
 * @param width The display width
 * @param height The display height
 * @param freq The SPI clock frequency desired
 */
SharpMem::SharpMem(SPIClass *theSPI, uint8_t cs,
                                     uint16_t width, uint16_t height,
                                     uint32_t freq)
    : Display_GFX(width, height) {
  _cs = cs;
  if (spidev) {
    delete spidev;
  }
  spidev = new SPIClass(cs, freq, SPI_BITORDER_LSBFIRST, SPI_MODE0,
                                  theSPI);
}