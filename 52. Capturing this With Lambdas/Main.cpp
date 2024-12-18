//Author: João Rocha. 
//Date:  "Dec 18 2024"
//Version: 1.0.0
//Path: "C:\\Users\\jubar\\OneDrive\\Cursos\\Programacao\\C++\\Learn Advanced C++ Programming\\
// 52. Capturing this With Lambdas\\Main.cpp"

#include "MyTypes.hpp"

#include "Test.h"

#include "memory"

int Start(){

    auto test = std::make_unique<Test>();
    test->run();

    return 0; 
}

int main() {

    setUTF8();
    headerShow();

    Start();

    std::cin.get();
    return 0;
}
