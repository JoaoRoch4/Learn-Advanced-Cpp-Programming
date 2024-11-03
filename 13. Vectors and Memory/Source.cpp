#include <iostream>
#include <iterator>
#include <print>
#include <string>
#include <vector>

#define vec std::vector
typedef std::string str;
typedef vec<str> strvec;
typedef strvec::iterator vsi;
typedef vec<double> dVec;


int main() {

	dVec dvecNumbers{20};

	std::cout << "Size " << dvecNumbers.size() << '\n';

	int iCapacity = dvecNumbers.capacity();

	std::cout << "Capacity " << iCapacity << '\n';

	 for (int i = 0; i < 100000; i++)  {

		if (dvecNumbers.capacity() != iCapacity) {

			iCapacity = dvecNumbers.capacity();
			std::cout << "Capacity " << iCapacity << '\n';
		}		
		dvecNumbers.push_back(i);
	 }

	 dvecNumbers.resize(0);
	 dvecNumbers.shrink_to_fit();
	 dvecNumbers.clear();
	
	std::cin.get();
	return 0;
}
 