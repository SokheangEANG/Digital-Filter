/*
 * kalman_filter.h
 *
 *  Created on: Apr 11, 2025
 *      Author: astrox
 */
#ifndef INC_KALMAN_FILTER_H_
#define INC_KALMAN_FILTER_H_

typedef struct {
	/* Newer Use */
	double LastP;          // Last Estimate coveriance
	double CurrentP;       // Current Estimate coveriance
	double KalmanOutput;   // Output Filter
	double KalmanGian;     // Kalman Gain
	double KalmanQ;
	double KalmanR;

} Kalman_Typedef;

void KalmanInit(Kalman_Typedef *kalam_filter, const double kalman_Q, const double kalman_R);
double KalmanFilter(Kalman_Typedef *kalman_filter, double kalman_input);

#endif /* INC_KALMAN_FILTER_H_ */
