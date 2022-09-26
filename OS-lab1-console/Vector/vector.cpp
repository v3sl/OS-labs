#include "vector.h"

namespace vector {
	Vector::Vector(number::Number x, number::Number y) :x(x), y(y) {}
	Vector Vector::operator+(const Vector& secondVector) {
		return Vector(x + secondVector.x, y + secondVector.y);
	}
	number::Number Vector::getRadius() {
		return number::Number(sqrt((x * x + y * y).getNumber()));
	}
	number::Number Vector::getAngle() {
		return x.getNumber() == 0 ? number::Number(atan((y / x).getNumber())) : 0;
	}
	std::string Vector::toString() {
		std::string vectorStr = "( " + std::to_string(x.getNumber()) + " " + std::to_string(y.getNumber()) + " )";
		return vectorStr;
	}
}
