//Author: João Rocha. 
//Date:  "Dec 16 2024"
//Version: 1.0.0
//Path: "C:\\Users\\jubar\\OneDrive\\Cursos\\Programacao\\C++\\Learn Advanced C++ Programming\\
// 51. Lambda Capture Expressions\\Main.cpp"

#include "MyTypes.hpp"

int main() {

    setUTF8();
    headerShow();

    int one = 1, two = 2, three = 3;

    // Capture one and two by value.
    [one, two]() { out << one; }();

    // Capture all local variables by value.
    [=]() { out << one; }();

    // Capture all local variables by value, but capture three by reference.
    [=, &three]() { out << one; }();

    // Capture all local variables by reference.
    [&]() { out << one; }();

    // Capture all local variables by reference.
    [&, two, three]() { out << one; }();

    std::cin.get();
    return 0;
}
