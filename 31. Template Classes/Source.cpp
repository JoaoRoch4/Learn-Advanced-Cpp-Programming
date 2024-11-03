#include <iostream>
#include <string>
#include <type_traits>

#define out std::cout
typedef std::string str;
typedef str STR;

template<class t>
class Test {
private:

	t obj;

public:

	Test(t obj) {
		this->obj = obj;
	}

	void print() {
		out << obj << '\n';
	}

	
};

int main() {

	Test<str> test1("hello");
	test1.print();
	
	out << '\n';
	
	std::cin.get();
	return 0;
}
