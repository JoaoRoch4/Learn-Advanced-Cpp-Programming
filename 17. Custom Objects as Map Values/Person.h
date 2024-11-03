#pragma once

#include <iostream>
#include <string>

typedef std::string str;

class Person {

private:

	str sName;
	int iAge;

public:

	inline Person() = default;

	inline Person (str sName, int iAge) : sName(sName), iAge(iAge) {};
	
	inline Person(const Person &person) : sName(person.sName), iAge(person.iAge) {
		std::cout << "Copy constructor called\n";
	}

	inline void Print() const {
		std::cout << sName << ": " << iAge << '\n';
	}
};

