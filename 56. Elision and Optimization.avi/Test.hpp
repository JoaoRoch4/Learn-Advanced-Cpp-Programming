#pragma once

#include "MyTypes.hpp"

class Test {

    int num ;
    const str word;

public:
    Test() : num(20), word("dog") { std::cout << "Constructor\n"; }

    Test(int i) : Test() { std::cout << "Parameterized Constructor\n"; }

     Test(const Test &other) : Test() { std::cout << "Copy Constructor\n"; }

    Test &operator=(const Test &other) {

        std::cout << "Assignment\n";
        return *this;
    }

    static Test *GetTestPtr() {
        static Test instance; // Instância única (alocada estaticamente)
        std::cout << "GetTestPtr() called\n";
        return &instance;
    }

    void Print(const str &txt) { std::cout << txt; }

    const int getNum() { return num; }

    const str getWord() { return word; }

    ~Test() { std::cout << "Destructor\n"; }

    friend std::ostream &operator<<(std::ostream &out, const Test &test);
};