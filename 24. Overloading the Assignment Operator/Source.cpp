#include <iostream>
#include <memory>

#include "Test.h"

int main() {

	auto test1 = std::make_unique<Test>(10, "Mike");
	test1->print("test1->print()\n\n");

	auto test2 = std::make_unique<Test>(20, "Bob");
	test2->print("test2->print()\n\n");

	*test2 = *test1;
	test2->print("*test2 = *test1; test2->print()\n\n");
	
	Test test3;

	test3.operator=(*test2);
	test3.print("test3.operator=(*test2)\n\n");

	Test test4 = *test1;
	test4.print();

	std::cin.get();
	return 0;
}
