#ifndef INC_SPI_H_
#define INC_SPI_H_

#define DEFINE_REG(PORT_ID, REG_ID) (*(unsigned int *)(PORT_ID + REG_ID))

#define SLAVE 0x00
#define MASTER 0x01

#define IDLE_LOW 0x00
#define IDLE_HIGH 0x01

#define SAMPLE_FIRST_TRANSITION 0x00
#define SAMPLE_SOCAND_TRANSITION 0x01

#define SPI1_CR1 DEFINE_REG(0x40013000, 0x00)
#define SPI1_SR DEFINE_REG(0x40013000, 0x08)
#define SPI1_DR DEFINE_REG(0x40013000, 0x0C)

void SPI_EnableClock();
void SPI_Init(unsigned char MasterSlave, unsigned char ClkPol, unsigned char ClkPhase);
unsigned char SPI_TransmitRecieveByte(unsigned char TxData);

#endif /* INC_SPI_H_ */
