/*
 * low_pass_filter.c
 *
 *  Created on: Apr 11, 2025
 *      Author: astrox
 */
#include "stm32f1xx_hal.h"
#include "low_pass_filter.h"

/*
 * @brief  Initializes the low-pass filter with the specified number of samples.
 * @param  filter: Pointer to the LowPassFilter structure.
 * @param  num_samples: Number of samples for the filter.
 */
void LowPassFilter_init(LowPassFilter *filter, float alpha) {
	filter->alpha = alpha;
	filter->unfiltered_value = 0.0f;
	filter->filtered_value = 0.0f;
}

/*
 * @brief  Updates the low-pass filter with a new value.
 * @param  filter: Pointer to the LowPassFilter structure.
 * @param  new_value: New input value.
 * @return Filtered output value.
 */
float LowPassFilter_update(LowPassFilter *filter, float new_value) {
	/*
	 * Update the unfiltered value with the new input value.
	 * Calculate the filtered value using the low-pass filter formula.
	 * The formula is:
	 * filtered_value = (alpha * unfiltered_value) + ((1 - alpha) * filtered_value)
	 */
	filter->unfiltered_value = new_value;
	filter->filtered_value = (filter->alpha * filter->unfiltered_value) + ((1.0f - filter->alpha) * filter->filtered_value);
	return filter->filtered_value;
}
