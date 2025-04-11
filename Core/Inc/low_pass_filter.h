/*
 * low_pass_filter.h
 *
 *  Created on: Apr 11, 2025
 *      Author: astrox
 */

#ifndef INC_LOW_PASS_FILTER_H_
#define INC_LOW_PASS_FILTER_H_

typedef struct {
	float alpha;            // Smoothing factor
	float unfiltered_value; // Current unfiltered value
	float filtered_value;   // Current filtered value
} LowPassFilter;

/**
 * @brief Initialize the low-pass filter
 * @param filter Pointer to the LowPassFilter structure
 * @param alpha Smoothing factor (0 < alpha < 1)
 */
void LowPassFilter_init(LowPassFilter* filter, float alpha);
/**
 * @brief Update the low-pass filter with a new value
 * @param filter Pointer to the LowPassFilter structure
 * @param new_value New input value
 * @return Filtered output value
 */
float LowPassFilter_update(LowPassFilter* filter, float new_value);

#endif /* INC_LOW_PASS_FILTER_H_ */
