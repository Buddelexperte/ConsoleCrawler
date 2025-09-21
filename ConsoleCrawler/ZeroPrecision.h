#pragma once

#include <math.h>

static constexpr double EPSILON = 0.001;

inline void zeroPrecision(double& val)
{
	if (abs(val) < EPSILON)
		val = 0;
}

inline void zeroPrecision(float& val)
{
	if (abs(val) < EPSILON)
		val = 0;
}