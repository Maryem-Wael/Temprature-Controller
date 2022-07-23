
#ifndef INC_POLLER_H_
#define INC_POLLER_H_

void Poll(void);
void StartPolling(void);
void StopPolling(void);
void SetPollingTime(int polling_time);
void floatToStr(float val, char data[]);

#endif /* INC_POLLER_H_ */
