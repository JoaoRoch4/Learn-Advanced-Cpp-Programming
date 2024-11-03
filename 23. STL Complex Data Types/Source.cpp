#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <vector>

typedef std::string str;

int main() {

	std::map<std::string, std::vector<short>> scores;
	
	scores["Mike"].push_back(10);
	scores["Mike"].push_back(20);
	scores["Vicky"].push_back(15);

	for (auto it = scores.begin(); it != scores.end(); it++) {

		str name = it->first;
		auto &scoreList = it->second;

		std::cout << name << ": ";

		for (int i = 0; i < scoreList.size(); i++) 
			std::cout << scoreList[i] << " ";

		printf("\n");		
	}
		
	std::cin.get();
	return 0;

}