#include <iosfwd>
#include <iostream>
#include <string>

#define none void(0) 

void MightGoWrong() {

	bool error1 = false;
	bool error2 = false;
	bool error3 = true;

	(error1) ? throw "something went wrong" : none;

	(error2) ? throw std::string("Something else went wrong") : none;

	(error3) ? throw 8.1f : none;
}

static void UsesMightGoWrong() {

	return MightGoWrong();
}

void Start() {

	try {
		UsesMightGoWrong();

	} catch (int e) {
		std::cout << "Error code: " << e << std::endl;

	} catch (const char *e) {
		std::cout << "Error message: " << e << std::endl;

	} catch (std::string &e) {
		std::cout << "String error message: " << e << std::endl;

	} catch (...) {
		std::cout << "Unknown error" << std::endl;
	}

	std::cout << "Still running" << std::endl;

}

int main() {

	Start();

	return 0;
}