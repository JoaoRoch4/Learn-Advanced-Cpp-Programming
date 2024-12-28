// Author: João Rocha.
// Date:  "Dec 22 2024"
// Version: 1.0.0
// Path: "C:\\Users\\jubar\\OneDrive\\Cursos\\Programacao\\C++\\Learn Advanced C++
// Programming\\TestColors\\Main.cpp"

#include "MyTypes.hpp"

int main() { 

    setUTF8();

    Colors a;

    std::cout << "Hello World!" << StaticColors::UseColor(ColorEnum::bright_blue) << " test"
              << StaticColors::ResetColors() << '\n';

    std::cout << "Hello World!" << a.UseColor(BackgroundColorEnum::on_white) << " test"
              << std::endl;

   StaticColors::ResetColors();

    //StaticError::Catch();
}


