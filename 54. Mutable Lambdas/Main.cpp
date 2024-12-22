//Author: João Rocha. 
//Date:  "Dec 18 2024"
//Version: 1.0.0
//Path: "C:\\Users\\jubar\\OneDrive\\Cursos\\Programacao\\C++\\Learn Advanced C++ Programming\\
// 54. Mutable Lambdas\\Main.cpp"

#include "MyTypes.hpp"

int main() {

    setUTF8();
    headerShow();

    int cats {5};
     
    [cats]() mutable {

        cats = 8;
        out << cats << '\n';
    }();

    std::cin.get();
    return 0;
}
