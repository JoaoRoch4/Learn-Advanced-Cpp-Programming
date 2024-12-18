// Author: João Rocha.
// Date: "Nov 30 2024"
// Version: 1.0.0
//  Path: "C:\\Users\\jubar\\OneDrive\\Cursos\\Programacao\\C++\\Learn Advanced C++ Programming\\
//47. Initializer Lists\\Main.cpp"

#include "MyTypes.hpp"
#include "Test.hpp"

#include <initializer_list>

static void Start() {

    Test test {"apple", "orange", "banana", "\n"};

    test.print({"one", "two", "three"});
}

int main() {

    setUTF8();
    headerShow();
    Start();
    std::cin.get();
    return 0;
}
