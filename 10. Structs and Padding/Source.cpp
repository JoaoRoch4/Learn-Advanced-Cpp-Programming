#include <iostream>

#pragma pack(push, 1)
struct Person {

	char name[50];
	int age;
	double weight;

	Person() = default;
};
#pragma pack(pop)

int main() {


	std::cin.get();
	return 0;
}