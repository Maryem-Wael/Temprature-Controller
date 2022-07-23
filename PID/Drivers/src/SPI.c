#include "SPI.h"
#include "RCC.h"

void SPI_EnableClock()
{
	RCC_APB2ENR |= (0x01 << 12);
}

void SPI_Init(unsigned char MasterSlave, unsigned char ClkPol, unsigned char ClkPhase)
{
	SPI1_CR1 |= (0x3 << 8);

	SPI1_CR1 |= (MasterSlave << 2);

	SPI1_CR1 |= (ClkPol << 1);

	SPI1_CR1 |= (ClkPhase << 0);

	SPI1_CR1 |= (0x3 << 3);

	SPI1_CR1 |= (1 << 6);
}

unsigned char SPI_TransmitRecieveByte(unsigned char TxData)
{
	if (SPI1_SR & (1 << 1))
	{
		SPI1_DR = TxData;
		while (SPI1_SR & (1 << 7))
		{
		}
		return SPI1_DR;
	}
	return -1;
}
