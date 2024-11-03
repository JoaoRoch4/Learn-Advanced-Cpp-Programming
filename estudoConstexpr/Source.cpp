#include "cctype"
#include <filesystem>
#include <iomanip>
#include <iostream>
#include <locale>
#include <map>
#include <string>
#include <utility>

#include <cmath>
#include <ios>
#include <memory>

#include "MyMath.hpp"

typedef std::string str;


int main() {

	std::locale::global(std::locale("")); // Set the global locale to utf-8

	myMath mm{};

	std::locale loc("");
	std::cout.imbue(loc);

	constexpr const long double ldPi {mm.getPi()};

	constexpr const long double ldPi_x2 {mm.multPi(2.0l)};

	constexpr const long double a = 4;

	constexpr const long double ldPiSqr {mm.PiSqur(a)};

	constexpr const long double ldPiPow = mm.PiPow(a);
		
	std::cout << std::setprecision(50) << "Pi: " << ldPi 
		<< " \nldPi_x2: " << ldPi_x2 << " \nldPiSqr: " << ldPiSqr << " \nldPiPow: " << ldPiPow << '\n';

	std::flush(std::cout);
	std::cin.get();
	return 0;
}
