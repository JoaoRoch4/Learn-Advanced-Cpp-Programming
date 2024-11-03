#include "cctype"
#include <filesystem>
#include <iostream>
#include <locale>
#include <map>
#include <string>
#include <utility>

#include "Person.h"
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
	std::map<int, Person> mapPeople{};

	mapPeople [0] = Person("Mike",  40);
	mapPeople [1] = Person("Rag",   30);
	mapPeople [2] = Person("Vicky", 20);

	mapPeople.insert(std::make_pair(55, Person("Bob", 45)));
	mapPeople.insert(std::make_pair(55, Person("sue", 24)));


	for (auto it = mapPeople.begin(); it != mapPeople.end(); it++) {

		std::cout << it->first << ": ";
		it->second.Print();
	}

	std::flush(std::cout);
	std::cin.get();
	return 0;
}
