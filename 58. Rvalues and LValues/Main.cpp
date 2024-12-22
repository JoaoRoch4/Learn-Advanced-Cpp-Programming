// Author: João Rocha.
// Date:  "Dec 19 2024"
// Version: 1.0.0
// P ath: "C:\\Users\\jubar\\OneDrive\\Cursos\\Programacao\\C++\\
// Learn Advanced C++ Programming\\58. Rvalues and LValues\\Main.cpp"

#include "Test.hpp"
#include "termcolor.hpp"

#include <iostream>
#include <vector>
#include <memory>


int main() {

    Test  test {};
    Test  testArgs {10, "cat", 3.14};
    auto  unique {std::make_unique<Test>()};
    auto  uniqueArgs {std::make_unique<Test>(50, "Dog", 1.4)};
    auto  shared {std::make_shared<Test>()};
    auto  shared2 {std::make_shared<Test>(shared)};
    auto  sharedArgs {std::make_shared<Test>(70, "Bear", 2.5)};
    auto  sharedArgs2 {std::make_shared<Test>(sharedArgs)};
    Test *testRawPtr {Test::staticTestPtr()};
    Test *testRawPtrArgs {Test::staticTestPtr(30, "Monkey", 1.9999999)};
    Test *NVar {new Test()};
    Test *NVarArgs {new Test(200, "Goat", 48564856.74586)};

    Test a = Test(false);
    a.show("test", test);
    a.show("testArgs", testArgs);
    a.show("unique", unique);
    a.show("uniqueArgs", uniqueArgs);
    a.show("shared", shared);
    a.show("shared2", shared2);
    a.show("sharedArgs", sharedArgs);
    a.show("sharedArgs2", sharedArgs2);
    a.show("testRawPtr", testRawPtr);
    a.show("testRawPtrArgs", testRawPtrArgs);
    a.show("NVar", NVar);
    a.show("NVarArgs", NVarArgs);

    test = test.DeleteAll();
    testArgs = testArgs.DeleteAll();
    unique.reset();
    unique = {};
    uniqueArgs.reset();
    uniqueArgs = {};
    shared.reset();
    shared = {};
    sharedArgs.reset();
    sharedArgs = {};
    testRawPtr = {};
    testRawPtrArgs = {};
    delete NVar;
    NVar = {};
    delete NVarArgs;
    NVarArgs = {};

    const std::string l  
    (R"(
    40: test = test.DeleteAll();
    41: testArgs = testArgs.DeleteAll();
    42: unique.reset();
    43: unique = {};
    44: uniqueArgs.reset();
    45: uniqueArgs = {};
    46: shared.reset();
    47: shared = {};
    48: sharedArgs.reset();
    49: sharedArgs = {};
    50: testRawPtr = {};
    51: delete NVar;
    52: NVar = {};
    53: delete NVarArgs;
    54: NVarArgs = {}; )");

    std::cout << termcolor::bright_yellow << l << termcolor::reset << "\n\n";  

    a.show("test", test);
    a.show("testArgs", testArgs);
    a.show("unique", unique);
    a.show("uniqueArgs", uniqueArgs);
    a.show("shared", shared);
    a.show("sharedArgs", sharedArgs);
    a.show("testRawPtr", testRawPtr);
    a.show("testRawPtrArgs", testRawPtrArgs);
    a.show("NVar", NVar);
    a.show("NVarArgs", NVarArgs);

    std::cin.get();
    return 0;
}
