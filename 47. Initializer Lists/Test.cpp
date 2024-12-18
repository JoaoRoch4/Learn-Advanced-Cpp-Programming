#include "Test.hpp"

#include <initializer_list>

Test::Test(std::initializer_list<str> txt) {

    for (auto &v : txt) out << v << '\n';
}

void Test::print(std::initializer_list<str> txt) {

      for (auto &v : txt) out << v << '\n';
}
