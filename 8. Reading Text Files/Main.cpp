#include <fstream>
#include <iosfwd>
#include <iostream>
#include <string>

int main() {

	const char* ccFileName = "test1.txt";	

	std::fstream ifsInFile;

	ifsInFile.open(ccFileName, std::ios::in); 

	if (ifsInFile.is_open()) {

		std::string sLine{};

		std::getline(ifsInFile, sLine);

		std::cout << sLine << '\n';

		ifsInFile.close();

	} else {

		std::cerr << "Error: Could not open file: " << ccFileName << std::endl;
		std::cin.get();
		return 1;
	}

	std::cin.get();
	return 0;
}