#include <iostream>

#include "Test.h"

int main() {

	setlocale(0, "");

	Test test1(10, "Mike");
	Test test2(20, "João");

	std::cout << test1 << test2 << '\n';

	std::cin.get();
	return 0;
}
