#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <array>

typedef std::string str;
#define __END std::cin.get(); return 0
 
int main() {

	std::multimap<int, str> lookup;

	lookup.insert(std::make_pair(30, "Mike"));
	lookup.insert(std::make_pair(10, "Vicky"));
	lookup.insert(std::make_pair(30, "Raj"));
	lookup.insert(std::make_pair(20, "Bob"));

	for (auto it = lookup.begin(); it != lookup.end(); it++)  
		std::cout << it->first << ": " << it->second << '\n';
	
	std::cout << '\n';	

	for (auto it = lookup.find(20); it != lookup.end(); it++) 
		std::cout << it->first << ": " << it->second << '\n';
	
	std::cout << '\n';

	std::pair<std::multimap<int, str>::iterator, std::multimap<int, str>::iterator> its = lookup.equal_range(30);

	for (std::multimap<int, str>::iterator it = its.first; it != its.second; it++)
		std::cout << it->first << ": " << it->second << '\n';


	lookup.empty();
	                                                                                                                                          
	__END;	
}