//Author: João Rocha. 
//Date:  "Dec 16 2024"
//Version: 1.0.0
//Path: "C:\\Users\\jubar\\OneDrive\\Cursos\\Programacao\\C++\\Learn Advanced C++ Programming\\
// 48. Object Initialization, Default and Delete\\Main.cpp"

#include "MyTypes.hpp"

#include<iostream>
#include <string>


class Test {
    int    id {3};
    string name {"Mike"};

public:
    Test()                             = default;
    Test(const Test &other)            = delete;
    Test &operator=(const Test &other) = delete;

    Test(int id) : id(id) {}

    void print() { out << id << ": " << name << "\n"; }
};

int main() {

    Test test;
    test.print();

    Test test1(77);
    test1.print();

    /**
     * Won't work, we deleted them.
     */
    // test2 = test;

    return 0;
}