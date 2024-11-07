// 37. Abstract Classes and Pure Virtual Functions.cpp : This file contains the 'main' 
//  function. Program execution begins and ends there.

#include <iostream>

#include "Labrador.hpp"

void test(Animal *a) {

    a->run();
}

int main()
{
    Labrador lab;
    lab.run();
    lab.speak();

    Animal *animals[5] {};
    animals[0] = &lab;
    animals[0]->speak();

    test(&lab);

    std::cin.get();
    return 0;
}

