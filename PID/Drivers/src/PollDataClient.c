
//#include "stm324xx.h"
#include "PollingDataClient.h"
#include "USART.h"
#include "GPIO.h"
#include<stdio.h>


float pid_integrator = 0.0f;
float pid_prevError  = 0.0f;
float pid_prevMeasurement = 0.0f;
float setpoint = 30.0f;
float error=0.0f;
float PID_LIM_MIN = -10.0f;
float PID_LIM_MAX = 10.0f;

float pid_Kp = 0.1f;
float pid_Ki = 0.01f;
float pid_limMax=10.0f;
float pid_T = 0.5f;    /*Time in sec*/
float pid_prevout=0.0f;
float pid_out=0.0f;

float Handle_data(float data)
{
	/*
	* Error signal
	*/
    float error = setpoint-data;

	/*
	* Proportional
	*/
    float proportional = pid_Kp * error;


	/*
	* Integral
	*/
    pid_integrator = pid_integrator + 0.5f * pid_Ki * pid_T * (error + pid_prevError);

	/* Anti-wind-up via integrator clamping */
    if (pid_integrator > PID_LIM_MAX) {

        pid_integrator = PID_LIM_MAX;

    } else if (pid_integrator < PID_LIM_MAX) {

        pid_integrator = PID_LIM_MAX;

    }

	/*
	* Compute output and apply limits
	*/
    pid_out = proportional + pid_integrator ;

    if (pid_out > pid_limMax) {

    	pid_out = 0.73f;

    }else if (pid_out <= pid_limMax) {

    	pid_out = 0.0f;
    }



	/* Store error and measurement or later use */
    pid_prevError       = error;
    pid_prevMeasurement = data;
    pid_prevout=pid_out;

	/* Return controller output */

    return (pid_out);

}

