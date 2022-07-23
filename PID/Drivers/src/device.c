
#include "device.h"
#include "SPI.h"
#include "TC72.h"
#include "GPIO.h"
#include "PollingDataClient.h"
#include "USART.h"
/*macros to select sensor*/
#define TC72_SELECT()   (GPIO_WritePin(1, 0, 1))
#define TC72_UNSELECT() (GPIO_WritePin(1, 0, 0))

unsigned char spiData = 0;
float temperature = 0.0f ;


float Get_Data(void)
{

	TC72_SELECT();
	TC72_Init(0);       /*write zeros in control register*/
	TC72_UNSELECT();   /*choose TC72*/

    temperature = 0.0f;

    TC72_SELECT();
    TC72_RegisterRead(0x01, &spiData);
    TC72_UNSELECT();

    if (spiData & (1 << 7)) {
      temperature += 0.5f;
    }
    if (spiData & (1 << 6)) {
      temperature += 0.25f;
    }

    TC72_SELECT();
    TC72_RegisterRead(0x02, &spiData);
    TC72_UNSELECT();

    temperature += (signed char)spiData;
    return temperature;

}
