#include <exception>
#include <iostream>
#include <print>
#include <memory>


class MyException;
class Test;

class MyException : public std::exception {

public:

    inline MyException() noexcept {

		std::println("MyException created\n");
	}

    inline ~MyException() noexcept {

        std::println("MyException destroyed\n");
    }

    bool operator==(const MyException &other) const = default;

    constexpr inline void mtvDoSomething_NoexInl() noexcept {

        std::println("MyException created\n");
    }

    virtual const char *what() const noexcept override {

        return "Something bad happened!";
    }

};

class Test {

public:

    inline bool operator==(const Test &other) const = default;

    inline Test() noexcept {

        std::println("Test created\n");
    } 

    inline ~Test() noexcept {

        std::println("Test destroyed\n");
    }

	void goesWrong() {

		throw MyException();
	}     
        
};

int main() {

    std::unique_ptr<Test> m_test {std::make_unique<Test>()};
    
    try {

        m_test->goesWrong();

    } catch (MyException &e) {

		std::cout << e.what() << std::endl;
	}

    m_test.reset();
    std::cin.get();
    return 0;
}