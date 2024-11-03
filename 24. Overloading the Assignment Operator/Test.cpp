#include "test.h"

#include<iostream>

Test::Test(const Test &other) {

	std::cout << "Copy constructor running\n";
	id = other.id;
	name = other.name;
}

void Test::print() const {
	std::cout << id << ": " << name << '\n';
}

void Test::print(const char *s) const {

	std::cout << id << ": " << name << '\n';
	std::cout << s;
}

Test &Test::operator=(const Test &other) {
	
	std::cout << "assignment running\n";
	return *this = other;	
}
