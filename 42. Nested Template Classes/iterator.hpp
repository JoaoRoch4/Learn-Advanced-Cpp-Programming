#pragma once

#include "ring.hpp"
#include <iostream>

template<class T>
class ring<T>::iterator {

 public:

    void print() { std::cout << "Hello from iterator"; };

};

