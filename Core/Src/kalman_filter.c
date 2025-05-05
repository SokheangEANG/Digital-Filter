/*
 * kalman_filter.c
 *
 *  Created on: Apr 11, 2025
 *      Author: astrox
 */
#include "stm32f1xx_hal.h"
#include "kalman_filter.h"

double KalmanFilter(Kalman_Typedef *kalman_filter, double kalman_input) {
	/* Kalman Predict */
	kalman_filter->CurrentP = kalman_filter->LastP + kalman_filter->KalmanQ;

	/* Kalman Gain Equaltion */
	kalman_filter->KalmanGian = kalman_filter->CurrentP
			/ (kalman_filter->CurrentP + kalman_filter->KalmanR);

	/* Kalman Optimal Value */
	kalman_filter->KalmanOutput = kalman_filter->KalmanOutput
			+ kalman_filter->KalmanGian
					* (kalman_input - kalman_filter->KalmanOutput);

	/* Update Kalman Filter */
	kalman_filter->LastP = (1 - kalman_filter->KalmanGian)
			* kalman_filter->CurrentP;

	return (kalman_filter->KalmanOutput);
}
void KalmanInit(Kalman_Typedef *kalman_filter, const double kalman_Q, const double kalman_R)
{
	kalman_filter->LastP = 0.02;
	kalman_filter->CurrentP = 0.00;
	kalman_filter->KalmanOutput = 0.00;
	kalman_filter->KalmanGian = 0.00;
	kalman_filter->KalmanQ = kalman_Q;
	kalman_filter->KalmanR = kalman_R;
}
