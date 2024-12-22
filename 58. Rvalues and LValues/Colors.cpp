#include "Colors.hpp"

std::ostream &Colors::ChangeColor(const ColorEnum &color) noexcept {

    switch (color) {

        case ColorEnum::reset : [[fallthrough]];
        case ColorEnum::none : return std::cout << "" << termcolor::reset;
        case ColorEnum::grey : return std::cout << "" << termcolor::grey;
        case ColorEnum::red : return std::cout << "" << termcolor::red;
        case ColorEnum::green : return std::cout << "" << termcolor::green;
        case ColorEnum::yellow : return std::cout << "" << termcolor::yellow;
        case ColorEnum::blue : return std::cout << "" << termcolor::blue;
        case ColorEnum::magenta : return std::cout << "" << termcolor::magenta;
        case ColorEnum::cyan : return std::cout << "" << termcolor::cyan;
        case ColorEnum::white : return std::cout << "" << termcolor::white;
        case ColorEnum::bright_grey : return std::cout << "" << termcolor::bright_grey;
        case ColorEnum::bright_red : return std::cout << "" << termcolor::bright_red;
        case ColorEnum::bright_green : return std::cout << "" << termcolor::bright_green;
        case ColorEnum::bright_yellow : return std::cout << "" << termcolor::bright_yellow;
        case ColorEnum::bright_blue : return std::cout << "" << termcolor::bright_blue;
        case ColorEnum::bright_magenta : return std::cout << "" << termcolor::bright_magenta;
        case ColorEnum::bright_cyan : return std::cout << "" << termcolor::bright_cyan;
        case ColorEnum::bright_white : return std::cout << "" << termcolor::bright_white;
        default : return std::cout << "" << termcolor::reset;
    }
}
