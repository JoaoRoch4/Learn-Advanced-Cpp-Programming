#pragma once

#include <iostream>
#include <memory>
#include "termcolor.hpp"

class Test {

    const static int     SIZE {100};
    std::shared_ptr<int> _pBuffer;
    int                  Val;
    std::string          Word;
    double               real;

public:

        friend std::ostream &operator<<(std::ostream &out, const Test &test);
    friend std::ostream &operator<<(std::ostream &out, const Test *test);

    
    Test() : _pBuffer(nullptr), Val(-1), Word("Default"), real(-0.1)  {

        if (_pBuffer == nullptr) _pBuffer = std::make_shared<int>(SIZE);
        std::cout << "Constructor\n\n";
    }

    Test(const int &Val, const std::string &str, const double &real)
     : _pBuffer(nullptr), Val(Val), Word(str), real(real) {

        if (_pBuffer == nullptr) _pBuffer = std::make_shared<int>(SIZE);
        std::cout << "Parameterized Constructor\n\n";
    }
    // make a copy constructor
    Test(const Test &test) : _pBuffer(nullptr), Val(test.Val), Word(test.Word), real(test.real) {
        if (_pBuffer == nullptr) _pBuffer = std::make_shared<int>(SIZE);
        std::cout << "Copy Constructor\n\n";
    }
       

    Test(const std::unique_ptr<Test>(&test))
     : _pBuffer(nullptr), Val(test->Val), Word(test->Word), real(test->real) {
        if (_pBuffer == nullptr) _pBuffer = std::make_shared<int>(SIZE);
        std::cout << "unique_ptr Copy Constructor\n\n";
    }

    Test(const std::shared_ptr<Test>(&test))
     : _pBuffer(nullptr), Val(test->Val), Word(test->Word), real(test->real) {
        if (_pBuffer == nullptr) _pBuffer = std::make_shared<int>(SIZE);
        std::cout << "shared_ptr Copy Constructor\n\n";
    }

    Test(bool i) : _pBuffer(nullptr), Val(0), Word(""), real(0.0) {}  
    
    static Test GetTestStatic() {

        std::cout << "GetTestStatic() called\n\n";
        Test a;
        return a;
    }

    static Test GetTestStatic(const int &Val, const std::string &str, const double &real) {

        std::cout << "GetTestStatic(args) called\n\n";
        Test a(Val, str, real);
        return a;
    }

    Test GetTest() {

        std::cout << "GetTest() called\n\n";
        return *this;
    }

    Test GetTest(const int &Val, const std::string &str, const double &real) {

        std::cout << "GetTest(args) called\n\n";
        return Test(Val, str, real);
    }

    static Test *staticTestPtr() {

        std::cout << "* staticTestPtr() called\n\n";
        static Test ptr;
        return &ptr;
    }

    static Test *staticTestPtr(const int &Val, const std::string &str, const double &real) {

        std::cout << "* staticTestPtr(args) called\n\n";
        static Test ptr(Val, str, real);
        return &ptr;
    }

    Test *GetTestPtr() {

        std::cout << "GetTestPtr() called\n\n";

        static Test ptr;

        return &ptr;
    }

    Test *GetTestPtr(const int &Val, const std::string &str, const double &real) {

        std::cout << "GetTestPtr(args) called\n\n";

        static Test ptr(Val, str, real);

        return &ptr;
    }

    inline const Test DeleteAll() noexcept {
        DeleteBuffer();
        return Test(true);
    }

    inline const void setVal(const int &val) noexcept { Val = val; }
    inline const void setWord(const std::string &word) noexcept { Word = word; }
    inline const void setReal(const double &Real) noexcept { real = Real; }

    inline const int          getVal() const noexcept { return Val; }
    inline const std::string &getWord() const noexcept { return Word; }
    inline const double       getReal() const noexcept { return real; }

    inline const void DeleteVal() noexcept { Val = 0; }
    inline const void DeleteWord() noexcept { Word = ""; }
    inline const void DeleteReal() noexcept { real = 0.0; }   

     
    void show(const std::string &name, const Test &Var) const noexcept;
    void show(const std::string &name, const Test *ptr);
    void show(const std::string &name, const Test *ptr,
       bool isSmartPtr = false,
      const std::string type = std::string()) const noexcept;

    template<typename CharT>
     inline void show(const std::string &name, const std::unique_ptr<Test> &ptr) const noexcept {
        return show(name, ptr.get(), true, "unique");
    }
    template<typename CharT>
    inline void show(const std::string &name, const std::shared_ptr<Test> &ptr) const noexcept {
                return show(name, ptr.get(), true, "shared");
    }

  private : 
    
    inline const void DeleteBuffer() noexcept {

        _pBuffer.reset();
        _pBuffer = {};
    }

public:
    ~Test() {

        const bool empty {
          ((_pBuffer == nullptr || *_pBuffer == 0) || (Val == 0 && Word == "" && real == 0.0))};

        if (empty) return;

        std::cout << termcolor::red << "Destructor\n" << termcolor::reset;
        DeleteAll();
        std::flush(std::cout);
    }
};