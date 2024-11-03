// 35. Using Function Pointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

typedef std::vector<std::string> VecStr;

bool Match(std::string test) {

    return test.size() == 3;
}

int CountStrings(VecStr &texts, bool (*match)(std::string test)) {

    int tally {};

    for (int i = 0; i < texts.size(); i++) 
        if (match(texts[i])) tally++;
         
    return tally;
}

int main() {

    VecStr texts;

    texts.push_back("one");
    texts.push_back("two");
    texts.push_back("three");
    texts.push_back("two");
    texts.push_back("two");
    texts.push_back("three");

    std::cout << std::count_if(texts.begin(), texts.end(), &Match) << '\n';

    std::cout << CountStrings(texts, Match) << '\n';

    std::cin.get();
}


