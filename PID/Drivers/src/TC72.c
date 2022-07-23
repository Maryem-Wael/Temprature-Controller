
#include "TC72.h"
#include "SPI.h"
#include "Util.h"


void TC72_Init(unsigned char Mode) {

    TC72_RegisterWrite(0x80, 0x00);
}

void TC72_RegisterWrite(unsigned char RegAdd, unsigned char Data) {
  SPI_TransmitRecieveByte(RegAdd | (1 << 7));
  SPI_TransmitRecieveByte(Data);
}

void TC72_RegisterRead(unsigned char RegAdd, unsigned char* DataPtr) {
    SPI_TransmitRecieveByte(RegAdd & (~(1 << 7)));
    *DataPtr = SPI_TransmitRecieveByte(0x00);
}
