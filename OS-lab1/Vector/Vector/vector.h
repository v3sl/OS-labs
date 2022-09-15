#pragma once

#ifdef VECTORDLL_EXPORTS
#define VECTORDLL __declspec(dllexport)
#else
#define VECTORDLL __declspec(dllimport)
#endif

#include <string>
#include <number.h>
#include <cmath>

namespace vector {
	class VECTORDLL Vector {
	public:
		Vector(number::Number x = 0, number::Number y = 0);
		Vector operator+(const Vector& secondVector);
		number::Number getRaduis();
		number::Number getAngle();
		std::string toString();
	private:
		number::Number x;
		number::Number y;
	};
	const Vector ZERO_VECTOR = Vector(number::ZERO, number::ZERO);
	const Vector ONE_VECTOR = Vector(number::ONE, number::ONE);
}