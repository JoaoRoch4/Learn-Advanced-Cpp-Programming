#include <iostream>
#include <string>

#include "Complex.h"

#define ct std::cout
class my::Complex;

int main() {

	my::Complex c0(3, 4);
	my::Complex c1(2, 3);
	my::Complex c2 = c0 + c1;

	std::cout << c0 << '\n';
	std::cout << c0 + c1 + c2 << '\n';
	
	my::Complex c4(4, 2);
	my::Complex c5 = c4 + 7;
	my::Complex c6(1, 7);

	ct << 3.2 + c6 << '\n';
	ct << 7 + c1 + c2 + 8 + 9 + c6 << '\n';

	std::cin.get();
	return 0;
}
