//Author: João Rocha. 
//Date:  "Nov 29 2024"
//Version: 1.0.0
//Path: "C:\\Users\\jubar\\OneDrive\\Cursos\\Programacao\\C++\\Learn Advanced C++ Programming\\
// 46. Initialization in C++ 11\\Main.cpp"

#include "MyTypes.hpp"

#include <memory>

static unsigned int Fun() {

    int32_t value {5};
    out << value << "\n\n";

    str text {"Hello"};
    out << text << "\n\n";

    int32_t numbers [] {1, 2, 4};
    out << numbers [1] << "\n\n";

    int32_t *pInts = new int32_t [] {1, 2, 3};
    out << pInts [1] << "\n\n";
    
    int *p {new int(value)};
    out << *p << "\n\n";
    *p = 10;
    *p = value;
   
    auto i {std::make_unique<int64_t>()};
    *i = 10;
    out << *i << "\n\n";

    size_t a {};
    a = *i;
    out << a << std::endl;

    i.reset();

    i = std::make_unique<int64_t>(10);
    *i = std::numeric_limits<int64_t>::max();
     
    struct S {

        int32_t val = 7;
        str     txt;

    } s1 {5, "Hi"};
    out << s1.txt << "\n\n";

    vecStr strings {"one", "two", "three"};
    out << strings [2] << "\n\n";

    delete [] pInts;
    delete p;
    i.reset();
    pInts = {};
    p     = {};
    i     = {};

    return 0;
}

int Start() {


    return 0; }

int main() {

    setUTF8();
    headerShow();
    Fun();
    Start();
    std::cin.get();
    return 0;
}
