#pragma once

#include "MyTypes.hpp"

#include <memory>

class Test {

    const static int SIZE {100};
    int             *_pBuffer {};

public:
    Test() {

        std::cout << "Constructor\n";

        _pBuffer = new int [SIZE] {};
    }

    Test(int i) {

        std::cout << "Parameterized Constructor\n";

        _pBuffer = new int [SIZE] {};

        for (int i = 0; i < SIZE; i++) _pBuffer [i] = 7 * i;
    }

    Test(const Test &other) {

        std::cout << "Copy Constructor\n";

        _pBuffer = new int [SIZE] {};
        
        std::memcpy(_pBuffer, other._pBuffer, SIZE * sizeof(int));
    }

    Test &operator=(const Test &other) {

        std::cout << "Assignment\n";

         _pBuffer = new int [SIZE] {};

        std::memcpy(_pBuffer, other._pBuffer, SIZE * sizeof(int));

        return *this;
    }

    static Test *GetTestPtr() {

        static Test instance {};

        std::cout << "GetTestPtr() called\n";

        return &instance;
    }

    ~Test() {

        std::cout << "Destructor\n";

        delete [] _pBuffer;
        _pBuffer = {};
    }

    // friend std::ostream &operator<<(std::ostream &out, const Test &test);
};