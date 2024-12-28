#include "Test.hpp"
#include "termcolor.hpp"

#include <cstdint>
#include <cassert>
#include <iostream>
#include <string>
#include <sstream>
#include <io.h>
#include <windows.h>

using namespace termcolor;


void Test::show(const std::string &name, const Test &Var) const noexcept {

    const auto &Val {Var.getVal()};
    const auto &Word {Var.getWord()};
    const auto &Real {Var.getReal()};

    const bool haveValue = (Val != 0 && Word != "" && Real != 0.0);

    if (haveValue) {
        std::cout << '\n'
                  << name << " address : " << termcolor::green << '&' << &name << '\n'
                  << termcolor::reset << name << " Val: " << termcolor::green << Var.getVal()
                  << '\n'
                  << termcolor::reset << name << " Word: " << termcolor::green << Var.getWord()
                  << '\n'
                  << termcolor::reset << name << " real: " << termcolor::green << Var.getReal()
                  << termcolor::reset << '\n'
                  << std::endl;
    }

    if (!haveValue) {
        std::cout << '\n'
                  << name << " address : " << termcolor::red << '&' << &name << '\n'
                  << termcolor::reset << name << " Val: " << termcolor::red << 0 << '\n'
                  << termcolor::reset << name << " Word: " << termcolor::red << "" << '\n'
                  << termcolor::reset << name << " real: " << termcolor::red << 0
                  << termcolor::reset << '\n'
                  << std::endl;
    }
}

void Test::show(const std::string &name, const Test *ptr) {

    const bool isNullptr {ptr == nullptr};

    const int         &Val {(isNullptr) ? (0) : (ptr->getVal())};
    const std::string &Word {(isNullptr) ? ("") : (ptr->getWord())};
    const double      &Real {(isNullptr) ? (0.0) : (ptr->getReal())};

    std::cout << '\n'
              << termcolor::blue << name << ": \n"
              << "Pointer address: " << termcolor::green << &ptr << '\n'
              << termcolor::blue << name << termcolor::reset << " address : " << termcolor::green
              << ptr << '\n'
              << termcolor::blue << name << termcolor::reset << " Val: " << termcolor::green << Val
              << '\n'
              << termcolor::blue << name << termcolor::reset << " Word: " << termcolor::green
              << Word << '\n'
              << termcolor::blue << name << termcolor::reset << " real: " << termcolor::green
              << Real << termcolor::reset << '\n'
              << std::endl;
}

void Test::show(const std::string &name, const Test *ptr, bool isSmartPtr,
  const std::string type) const noexcept {

    const bool isNullptr {ptr == nullptr};

    const int         &Val {(isNullptr) ? (0) : (ptr->getVal())};
    const std::string &Word {(isNullptr) ? ("") : (ptr->getWord())};
    const double      &Real {(isNullptr) ? (0.0) : (ptr->getReal())};
   
    std::cout << '\n'
              << PrintName("Smart", false) << type << " pointer: " << name << ": \n"
              << "Pointer address: " << PrintPtr(&ptr) << '\n'
              << PrintPtr(&ptr) << " object address : " << PrintPtr(ptr) << '\n'
              << PrintName(name, false) << " Val: " << Val << '\n'
              << termcolor::blue << name << termcolor::reset << " Word: " << termcolor::green
              << Word << '\n'
              << termcolor::blue << name << termcolor::reset << " real: " << termcolor::green
              << Real << termcolor::reset << '\n'
              << std::endl;
}

std::ostream &operator<<(std::ostream &out, const Test &test) { return out; }

std::ostream &operator<<(std::ostream &out, const Test *test) { return out; }
