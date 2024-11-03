#include <algorithm>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>
#include <deque>

class Test {

	int m_id;
	std::string m_name;

public:

	Test(): m_id(0), m_name("") {};

	Test(int id, std::string name): m_id(id), m_name(name) {}

	~Test() {
		//std::cout << "Object " << m_name << " destroyed\n";
	}

	void print() {
		std::cout << m_id << ": \t" << m_name << '\n';
	}

	bool operator<(const Test &other) const {
		return (m_name == other.m_name) ? m_id < other.m_id : m_name < other.m_name;
	}

	friend bool comp(const Test &a, const Test &b);
};

bool comp(const Test &a, const Test &b) {
	return a.m_name < b.m_name;
}

int main() {
		 
	std::deque<Test> vecTest;

	vecTest.push_back(Test(5, "Mike"));
	vecTest.push_back(Test(10, "Sue"));
	vecTest.push_back(Test(7, "Raj"));
	vecTest.push_back(Test(3, "Vicky"));
	vecTest.push_back(Test(15, "Aba"));
	vecTest.push_back(Test(22, "Catharine"));
	vecTest.push_back(Test(38, "Beatrix"));
	vecTest.push_back(Test(32, "Sara"));

	std::sort(vecTest.begin(), vecTest.end(), comp);

	for (int8_t i = 0; i < vecTest.size(); i++)
		vecTest[i].print();

	std::cin.get();
	return 0;
}