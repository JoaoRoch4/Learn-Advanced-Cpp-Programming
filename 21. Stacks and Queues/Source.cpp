#include <cstdint>
#include <iostream>
#include <string>
#include <stack>
#include <queue>

class Test {

private:

	std::string m_name;

public:

	Test(std::string name): m_name(name) {}

	~Test() {
		//std::cout << "Object " << m_name << " destroyed\n";
	}

	void print() {
		std::cout << m_name << '\n';
	}

};

int main() {

	std::stack<Test> testStack;

	testStack.push(Test("Mike"));
	testStack.push(Test("John"));
	testStack.push(Test("Sue"));

	while (testStack.size() > 0) {

		Test &test = testStack.top();
		test.print();
		testStack.pop();
	}

	std::cout << '\n';

	std::queue<Test> testQueue;

	testQueue.push(Test("Mike"));
	testQueue.push(Test("John"));
	testQueue.push(Test("Sue"));

	while (testQueue.size() > 0) {

		Test &test = testQueue.front();
		test.print();
		testQueue.pop();
	}

	/*
	Test& test1 = testStack.top();
	testStack.pop();
	test1.print();

	std::cout << '\n';

	testStack.pop();
	Test test2 = testStack.top();
	test2.print();

	*/

	std::cin.get();
	return 0;
}