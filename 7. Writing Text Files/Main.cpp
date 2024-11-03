#include <fstream>
#include <iosfwd>
#include <iostream>
#include <print>
#include <string>

int main() {

    std::ofstream ofstOutFile{};

    const std::string &sFileName {"test.txt"};

    ofstOutFile.open(sFileName);

    if (ofstOutFile.is_open()) {
        
        ofstOutFile << "Hello there!" << std::endl;
        ofstOutFile << "123" << std::endl;
        ofstOutFile << "Goodbye!" << std::endl;
        ofstOutFile.close();

    } else {

        std::println("Could not open file: %s for writing\n", sFileName);
    }

    std::cin.get();
    return 0;
}