#include <cstdio>
#include <fstream>
#include <iosfwd>
#include <iostream>
#include <print>
#include <string>

#pragma pack(push, 1)
struct Person {

	char Name [50];
	int Age;
	double Height;

};
#pragma pack(pop)

int main() {

	const std::string sFileName = "test.bin";

	Person someone = {"Frodo", 220, 0.8};

	// Write to a binary file
	std::ofstream ofsOutputFile{};

	ofsOutputFile.open(sFileName, std::ios::binary);

	if (ofsOutputFile.is_open()) {

		ofsOutputFile.write(reinterpret_cast<char *>(&someone), sizeof(Person));

		std::println("successfully wrote to file: {}\n", sFileName.c_str()); 

		ofsOutputFile.close();


	} else {

		ofsOutputFile.close();
		std::cerr << "Error: Unable to open file: " << sFileName << std::endl;
		return 1;
	}

	// Read from a binary file
	std::ifstream ifsInputFile {};
	Person someoneElse{};


	ifsInputFile.open(sFileName, std::ios::binary);

	if (ifsInputFile.is_open()) {

		ifsInputFile.read(reinterpret_cast<char *>(&someoneElse), sizeof(Person));

		std::print("successfully read to file: {}\n", sFileName.c_str());

		ifsInputFile.close();


	} else {

		ifsInputFile.close();
		std::cerr << "Error: Unable to read file: " << sFileName << std::endl;
		return 1;
	}

	std::cout << "Name: " << someoneElse.Name << ", Age: " << someoneElse.Age << ", Height: " << someoneElse.Height << std::endl;

	std::cin.get();
	return 0;
}