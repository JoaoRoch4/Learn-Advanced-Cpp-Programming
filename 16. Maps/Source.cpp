#include "cctype"
#include <filesystem>
#include <iostream>
#include <locale>
#include <map>
#include <string>
#include <utility>

typedef std::string str;

struct CaseInsensitiveCompare {

	constexpr bool operator()(const std::string &left, const std::string &right) const {

		return std::lexicographical_compare(left.begin(), left.end(),
		right.begin(), right.end(),

			 [] (const char& a, const char& b) -> int {

				return std::tolower(a) < std::tolower(b);
		     }
		);
	}
};

int main() {

	std::locale::global(std::locale("")); // Set the global locale to utf-8

	// Non case sensitive map that stores people and their ages
	std::map<std::string, int, CaseInsensitiveCompare> mapAges; 

	mapAges ["Mike"]  = 23;
	mapAges ["Rag"]   = 20;
	mapAges ["Vicky"] = 30;

	std::pair<str, int> parAddToMap {"Peter", 100}; // a std::pair<str, int> to the map being "Peter" and 100
	mapAges.insert(parAddToMap);
	mapAges.insert(std::make_pair("Rocha", 30));

	//mapAges.insert(std::make_pair("Peter", 100));

	//std::cout << mapAges ["Rag"] << std::endl;

	(mapAges.find("vicky") != mapAges.end()) ?
		std::cout << "Found Vicky\n" :	  
		std::cout << "Key not found\n";
	
	for (auto it = mapAges.begin(); it != mapAges.end(); it++) {

		str sMyMap{ it->first + ": " + std::to_string(it->second) + '\n'};
		std::cout << sMyMap;
	} 

	std::cout << mapAges["MIKE"] << '\n';
	std::cout << mapAges ["André"] << "André" << '\n';

	std::flush(std::cout);
	std::cin.get();
	return 0;
}
