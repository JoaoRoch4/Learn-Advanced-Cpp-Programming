//Author: João Rocha. 
//Date:  "Dec 16 2024"
//Version: 1.0.0
//Path: "C:\\Users\\jubar\\OneDrive\\Cursos\\Programacao\\C++\\Learn Advanced C++ Programming\\
// 49. Introducing Lambda Expressions\\Main.cpp"

#include "MyTypes.hpp"

void test(void(*pFunc)()){

    pFunc(); }

int main() {

    setUTF8();
    headerShow();

    auto func = []() { out << "Hello" << std::endl; };
    func();

    test( []() {
        out << "Hello again" << std::endl; });

    std::cin.get();
    return 0;
}
