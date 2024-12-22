#pragma once

#include "MyTypes.hpp"

class Parent {

    int dogs;
    str text;

public:

    Parent() : Parent("Hello") {

        out << "No parameter parent constructor.\n";
    }

    Parent(const str &text) : dogs(5), text(text) {

        out << "String parent constructor.\n";
    }

};
