#include <iostream>

#include "Complex.h"

int main() {

	printf("Hello world\n");
	Complex c1(2,3);
	Complex c2 = c1;

	c1 = c2;

	std::cout << c2;
	printf("\nGoodbye world");
	std::cin.get();
	return 0;
}
