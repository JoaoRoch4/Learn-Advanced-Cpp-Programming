#include <iostream>
#include <string>

#include "Complex.h"

#define out std::cout
using my::Complex;

int main() {

	Complex c0(3, 2);
	Complex c1(3, 2);
	
	if (c0 == c1) {
		out << "Equal\n";
	} else {
		out << "Not equal\n";
	}

	if (c0 != c1) {
		out << "Not equal\n";
	} else {
		out << "Equal\n";
	}
	std::cin.get();
	return 0;
}
