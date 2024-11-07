#pragma once

#define pure_virtual 0

class Animal {

public:

    virtual void speak() = pure_virtual;

    virtual void run()   = pure_virtual;
};


