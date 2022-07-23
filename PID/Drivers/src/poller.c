
#include "poller.h"
#include "device.h"
#include "PollingDataClient.h"
#include "GPIO.h"
#include "USART.h"

int polling_enabled= 1;
int polling_counter= 1;
int counter = 0 ;
char usart2TempData[] = {' ', '.', ' ', ' ', '\r', '\n', '\0'};


void Poll(void)
{
	if(polling_enabled && (!counter))
	{
		float data;
		data = Get_Data();
		float pid_out;
		pid_out=Handle_data(data);
	    floatToStr(pid_out, usart2TempData);
	    USART_TRANSMIT(usart2TempData);


	}
	counter++;
	counter = counter%polling_counter;
}

void StartPolling(void)
{
	polling_enabled=1;
}

void StopPolling(void)
{
	polling_enabled=0;
}

void SetPollingTime(int polling_time)
{
	polling_counter = polling_time/100;
}

void floatToStr(float val, char data[]) {
  int intVal = val * 100;
  data[3] = (intVal % 10) + '0';
  intVal /= 10;
  data[2] = (intVal % 10) + '0';
  data[1] = '.';
  intVal /= 10;
  data[0] = (intVal % 10) + '0';



  data[4] = '\r';
  data[5] = '\n';
  data[6] = '\0';
}
