#include <cstdint>
#include <exception>
#include <iostream>
#include <stdexcept>
#include <print>


void funcGoesWrong() {

	const bool bError1Detected {false};
	const bool bError2Detected {true};

	if (bError1Detected) {
		throw std::bad_alloc();
	}

	if (bError2Detected) {
		throw std::exception();
	}
}

int main() {

	std::print("oi");

	try {

		funcGoesWrong();

	} catch (const std::bad_alloc &e) {

		std::cout << "Catching bad_alloc: " << e.what() << std::endl;

	} catch (const std::exception &e) {
		
		std::cout << "Catching exception: " << e.what() << std::endl;
	}

    std::cin.get();
    return 0;
}