#include <iostream>
#include <string>

#include "Complex.h"

#define out std::cout
using my::Complex;

int main() {

	Complex co(2, 4);


	out << co.GetReal() << '\n';
	
	std::cin.get();
	return 0;
}
