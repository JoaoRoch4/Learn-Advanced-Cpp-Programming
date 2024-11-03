#include <iostream>
#include <string>
#include <type_traits>

#define out std::cout
typedef std::string str;
typedef str STR;

template<class T>
void print(T n) {
	out << "template version: " << n << '\n';
}

void print(int value) {
	out << "Non-template version: " << value << '\n';
}

template<class T>
void show() {
	out << t() << '\n';
}

int main() {

	print<const char *>("a");
	print(5);
	std::cin.get();
	return 0;
}
