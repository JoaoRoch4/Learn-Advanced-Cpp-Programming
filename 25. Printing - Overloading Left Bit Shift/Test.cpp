#include "Test.h"

#include <iosfwd>
#include <iostream>

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

std::ostream &operator<<(std::ostream &out, const Test &test) {

	out << test.id << " : " << test.name;
	return out;
}
