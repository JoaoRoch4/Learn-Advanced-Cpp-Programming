#include "cctype"
#include <filesystem>
#include <iomanip>
#include <iostream>
#include <locale>
#include <map>
#include <string>
#include <utility>

#include "Person.h"
#include <cmath>
#include <ios>
#include <memory>

typedef std::string str;

struct CaseInsensitiveCompare {

	bool operator()(const std::string &left, const std::string &right) const {

		return std::lexicographical_compare(left.begin(), left.end(),
			right.begin(), right.end(),

			[] (const char &a, const char &b) -> int {

			return std::tolower(a) < std::tolower(b);
		}
		);
	}
};

class Person;

int main() {

	std::locale::global(std::locale("")); // Set the global locale to utf-8

	auto person {std::make_unique<Person>()};

	// Non case sensitive map that stores people and their ages
	std::map<Person, int> mapPeople {};

	int ikey {};

	mapPeople [Person("Mike", 40)] = 40;
	mapPeople [Person("Sue", 30)] = 30;
	mapPeople [Person("Rag", 20)] = 20;

	for (std::map<Person, int>::iterator it = mapPeople.begin(); it != mapPeople.end(); it++) {

		std::cout << it->second << std::flush;
		it->first.Print();
		std::cout << std::endl << std::flush;		 
	}

	std::flush(std::cout);
	std::cin.get();
	return 0;
}
