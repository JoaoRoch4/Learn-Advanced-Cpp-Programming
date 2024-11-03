#include <cstdint>
#include <iostream>
#include <set>
#include <string>

int main() {

	std::set<int16_t> setNumbers;

	setNumbers.insert(50);
	setNumbers.insert(10);
	setNumbers.insert(30);
	setNumbers.insert(20);

	for (auto it = setNumbers.begin(); it != setNumbers.end(); it++) 
		std::cout << *it << '\n';
	
	(setNumbers.find(30) != setNumbers.end()) ?
		std::cout << "\n30 is in the set\n" :	
		std::cout << "30 is not in the set\n";


	std::cin.get();
	return 0;
}