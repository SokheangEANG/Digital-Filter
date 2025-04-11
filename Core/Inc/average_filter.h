#ifndef _AVERAGE_FILTER_H
#define _AVERAGE_FILTER_H

typedef struct {
	float *buffer;  // Buffer for storing samples
	float sum;      // Sum of the samples in the buffer
	float average;  // Average of the samples
	int num_read;   // Number of samples to read
	int read_index; // Current index in the buffer
} AverageFilter;

void avg_filter_init(AverageFilter *filter, int num_samples);
float avg_filter_update(AverageFilter *filter, float adc_value);

#endif // _AVERAGE_FILTER_H
