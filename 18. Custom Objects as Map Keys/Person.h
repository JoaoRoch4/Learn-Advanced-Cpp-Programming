#pragma once

#include <iostream>
#include <string>

typedef std::string str;

class Person {

	str sName;
	int iAge;

public:

	inline Person() = default;

	inline Person (str sName, int iAge) : sName(sName), iAge(iAge) {};
	
	void Print() const {
		std::cout << sName << ": " << iAge << std::flush;
	}

	inline bool operator<(const Person &other) const {
		return (sName == other.sName) ? iAge < other.iAge : iAge < other.iAge;
	}

	inline str &operator=(const Person &person) {
		return sName = person.sName;
	}

};

