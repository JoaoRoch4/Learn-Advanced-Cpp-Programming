// Author: João Rocha.
// Date:  "Nov 29 2024"
// Version: 1.0.0
// P ath: "C:\\Users\\jubar\\OneDrive\\Cursos\\Programacao\\C++\\Learn Advanced C++ Programming\\
// 45. Initialization in C++ 98\\Main.cpp"

// #include "MyTypes.hpp"

#include <iostream>
#include <random>
#include <string>
#include <vector>

typedef std::string      str;
typedef std::vector<str> vecstr;
typedef std::uniform_int_distribution<uint32_t> uidi32;


unsigned int getNum() {

    static std::random_device rd {};
    static std::mt19937_64    mt {rd()};
    static uidi32             di {1U, 999999U};
    static uint32_t           num_rand     = {};
    static uint32_t           old_num_rand = {};
    static uint32_t           counts       = {};

    // Buffer the previous number and Guaranties that won't give a repeated number
    [[likely]]
    if (counts >= 0) old_num_rand = num_rand;

    [[unlikely]]
    if ((old_num_rand == num_rand) && (counts < 0)) getNum();

    const size_t value_geted {di(mt)};
    num_rand                 = static_cast<uint32_t>(value_geted);

    counts++;
    return num_rand;
}

class C {

public:
    str      text;
    uint32_t id;
};

struct S {

    str      text;
    uint32_t id;
};

struct R {

    str      text;
    uint32_t id;
} r1, r2 = {"Hi from r2 struct inline instance", getNum()};

int Start() {

    C c1 = {"Hello from c class", getNum()};
    S s1 = {"Hello from s struct", getNum()};
    r1   = {"Hello from r1 struct instance", getNum()};

    std::cout << c1.text << ' ' << c1.id << "\n"
              << s1.text << ' ' << s1.id << "\n"
              << r1.text << ' ' << r1.id << "\n"
              << r2.text << ' ' << r2.id << "\n";

    vecstr strings;

    strings.push_back("One");
    strings.push_back("Two");
    strings.push_back("Three");

    return 0;
}

int main() {

    Start();
    std::cin.get();
    return 0;
}
