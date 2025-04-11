/*
 * kalman_filter.c
 *
 *  Created on: Apr 11, 2025
 *      Author: astrox
 */
#include "stm32f1xx_hal.h"
#include "kalman_filter.h"

void KalmanFilter_Init(KalmanFilter* kf, float q, float r) {
	/*
	 * Tune the process noise covariance (q) and measurement noise covariance (r)
	 * to adjust the filter's responsiveness and stability.
	 * Higher q values make the filter more responsive to changes.
	 * Lower r values make the filter more stable.
	 */
	kf->q = q; // Process noise covariance
	kf->r = r; // Measurement noise covariance
	kf->x = 0; // Initial estimated value
	kf->p = 1; // Initial estimation error covariance
}

float KalmanFilter_Update(KalmanFilter* kf, float adc_value) {
	// Prediction step
	kf->p += kf->q;
	// Measurement update step
	float k = kf->p / (kf->p + kf->r); // Kalman gain
	kf->x += k * (adc_value - kf->x); // Update estimate
	kf->p *= (1 - k); // Update estimation error covariance
	return kf->x; // Return the updated estimated value
}
