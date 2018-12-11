#pragma once

////////////////////////////////////////////////////////////////////////////////
// The MIT License (MIT)
//
// Copyright (c) 2017 Nicholas Frechette & Animation Compression Library contributors
// Copyright (c) 2018 Nicholas Frechette & Realtime Math contributors
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
////////////////////////////////////////////////////////////////////////////////

#include "rtm/math.h"
#include "rtm/impl/scalar_common.h"

#include <algorithm>
#include <cmath>

namespace rtm
{
	//////////////////////////////////////////////////////////////////////////
	// Returns the largest integer value not greater than the input.
	// scalar_floor(1.8) -> 1.0
	// scalar_floor(-1.8) -> -2.0
	//////////////////////////////////////////////////////////////////////////
	inline double scalar_floor(double input) RTM_NO_EXCEPT
	{
		return std::floor(input);
	}

	//////////////////////////////////////////////////////////////////////////
	// Returns the smallest integer value not less than the input.
	// scalar_ceil(1.8) = 2.0
	// scalar_ceil(-1.8) = -1.0
	//////////////////////////////////////////////////////////////////////////
	inline double scalar_ceil(double input) RTM_NO_EXCEPT
	{
		return std::ceil(input);
	}

	//////////////////////////////////////////////////////////////////////////
	// Returns the input if it is within the min/max values otherwise the
	// exceeded boundary is returned.
	//////////////////////////////////////////////////////////////////////////
	inline double scalar_clamp(double input, double min, double max) RTM_NO_EXCEPT
	{
		return std::min(std::max(input, min), max);
	}

	//////////////////////////////////////////////////////////////////////////
	// Returns the absolute value of the input.
	//////////////////////////////////////////////////////////////////////////
	inline double scalar_abs(double input) RTM_NO_EXCEPT
	{
		return std::fabs(input);
	}

	//////////////////////////////////////////////////////////////////////////
	// Returns the square root of the input.
	//////////////////////////////////////////////////////////////////////////
	inline double scalar_sqrt(double input) RTM_NO_EXCEPT
	{
		return std::sqrt(input);
	}

	//////////////////////////////////////////////////////////////////////////
	// Returns the reciprocal square root of the input.
	//////////////////////////////////////////////////////////////////////////
	inline double scalar_sqrt_reciprocal(double input) RTM_NO_EXCEPT
	{
		// TODO: Use recip instruction
		return 1.0 / scalar_sqrt(input);
	}

	//////////////////////////////////////////////////////////////////////////
	// Returns the reciprocal of the input.
	//////////////////////////////////////////////////////////////////////////
	inline double scalar_reciprocal(double input) RTM_NO_EXCEPT
	{
		return 1.0 / input;
	}

	//////////////////////////////////////////////////////////////////////////
	// Returns the sine of the input angle.
	//////////////////////////////////////////////////////////////////////////
	inline double scalar_sin(double angle) RTM_NO_EXCEPT
	{
		return std::sin(angle);
	}

	//////////////////////////////////////////////////////////////////////////
	// Returns the cosine of the input angle.
	//////////////////////////////////////////////////////////////////////////
	inline double scalar_cos(double angle) RTM_NO_EXCEPT
	{
		return std::cos(angle);
	}

	//////////////////////////////////////////////////////////////////////////
	// Returns both sine and cosine of the input angle.
	//////////////////////////////////////////////////////////////////////////
	inline void scalar_sincos(double angle, double& out_sin, double& out_cos) RTM_NO_EXCEPT
	{
		out_sin = scalar_sin(angle);
		out_cos = scalar_cos(angle);
	}

	//////////////////////////////////////////////////////////////////////////
	// Returns the arc-cosine of the input.
	//////////////////////////////////////////////////////////////////////////
	inline double scalar_acos(double value) RTM_NO_EXCEPT
	{
		return std::acos(value);
	}

	//////////////////////////////////////////////////////////////////////////
	// Returns the arc-tangent of [x/y] using the sign of the arguments to
	// determine the correct quadrant.
	//////////////////////////////////////////////////////////////////////////
	inline double scalar_atan2(double x, double y) RTM_NO_EXCEPT
	{
		return std::atan2(x, y);
	}

	//////////////////////////////////////////////////////////////////////////
	// Returns the smallest of the two inputs.
	//////////////////////////////////////////////////////////////////////////
	inline double scalar_min(double left, double right) RTM_NO_EXCEPT
	{
		return std::min(left, right);
	}

	//////////////////////////////////////////////////////////////////////////
	// Returns the largest of the two inputs.
	//////////////////////////////////////////////////////////////////////////
	inline double scalar_max(double left, double right) RTM_NO_EXCEPT
	{
		return std::max(left, right);
	}

	//////////////////////////////////////////////////////////////////////////
	// Returns true if both inputs are nearly equal, false otherwise.
	//////////////////////////////////////////////////////////////////////////
	inline bool scalar_near_equal(double lhs, double rhs, double threshold = 0.00001) RTM_NO_EXCEPT
	{
		return scalar_abs(lhs - rhs) < threshold;
	}

	//////////////////////////////////////////////////////////////////////////
	// Returns true if the input is finite (not NaN or Inf), false otherwise.
	//////////////////////////////////////////////////////////////////////////
	inline bool scalar_is_finite(double input) RTM_NO_EXCEPT
	{
		return std::isfinite(input);
	}

	//////////////////////////////////////////////////////////////////////////
	// Returns the rounded input using a symmetric algorithm.
	// scalar_symmetric_round(1.5) = 2.0
	// scalar_symmetric_round(1.2) = 1.0
	// scalar_symmetric_round(-1.5) = -2.0
	// scalar_symmetric_round(-1.2) = -1.0
	//////////////////////////////////////////////////////////////////////////
	inline double scalar_symmetric_round(double input) RTM_NO_EXCEPT
	{
		return input >= 0.0 ? scalar_floor(input + 0.5) : scalar_ceil(input - 0.5);
	}

	//////////////////////////////////////////////////////////////////////////
	// Returns the fractional part of the input.
	//////////////////////////////////////////////////////////////////////////
	inline double scalar_fraction(double value) RTM_NO_EXCEPT
	{
		return value - scalar_floor(value);
	}

	//////////////////////////////////////////////////////////////////////////
	// Safely casts an integral input into a float64 output.
	//////////////////////////////////////////////////////////////////////////
	template<typename SrcIntegralType>
	inline double scalar_safe_to_double(SrcIntegralType input) RTM_NO_EXCEPT
	{
		double input_f = double(input);
		RTM_ASSERT(SrcIntegralType(input_f) == input, "Conversion to double would result in truncation");
		return input_f;
	}
}
