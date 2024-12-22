// Author: João Rocha.
// Date:  "Dec 18 2024"
// Version: 1.0.0
// P ath: "C:\\Users\\jubar\\OneDrive\\Cursos\\Programacao\\C++\\Learn Advanced C++ Programming\\
// 56. Elision and Optimization.avi\\Main.cpp"

// #include "MyTypes.hpp"

#include "Test.hpp"

#include <vector>
#include <memory>

std::ostream &operator<<(std::ostream &out, const Test &test) {

    out << "Hello from test";
    return out;
}

Test getTest() { return Test(); }

int main() {

    auto                test1 {std::make_unique<Test>(10)};
    Test               *testPtr {Test::GetTestPtr()};
    Test               *VNew = new Test;
    std::vector<Test>   vec;
    std::vector<Test *> vecPtr;
    Test *ptr = testPtr;

    ptr->Print("ptr\n");
    std::cout << *test1 << '\n';

    testPtr->Print("testPtr\n");

    vecPtr.push_back(testPtr);
    vecPtr.push_back(ptr);
    vecPtr.push_back(VNew);

    std::cout << testPtr << '\n';

    vec.push_back(Test());
    vec.push_back(*testPtr);
    vec.push_back(*ptr);
    vec.push_back(*VNew);

    int num = testPtr->getNum();

    std::cout << num << '\n';

    const str word = ptr->getWord();

    std::cout << word << '\n';

    vec.clear();
    vec.shrink_to_fit();
    vecPtr.clear();
    vecPtr.shrink_to_fit();
    test1.reset();
    test1   = {};
    testPtr = {};
    ptr     = {};
    delete VNew;
    VNew = {};

    std::cin.get();
    return 0;
}
