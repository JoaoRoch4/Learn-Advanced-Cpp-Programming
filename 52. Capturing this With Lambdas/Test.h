#pragma once

#include "MyTypes.hpp"

class Test {

private:
    int one;
    int two;

public:
    Test() : one(1), two(2) {}

    void run() {

        int three {3};
        int four {4};

        auto pLambda = [this, three, four]() {

            out << one << '\n';
            out << two << '\n';
            out << three << '\n';
            out << four << '\n';
        };

        pLambda();
    }
};
