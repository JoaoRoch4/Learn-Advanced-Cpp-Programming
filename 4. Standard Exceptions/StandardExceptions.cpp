#include <climits>
#include <exception>
#include <iostream>
#include <string>

class CanGoWrong;

class CanGoWrong {

public: 

	CanGoWrong() {

		char *pMemory = new char[ULLONG_MAX];
		delete[] pMemory;
	}

	inline bool operator==(const CanGoWrong &other) const {
		return false;
	}
};

int main() {

	try {
		CanGoWrong m_wrong;

	} catch (std::bad_alloc &e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	std::cout << "Still running" << std::endl;

	std::cin.get();
	return 0;
}