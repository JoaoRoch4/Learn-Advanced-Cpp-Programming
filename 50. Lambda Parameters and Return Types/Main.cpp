// Author: João Rocha.
// Date:  "Dec 16 2024"
// Version: 1.0.0
// Path: "C:\\Users\\jubar\\OneDrive\\Cursos\\Programacao\\C++\\Learn Advanced C++ Programming
//  50. Lambda Parameters and Return Types\\Main.cpp"

#include "MyTypes.hpp"

#include <functional>

void testGreet(void (*greet)(const str &)) {

    greet("André"); 
}

double runDivide(double (*divide)(const double &a, const double &b)){

    auto rval = divide(9, 3);

    out << rval << '\n';

    return rval;
}

int start() {

    auto pGreet = [](const str& name) {

        out << "Hello " << name << '\n';
    };

    pGreet("João");

    testGreet(pGreet);

    auto pDivide = [](const double &a, const double &b) -> double { 

        if (a == 0.0 || b == 0.0) return 0.0;
        return a / b; };

    double a = pDivide(10.0, 0.0);

    out << a << '\n';

    double (*Divide)(double (*)(const double &, const double &)) {&runDivide};

    std::cout << *Divide;

    return 0;
}

int main() {

    setUTF8();
    headerShow();

    start();

    std::cin.get();
    return 0;
}
