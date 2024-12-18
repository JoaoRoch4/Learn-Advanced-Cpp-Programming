//Author: João Rocha. 
//Date:  "Nov 15 2024"
//Version: 1.0.0
//Path: "C:\\Users\\jubar\\OneDrive\\Cursos\\Programacao\\C++\\Learn Advanced C++ Programming\\
// 41. Range-Based Loops\\Main.cpp"

/*
“ 
    I just wanted to tell you that with all your faults I love you.
    I love or revere very few people. As for the rest,
    I’m ashamed of my indifference to them. But for those I love,
    nothing and no one, neither I nor certainly they themselves,
    can ever make me stop loving them. It took me a long time to learn that;
    now I know it.
    ”     

    ― Albert Camus
*/

#include "MyTypes.hpp"

int main() {

    setUTF8();
    headerShow();

    auto texts = {"one", "two", "three"};

    for (auto &text : texts) out << text << "\n";
    
    vec Numbers;

    Numbers.push_back(5);
    Numbers.push_back(7);
    Numbers.push_back(9);
    Numbers.push_back(11);

    for (auto &number : Numbers) out << number << '\n';

    str Hello {"Hello"};

    for (auto &c : Hello) out << c << '\n';

    std::cin.get();
    return 0;
}
