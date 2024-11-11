// 38. Functors.cpp : This file contains the 'main' function.
// Program execution begins

#define pure_virtual 0;

#include <iostream>
#include <string>

typedef std::string str;

struct Test {
	virtual bool operator() (str &text) = pure_virtual;
	virtual ~Test() {}
};

struct MatchTest : public Test {

	bool operator() (str &text) { return text == "lion"; }
};

void check(str Text, Test &test) {

	if (test(Text)) {
		std::cout << "Text matches!" << std::endl;
	} else {
		std::cout << "No match!" << std::endl;
	}
}

int main() {
	MatchTest pred;

	str value = "lion";

	MatchTest m;

	check(value, m);

	std::cin.get();
	return 0;
}
