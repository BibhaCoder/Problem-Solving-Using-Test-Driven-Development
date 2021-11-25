/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 */

#include <string.h>
#include "../inc/rain_water_tap.h"

#define RAIN_WATER_TAP_MIN_SIZE (2)
#define MIN(a, b) (a < b ? a : b)

static void generate_left_peaks(size_t *left_peaks, size_t const *arr,
				size_t len)
{
	size_t i;
	size_t max = 0;

	memset(left_peaks, 0, len * sizeof(left_peaks[0]));

	for (i = 0; i < len - 1; i++) {
		if (arr[i] > max)
			max = arr[i];
		left_peaks[i] = max;
	}
}

static void generate_right_peaks(size_t *right_peaks, size_t const *arr,
				 size_t len)
{
	ptrdiff_t i;
	size_t max = 0;

	memset(right_peaks, 0, len * sizeof(right_peaks[0]));

	for (i = len - 1; i > 0; i--) {
		if (arr[i] > max)
			max = arr[i];
		right_peaks[i] = max;
	}
}

size_t tap_rain_water(size_t const *arr, size_t len)
{
	size_t i;
	size_t volume = 0;
	size_t left_peak_arr[len];
	size_t right_peak_arr[len];
	size_t left_peak, right_peak, min_peak;

	if (len <= RAIN_WATER_TAP_MIN_SIZE)
		return 0;

	generate_left_peaks(left_peak_arr, arr, len);
	generate_right_peaks(right_peak_arr, arr, len);

	for (i = 1; i < len - 1; i++) {
		left_peak = left_peak_arr[i];
		right_peak = right_peak_arr[i];
		min_peak = MIN(left_peak, right_peak);
		if (arr[i] < min_peak)
			volume += min_peak - arr[i];
	}

	return volume;
}
