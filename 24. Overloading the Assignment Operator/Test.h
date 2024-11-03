#pragma once
#include <string>

class Test {

	int id;
	std::string name;

public:

	Test() : id(0), name("") {}
	Test(const int &id, const std::string &name) : id(id), name(name) {}
	Test(const Test &other);
	void print() const;
	void print(const char *s) const;
	Test &operator=(const Test &other);
};

