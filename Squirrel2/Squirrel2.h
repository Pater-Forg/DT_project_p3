#pragma once
#include <cstdlib>
#include <utility>

/// <summary>
/// Generate random float in given range
/// </summary>
/// <param name="min">lower bound</param>
/// <param name="max">upper bound</param>
/// <returns>random float in range from 'min' to 'max'</returns>
float rand_float(float min, float max) {
	if (max == min) return min;
	if (max < min)  std::swap(max, min);
	return min + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (max - min)));
}

/// <summary>
/// Fills array 'bag' with random floats in given range 'min_w' and 'max_w'
/// </summary>
/// <param name="bag">pointer to array</param>
/// <param name="count">count of elements</param>
/// <param name="min_w">lower bound</param>
/// <param name="max_w">upper bound</param>
/// <returns>False if count is less or equal to zero, or min_w or max_w are negative. 
/// Otherwise True</returns>
bool fill_bag(float* bag, int count, float min_w, float max_w) {
	if (min_w < 0 || max_w < 0 || count <= 0) return false;
	for (int i = 0; i < count; i++) {
		bag[i] = rand_float(min_w, max_w);
	}
	return true;
}