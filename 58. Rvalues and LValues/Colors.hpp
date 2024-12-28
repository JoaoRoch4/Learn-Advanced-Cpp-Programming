#pragma once

#ifdef _WIN32
#define NOMINMAX
#include <Windows.h>
#define setUTF8()                                                                                  \
    setlocale(0, "");                                                                              \
    SetConsoleOutputCP(CP_UTF8);
#else
#define setUTF8() setlocale(LC_ALL, "en_US.UTF-8");
#endif // __WIN32

#include <iostream>

enum class ColorEnum {

    reset,
    none,
    grey,
    red,
    green,
    yellow,
    blue,
    magenta,
    cyan,
    white,
    bright_grey,
    bright_red,
    bright_green,
    bright_yellow,
    bright_blue,
    bright_magenta,
    bright_cyan,
    bright_white
};

class Colors {

    ColorEnum   color;

public:
    
    Colors() : color(ColorEnum::none) { setUTF8(); }

    static std::ostream &ChangeColor(const ColorEnum &color) noexcept;

        
    ~Colors() { color = ColorEnum::reset; }
};
