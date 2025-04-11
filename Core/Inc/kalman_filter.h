/*
 * kalman_filter.h
 *
 *  Created on: Apr 11, 2025
 *      Author: astrox
 */

#ifndef INC_KALMAN_FILTER_H_
#define INC_KALMAN_FILTER_H_

typedef struct {
	float q; // Process noise covariance
	float r; // Measurement noise covariance
	float x; // Estimated value
	float p; // Estimation error covariance
} KalmanFilter;

/*
 * @brief Initializes the Kalman filter with given process and measurement noise covariances.
 * @param kf Pointer to the KalmanFilter structure.
 * @param q Process noise covariance.
 * @param r Measurement noise covariance.
 */
void KalmanFilter_Init(KalmanFilter* kf, float q, float r);
/*
 * @brief Updates the Kalman filter with a new measurement.
 * @param kf Pointer to the KalmanFilter structure.
 * @param measurement The new measurement value.
 * @return The updated estimated value.
 */
float KalmanFilter_Update(KalmanFilter* kf, float measurement);


#endif /* INC_KALMAN_FILTER_H_ */
