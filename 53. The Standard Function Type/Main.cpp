// Author: João Rocha.
// Date:  "Dec 18 2024"
// Version: 1.0.0
// P ath: "C:\\Users\\jubar\\OneDrive\\Cursos\\Programacao\\C++\\Learn Advanced C++ Programming\\
// 53. The Standard Function Type\\Main.cpp"

// #include "MyTypes.hpp"

#include <algorithm>
#include <functional>
#include <iostream>
#include <memory>

typedef std::string              str;
typedef std::vector<str> vecStr;

class Check {

public:
    bool operator()(const str &test) { return test.size() == 5; }
} check1;

bool check(const str &test) { return test.size() == 2; }

void run(std::function<bool(const str&)> check) {

    const str test = "dog";
    
    std::cout << check(test) << '\n';
}

double Div(double a, double b) {

    if (a == 0 || b == 0) throw std::runtime_error("Erro: divisão por zero!");
    return a / b;
}

double multiply(double a, double b) { return a * b; }

int main() {

    setlocale(0, "");

    vecStr vec {"one", "two", "three"};
    char   size  = 5;
    char   size2 = 3;
    auto   check2 {std::make_unique<Check>()};

    int64_t count
      = std::count_if(vec.begin(), vec.end(), 
        [&size](str test) { return test.size() == size; });
    std::cout << count << '\n';

    auto pass = [&size2](str test) -> bool { return test.size() == size2; };
    count = std::count_if(vec.begin(), vec.end(), pass);
    std::cout << count << '\n';

    count = std::count_if(vec.begin(), vec.end(), check);
    std::cout << count << '\n';
     
    count = std::count_if(vec.begin(), vec.end(), check1);
    std::cout << count << '\n';

    count = std::count_if(vec.begin(), vec.end(), *check2);
    std::cout << count << '\n';

    run(pass);
    run(check1);
    run(check);

    std::function<int(int, int)> add = [](int one, int two) { return one + two; };
    std::cout << add(7, 3) << '\n';

    double (*funcPtr)(double, double) {Div};

    try {

        long double x = 10;
        long double y = 2;

        std::cout << "Resultado: " << funcPtr(x, y) << std::endl;

        // Isso causaria uma exceção:

        double z = 0;

        std::cout << "Resultado: " << funcPtr(x, z) << std::endl;

    } catch (const std::exception &e) {

        std::cerr << e.what() << std::endl;
    }

    std::cout << "still running\n";

    funcPtr = {};

    funcPtr = multiply;

    std::cout << funcPtr(2, 4) << '\n';

    auto lambda = [](char a, char b) { return a + b; };

    int (*lambdaPtr)(char, char) {lambda};

    std::cout << lambdaPtr(5, 5) << '\n';


    check2.reset();
    check2 = {};
    funcPtr = {};
    lambdaPtr = {};

    std::cin.get();
    return 0;
}
