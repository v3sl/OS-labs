#include <iostream>
#include <vector.h>

int main() {
	number::Number first = number::Number(5);
	number::Number second = number::valueOf(3);
	std::cout << (first + number::ONE).getNumber() << '\n';
	std::cout << (first - number::ZERO).getNumber() << '\n';
	std::cout << (first * second).getNumber() << '\n';
	std::cout << (first / second).getNumber() << '\n';
	vector::Vector ort = vector::Vector(number::ONE, number::ONE);
	std::cout << (ort + vector::ONE_VECTOR).toString();
	return 0;
}
