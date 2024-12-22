// Author: João Rocha.
// Date:  "Dec 18 2024"
// Version: 1.0.0
// P ath: "C:\\Users\\jubar\\OneDrive\\Cursos\\Programacao\\C++\\Learn Advanced C++ Programming\\
// 55. Delegating Constructors\\Main.cpp"

#include "MyTypes.hpp"

#include "Parent.hpp"
#include "Child.hpp"

#include <memory>

int main() {

    setUTF8();
    headerShow();

    auto parent {std::make_unique<Parent>("Hello")};
    auto child  {std::make_unique<Child>()};

    std::cin.get();
    return 0;
}
