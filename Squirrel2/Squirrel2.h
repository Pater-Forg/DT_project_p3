#pragma once
#include <cstdlib>

/// <summary>
/// Generate random float in given range
/// </summary>
/// <param name="min">lower bound</param>
/// <param name="max">upper bound</param>
/// <returns>random float in range from 'min' to 'max'</returns>
float rand_float(float min, float max) {
	return min + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (max - min)));
}