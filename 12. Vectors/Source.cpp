#include <iostream>
#include <iterator>
#include <print>
#include <string>
#include <vector>

typedef std::vector<std::string> strvec;
typedef strvec::iterator vsi;

int main() {

	strvec vecStrings{};
	vsi vsiIt{};
		
	vecStrings.push_back("one");
	vecStrings.push_back("two");
	vecStrings.push_back("three");

	vecStrings.insert(vecStrings.begin(), "zero");
	
	vsiIt = vecStrings.begin();

	for (int i = 0; i < vecStrings.size(); i++)
		std::cout << vecStrings [i] << '\n';

	std::println("");

	for (vsi it = vecStrings.begin(); it != vecStrings.end(); it++)
		std::cout << *it << '\n';
	
	std::cout << *vsiIt << '\n';
	
	vsi it = vecStrings.begin();

	it += 2;

	std::cout << *it << '\n';

	std::cin.get();
	return 0;
}
 
 // The code above is a simple example of how to use the std::vector class. 
 // The code creates a vector of strings and adds three strings to it. 
 // The code then prints the second string in the vector and the size of the vector. 
 // The output of the code is: 
 // two