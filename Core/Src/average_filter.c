/*
 * average_filter.c
 *
 *  Created on: Apr 11, 2025
 *      Author: astrox
 */
#include "stm32f1xx_hal.h"
#include "average_filter.h"
#include <stdlib.h>

/*
 * @brief Initializes the average filter with a specified number of samples.
 * @param filter Pointer to the AverageFilter structure.
 * @param num_samples Number of samples to average.
 */
void avg_filter_init(AverageFilter *filter, int num_samples) {

	// Allocate memory for the buffer
	filter->buffer = (float*) malloc(num_samples * sizeof(float));
	if (filter->buffer == NULL) {
		return;
	}
	// Initialize the filter parameters
	filter->sum = 0.0f;
	filter->average = 0.0f;
	filter->num_read = num_samples;
	filter->read_index = 0;

	// Initialize the buffer with zeros
	for (int i = 0; i < num_samples; i++) {
		filter->buffer[i] = 0.0f;
	}
}

/*
 * @brief Updates the average filter with a new ADC value.
 * @param filter Pointer to the AverageFilter structure.
 * @param adc_value New ADC value to add to the filter.
 * @return The updated average value.
 */
float avg_filter_update(AverageFilter *filter, float adc_value) {

	// Subtract the oldest sample from the sum
	filter->sum -= filter->buffer[filter->read_index];

	// Add the new sample to the buffer and the sum
	filter->buffer[filter->read_index] = adc_value;
	filter->sum += adc_value;

	// Update the read index
	filter->read_index = (filter->read_index + 1) % filter->num_read;

	// Calculate the average
	filter->average = filter->sum / filter->num_read;

	return filter->average;
}

