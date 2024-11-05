// 36. Object Slicing and Polymorphism.cpp 

#include <iostream>
#include <string>

class Parent {

public:

    Parent(){};
    
    Parent(const Parent &other){
    
        std::cout << "Copy parent\n";
    }

    virtual void print() {
        std::cout << "parent\n";
    }

    virtual ~Parent(){};
};

class Child : public Parent {

public:

    void print() {
        std::cout << "child\n";
    }
};

int main() {
    
    Child c1;
    Parent &p1 = c1;
    p1.print();

    Parent p2 = Child();
    p2.print();

    std::cin.get();
    return 0;
}

