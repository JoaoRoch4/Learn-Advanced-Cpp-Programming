#include "Colors.hpp"

#include "Error.hpp"
#include "MyTypes.hpp"

#include "termcolor.hpp"

#include <__msvc_ostream.hpp>
#include <iosfwd>
#include <ostream>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>

Colors::Colors() noexcept
 : color(ColorEnum::none)
 , backgroundColor(BackgroundColorEnum::none)
 , isLocalized(false)
 , ColorReturnStr(std::string())
 , BackgroundReturnStr(std::string())
 , colors(this) {}

Colors::Colors(const Colors &c) noexcept
 : color(c.color)
 , backgroundColor(c.backgroundColor)
 , isLocalized(c.isLocalized)
 , ColorReturnStr(c.ColorReturnStr)
 , BackgroundReturnStr(c.BackgroundReturnStr)
 , colors(c.colors) {

    if (hasColor(color) == false) color = ColorEnum::none;
    if (hasColor(backgroundColor) == false) backgroundColor = BackgroundColorEnum::none;
    if (isLocalized == false) isLocalized = false;
    if (ColorReturnStr.empty()) ColorReturnStr = std::string();
    if (BackgroundReturnStr.empty()) BackgroundReturnStr = std::string();
    if (colors == nullptr) colors = this;
}

Colors::Colors(const std::unique_ptr<Colors> &ptr) noexcept
 : color(ptr->color)
 , backgroundColor(ptr->backgroundColor)
 , isLocalized(ptr->isLocalized)
 , ColorReturnStr(ptr->ColorReturnStr)
 , BackgroundReturnStr(ptr->BackgroundReturnStr)
 , colors(ptr->colors) {

    if (ptr == nullptr || ClassEmpty()) {
        if (hasColor(color) == false) color = ColorEnum::none;
        if (hasColor(backgroundColor) == false) backgroundColor = BackgroundColorEnum::none;
        if (isLocalized == false) isLocalized = false;
        if (ColorReturnStr.empty()) ColorReturnStr = std::string();
        if (BackgroundReturnStr.empty()) BackgroundReturnStr = std::string();
        if (colors == nullptr) colors = this;
    }
}

Colors::Colors(const std::shared_ptr<Colors> &ptr) noexcept
 : color(ptr->color)
 , backgroundColor(ptr->backgroundColor)
 , isLocalized(ptr->isLocalized)
 , ColorReturnStr(ptr->ColorReturnStr)
 , BackgroundReturnStr(ptr->BackgroundReturnStr)
 , colors(ptr->colors) {

    if (ptr == nullptr || ClassEmpty()) {
        if (hasColor(color) == false) color = ColorEnum::none;
        if (hasColor(backgroundColor) == false) backgroundColor = BackgroundColorEnum::none;
        if (isLocalized == false) isLocalized = false;
        if (ColorReturnStr.empty()) ColorReturnStr = std::string();
        if (BackgroundReturnStr.empty()) BackgroundReturnStr = std::string();
        if (colors == nullptr) colors = this;
    }
}

const void Colors::SetClassColor(const ColorEnum &color) noexcept { this->color = color; }

const void Colors::SetClassColor(const std::string &Txt) {

    if (Txt.empty() || CheckColorExists(Txt) == false) {

        std::cout << termcolor::red;
        StaticError::TryCatch("Color does not exist.");
        std::cout << termcolor::reset;
        ColorReturnStr = "none";
        return;
    }
    ColorReturnStr = Txt;
}

const std::string &Colors::SetClassBackgroundColor(
  const BackgroundColorEnum &BackgroundColor) {
    backgroundColor = BackgroundColor;
    return EnumToStr(BackgroundColor);
}

const std::string &Colors::SetClassBackgroundColor(const std::string &BackgroundColor) {

    if (BackgroundColor.empty() || CheckBackgroundExists(BackgroundColor) == false) {

        std::cout << termcolor::red;
        StaticError::TryCatch("Background Color does not exist.");
        std::cout << termcolor::reset;
        const static std::string &none = "none";
        BackgroundReturnStr            = none;
        return none;
    }
    return BackgroundReturnStr = BackgroundColor;
}

const void Colors::SetLocale(const bool &locale) noexcept {

    if (locale == false || isLocalized == true) return;

    if (locale == true) {
        setUTF8();
        isLocalized = true;
        return;
    }
}

const ColorEnum &Colors::GetColorEnum() const noexcept { return color; }

const BackgroundColorEnum &Colors::GetBackgroundColorEnum() const noexcept {
    return this->backgroundColor;
}

const bool &Colors::GetLocale() const { return this->isLocalized; }

const std::string &Colors::GetColorStr(const Colors &c) {

    if (ClassEmpty(c) == true) {

        const static std::string &err  = "Error: Class passed is empty. " + std::to_string(__LINE__) + __func__;
        const static std::string &none = "none";
        StaticError::TryCatch(err);
        return none;
    }
    return c.ColorReturnStr;
}

const std::string &Colors::GetColorStr() const noexcept { return this->ColorReturnStr; }

const std::string &Colors::GetBackgroundColorStr(const Colors &c) {

    if (ClassEmpty(c) == true) {

        StaticError::TryCatch("Class passed is empty\n");
        const static std::string &none = "none";
        return none;
    }
    return c.ColorReturnStr;
}

const std::string &Colors::GetBackgroundColorStr() const noexcept {
    return this->BackgroundReturnStr;
}

const bool Colors::hasColor(const ColorEnum &color) noexcept {

    if (color == ColorEnum::reset || color == ColorEnum::none) return false;
    return true;
}

const bool Colors::hasColor(const BackgroundColorEnum &color) noexcept {
    if (color == BackgroundColorEnum::reset || color == BackgroundColorEnum::none) return false;
    return true;
}

const bool Colors::hasColor() noexcept {

    if (this->color == ColorEnum::reset || this->color == ColorEnum::none) return false;
    return true;
}

const bool Colors::hasBackgroundColor() {

    const bool hasBackgroundColor {(this->backgroundColor == BackgroundColorEnum::reset
                                    || this->backgroundColor == BackgroundColorEnum::none)};

    if (hasBackgroundColor == false) return false;
    if (hasBackgroundColor == true) return true;

    std::string err = "Error: " + std::to_string(__LINE__) + __func__;

    return StaticError::ExitBool(err);
}

const std::string &Colors::EnumToStr(const ColorEnum &color) {

    static std::ostringstream  ss;
    const static std::ostream &Return = ostreamChangeColor(color);
    ss << Return.rdbuf();
    const static std::string &result = ss.str();
    return result;
}

const std::string &Colors::EnumToStr(const BackgroundColorEnum &color) {

    static std::stringstream ss;

    ss << ostreamBackgroundChangeColor(color).rdbuf();
    const static std::string result = ss.str();
    return result;
}

const std::string &Colors::EnumToStrConst(const ColorEnum &color) {
    static std::stringstream ss;

    ss << ostreamChangeColor(color).rdbuf();
    const static std::string &result = ss.str();
    return result;
}

const std::string &Colors::EnumToStrConst(const BackgroundColorEnum &BackgroundColor) {
    static std::stringstream ss;

    ss << ostreamBackgroundChangeColor(BackgroundColor).rdbuf();
    const static std::string &result = ss.str();
    return result;
}

const std::string &Colors::EnumToTxt(const ColorEnum &color) {
    const static std::string &colorTxt = EnumToStr(color);
    return colorTxt;
}

const std::string &Colors::EnumToTxt(const BackgroundColorEnum &BackgroundColor) {
    const static std::string &BackgroundColorTxt = EnumToStr(BackgroundColor);
    return BackgroundColorTxt;
}

const bool Colors::ClassEmpty() noexcept {

    const bool emptyClass {hasColor() == false && hasBackgroundColor() == false
                           && isLocalized == false && ColorReturnStr.empty()
                           && BackgroundReturnStr.empty()};

    return emptyClass;
}

const bool Colors::ClassEmpty(const Colors &c) noexcept {
    const bool emptyClass {
      (c.color == ColorEnum::none || c.backgroundColor == BackgroundColorEnum::none)
      && c.isLocalized == false && c.ColorReturnStr.empty() && c.BackgroundReturnStr.empty()};

    return emptyClass;
}

const std::string &Colors::ResetColor() {
    SetClassColor(ColorEnum::reset);
    return EnumToStr(ColorEnum::reset);
}

const std::string &Colors::ResetBackgroundColor() noexcept {
    return SetClassBackgroundColor(BackgroundColorEnum::reset);
}

const std::ostream &Colors::PrintColor(const std::string &msg, const ColorEnum &color) {
    return std::cout << Colors::UseColor(color) << msg << Colors::UseColor(ColorEnum::reset);
}

const std::string &Colors::UseColor(const ColorEnum &color)  {

    const static std::string &Color = EnumToStr(color);
    return Color;
}

const std::string &Colors::UseColor(const BackgroundColorEnum &color)  {

    return UseBackgroundColor(color);
}

const std::string &Colors::UseBackgroundColor(const BackgroundColorEnum &color)  {

    const static std::string &BgColor = EnumToStr(color);
    return BgColor;
}

Colors Colors::GetColors() noexcept { return *this; }

Colors *Colors::ColorsPtr() noexcept {
    static Colors a = GetColors();
    return &a;
}

Colors *Colors::StaticColorsPtr() noexcept {
    static Colors a;
    return &a;
}

const Colors *Colors::constColorsPtr() noexcept {
    const static Colors a;
    return &a;
}

const bool Colors::CheckColorExists(const std::string &Color) {

    if (Color.empty()) return false;

    const bool ColorExists {
      (Color == "grey") || (Color == "red") || (Color == "green") || (Color == "yellow")
      || (Color == "blue") || (Color == "magenta") || (Color == "cyan") || (Color == "white")
      || (Color == "bright_grey") || (Color == "bright_red") || (Color == "bright_green")
      || (Color == "bright_yellow") || (Color == "bright_blue") || (Color == "bright_magenta")
      || (Color == "bright_cyan") || (Color == "bright_white")};

    if (ColorExists == true) return true;
    if (ColorExists == false) return false;

    return StaticError::ExitBool("Error:" + std::to_string(__LINE__) + __func__);
}

const bool Colors::CheckBackgroundExists(const std::string &BackgroundColor) {

    if (BackgroundColor.empty()) return false;

    const bool BackgroundExists {
      (BackgroundColor == "on_grey") || (BackgroundColor == "on_red")
      || (BackgroundColor == "on_green") || (BackgroundColor == "on_yellow")
      || (BackgroundColor == "on_blue") || (BackgroundColor == "on_magenta")
      || (BackgroundColor == "on_cyan") || (BackgroundColor == "on_white")
      || (BackgroundColor == "on_bright_grey") || (BackgroundColor == "on_bright_red")
      || (BackgroundColor == "on_bright_green") || (BackgroundColor == "on_bright_yellow")
      || (BackgroundColor == "ton_bright_blue") || (BackgroundColor == "on_bright_magenta")
      || (BackgroundColor == "on_bright_cyan") || (BackgroundColor == "on_bright_white")};

    if (BackgroundExists == true) return true;
    if (BackgroundExists == false) return false;

    return StaticError::ExitBool("Error:" + std::to_string(__LINE__) + __func__ + '\n');
}

const std::ostream &Colors::ostreamChangeColor(const ColorEnum &color) {

    switch (color) {

        case ColorEnum::none  : [[fallthrough]];

        case ColorEnum::reset : {

            const static std::ostream &reset {std::cout << "" << termcolor::reset};
            return reset;
        }

        case ColorEnum::grey : {
            const static std::ostream &grey {std::cout << "" << termcolor::grey};
            return grey;
        }

        case ColorEnum::red : {
            const static std::ostream &red {std::cout << "" << termcolor::red};
            return red;
        }

        case ColorEnum::green : {
            const static std::ostream &green {std::cout << "" << termcolor::green};
            return green;
        }

        case ColorEnum::yellow : {
            const static std::ostream &yellow {std::cout << "" << termcolor::yellow};
            return yellow;
        }

        case ColorEnum::blue : {
            const static std::ostream &blue {std::cout << "" << termcolor::blue};
            return blue;
        }

        case ColorEnum::magenta : {
            const static std::ostream &magenta {std::cout << "" << termcolor::magenta};
            return magenta;
        }

        case ColorEnum::cyan : {
            const static std::ostream &cyan {std::cout << "" << termcolor::cyan};
            return cyan;
        }

        case ColorEnum::white : {
            const static std::ostream &white {std::cout << "" << termcolor::white};
            return white;
        }

        case ColorEnum::bright_grey : {
            const static std::ostream &bright_grey {std::cout << "" << termcolor::bright_grey};
            return bright_grey;
        }

        case ColorEnum::bright_red : {
            const static std::ostream &bright_red {std::cout << "" << termcolor::bright_red};
            return bright_red;
        }

        case ColorEnum::bright_green : {
            const static std::ostream &bright_green {std::cout << "" << termcolor::bright_green};
            return bright_green;
        }

        case ColorEnum::bright_yellow : {
            const static std::ostream &bright_yellow {std::cout << "" << termcolor::bright_yellow};
            return bright_yellow;
        }

        case ColorEnum::bright_blue : {
            //const static std::ostream &bright_blue {};
            return std::cout << "" << termcolor::bright_blue;
        }

        case ColorEnum::bright_magenta : {
            const static std::ostream &bright_magenta {
              std::cout << "" << termcolor::bright_magenta};
            return bright_magenta;
        }

        case ColorEnum::bright_cyan : {
            const static std::ostream &bright_cyan {std::cout << "" << termcolor::bright_cyan};
            return bright_cyan;
        }

        case ColorEnum::bright_white : {
            const static std::ostream &bright_white {std::cout << "" << termcolor::bright_white};
            return bright_white;
        }

        default : {

            StaticError::TryCatch("Invalid ColorEnum");
            const static std::ostream &err {ostreamChangeColor(ColorEnum::reset)};
            return err;
        };
    }
}

const std::ostream &Colors::ostreamBackgroundChangeColor(const BackgroundColorEnum &color) {

    switch (color) {

        case BackgroundColorEnum::reset : [[fallthrough]];
        case BackgroundColorEnum::none  : {
            const static std::ostream &none {std::cout << termcolor::reset};
            return none;
        }
        case BackgroundColorEnum::on_grey : {
            const static std::ostream &on_grey {std::cout << termcolor::on_grey};
            return on_grey;
        }
        case BackgroundColorEnum::on_red : {
            const static std::ostream &on_red {std::cout << termcolor::on_red};
            return on_red;
        }
        case BackgroundColorEnum::on_green : {
            const static std::ostream &on_green {std::cout << termcolor::on_green};
            return on_green;
        }
        case BackgroundColorEnum::on_yellow : {
            const static std::ostream &on_yellow {std::cout << termcolor::on_yellow};
            return on_yellow;
        }
        case BackgroundColorEnum::on_blue : {
            const static std::ostream &on_blue {std::cout << termcolor::on_blue};
            return on_blue;
        }
        case BackgroundColorEnum::on_magenta : {
            const static std::ostream &on_magenta {std::cout << termcolor::on_magenta};
            return on_magenta;
        }
        case BackgroundColorEnum::on_cyan : {
            const static std::ostream &on_cyan {std::cout << termcolor::on_cyan};
            return on_cyan;
        }
        case BackgroundColorEnum::on_white : {
            const static std::ostream &on_white {std::cout << termcolor::on_white};
            return on_white;
        }

        case BackgroundColorEnum::on_bright_grey : {
            const static std::ostream &on_bright_grey {std::cout << termcolor::on_bright_grey};
            return on_bright_grey;
        }

        case BackgroundColorEnum::on_bright_red : {
            const static std::ostream &on_bright_red {std::cout << termcolor::on_bright_red};
            return on_bright_red;
        }

        case BackgroundColorEnum::on_bright_green : {
            const static std::ostream &on_bright_green {std::cout << termcolor::on_bright_green};
            return on_bright_green;
        }

        case BackgroundColorEnum::on_bright_yellow : {
            const static std::ostream &on_bright_yellow {std::cout << termcolor::on_bright_yellow};
            return on_bright_yellow;
        }

        case BackgroundColorEnum::on_bright_blue : {
            const static std::ostream &on_bright_blue {std::cout << termcolor::on_bright_blue};
            return on_bright_blue;
        }

        case BackgroundColorEnum::on_bright_magenta : {
            const static std::ostream &on_bright_magenta {
              std::cout << termcolor::on_bright_magenta};
            return on_bright_magenta;
        }

        case BackgroundColorEnum::on_bright_cyan : {
            const static std::ostream &on_bright_cyan {std::cout << termcolor::on_bright_cyan};
            return on_bright_cyan;
        }

        case BackgroundColorEnum::on_bright_white : {
            const static std::ostream &on_bright_white {std::cout << termcolor::on_bright_white};
            return on_bright_white;
        }

        default : {

            const static std::ostream &err = ostreamChangeColor(ColorEnum::reset);
            StaticError::TryCatch("Invalid BackgroundColorEnum\n");
            return err;
        };
    }
}

const std::string &Colors::stringChangeColor(const ColorEnum &color) {

    switch (color) {

        case ColorEnum::none : {
            const static std::string &none {"none"};
            return none;
        }

        case ColorEnum::reset : {
            const static std::string &reset {"reset"};
            return reset;
        }
        case ColorEnum::grey : {
            const static std::string &grey {"grey"};
            return grey;
        }
        case ColorEnum::red : {
            const static std::string &red {"red"};
            return red;
        }
        case ColorEnum::green : {
            const static std::string &green {"green"};
            return green;
        }
        case ColorEnum::yellow : {
            const static std::string &yellow {"yellow"};
            return yellow;
        }
        case ColorEnum::blue : {
            const static std::string &blue {"blue"};
            return blue;
        }
        case ColorEnum::magenta : {
            const static std::string &magenta {"magenta"};
            return magenta;
        }
        case ColorEnum::cyan : {
            const static std::string &cyan {"cyan"};
            return cyan;
        }
        case ColorEnum::white : {
            const static std::string &white {"white"};
            return white;
        }
        case ColorEnum::bright_grey : {
            const static std::string &bright_grey {"bright_grey"};
            return bright_grey;
        }
        case ColorEnum::bright_red : {
            const static std::string &bright_red {"bright_red"};
            return bright_red;
        }
        case ColorEnum::bright_green : {
            const static std::string &bright_green {"bright_green"};
            return bright_green;
        }
        case ColorEnum::bright_yellow : {
            const static std::string &bright_yellow {"bright_yellow"};
            return bright_yellow;
        }
        case ColorEnum::bright_blue : {
            const static std::string &bright_blue {"bright_blue"};
            return bright_blue;
        }
        case ColorEnum::bright_magenta : {
            const static std::string &bright_magenta {"bright_magenta"};
            return bright_magenta;
        }
        case ColorEnum::bright_cyan : {
            const static std::string &bright_cyan {"bright_cyan"};
            return bright_cyan;
        }
        case ColorEnum::bright_white : {
            const static std::string &bright_white {"bright_white"};
            return bright_white;
        }

        default : {

            const static std::string &err = stringChangeColor(ColorEnum::reset);
            StaticError::TryCatch("Invalid BackgroundColorEnum\n");
            return err;
        };
    }
}

const std::string &Colors::stringBackgroundChangeColor(const BackgroundColorEnum &color) {

    switch (color) {

        case BackgroundColorEnum::reset : [[fallthrough]];

        case BackgroundColorEnum::none  : {
            const static std::string &none {"none"};
            return none;
        }

        case BackgroundColorEnum::on_grey : {
            const static std::string &on_grey {"on_grey"};
            return on_grey;
        }

        case BackgroundColorEnum::on_red : {
            const static std::string &on_red {"on_red"};
            return on_red;
        }

        case BackgroundColorEnum::on_green : {
            const static std::string &on_green {"on_green"};
            return on_green;
        }

        case BackgroundColorEnum::on_yellow : {
            const static std::string &on_yellow {"on_yellow"};
            return on_yellow;
        }

        case BackgroundColorEnum::on_blue : {
            const static std::string &on_blue {"on_blue"};
            return on_blue;
        }

        case BackgroundColorEnum::on_magenta : {
            const static std::string &on_magenta {"on_magenta"};
            return on_magenta;
        }

        case BackgroundColorEnum::on_cyan : {
            const static std::string &on_cyan {"on_cyan"};
            return on_cyan;
        }

        case BackgroundColorEnum::on_white : {
            const static std::string &on_white {"on_white"};
            return on_white;
        }

        case BackgroundColorEnum::on_bright_grey : {
            const static std::string &on_bright_grey {"on_bright_grey"};
            return on_bright_grey;
        }

        case BackgroundColorEnum::on_bright_red : {
            const static std::string &on_bright_red {"on_bright_red"};
            return on_bright_red;
        }

        case BackgroundColorEnum::on_bright_green : {
            const static std::string &on_bright_green {"on_bright_green"};
            return on_bright_green;
        }

        case BackgroundColorEnum::on_bright_yellow : {
            const static std::string &on_bright_yellow {"on_bright_yellow"};
            return on_bright_yellow;
        }

        case BackgroundColorEnum::on_bright_blue : {
            const static std::string &on_bright_blue {"on_bright_blue"};
            return on_bright_blue;
        }

        case BackgroundColorEnum::on_bright_magenta : {
            const static std::string &on_bright_magenta {"on_bright_magenta"};
            return on_bright_magenta;
        }

        case BackgroundColorEnum::on_bright_cyan : {
            const static std::string &on_bright_cyan {"on_bright_cyan"};
            return on_bright_cyan;
        }

        case BackgroundColorEnum::on_bright_white : {
            const static std::string &on_bright_white {"on_bright_white"};
            return on_bright_white;
        }

        default : {
            stringBackgroundChangeColor(BackgroundColorEnum::reset);
            StaticError::TryCatch("Invalid BackgroundColorEnum\n");
            const static std::string &none = "none";
            return none;
        };
    }
}

Colors::~Colors() {

    color               = ColorEnum::none;
    backgroundColor     = BackgroundColorEnum::none;
    isLocalized         = {};
    ColorReturnStr      = {};
    BackgroundReturnStr = {};
}
Colors &Colors::operator=(const Colors &other) {

    if (this == &other) return *this;

    else {
        color               = other.color;
        backgroundColor     = other.backgroundColor;
        isLocalized         = other.isLocalized;
        ColorReturnStr      = other.ColorReturnStr;
        BackgroundReturnStr = other.BackgroundReturnStr;
        colors              = other.colors;
        return *this;
    }
}
Colors &Colors::operator=(const StaticColors &other) {

    if (this == &other) return *this;

    else {
        color               = other.color;
        backgroundColor     = other.backgroundColor;
        isLocalized         = other.isLocalized;
        ColorReturnStr      = other.ColorReturnStr;
        BackgroundReturnStr = other.BackgroundReturnStr;
        colors              = other.colors;
        return *this;
    }
};

StaticColors::StaticColors() noexcept
 : color(ColorEnum::none)
 , backgroundColor(BackgroundColorEnum::none)
 , isLocalized(false)
 , ColorReturnStr("none")
 , BackgroundReturnStr("none") {}

StaticColors::StaticColors(const StaticColors &c) noexcept : StaticColors() { Colors a(c); }

StaticColors::StaticColors(const std::unique_ptr<Colors> &ptr) noexcept : StaticColors() {
    Colors a(ptr);
}

StaticColors::StaticColors(const std::shared_ptr<Colors> &ptr) noexcept : StaticColors() {
    Colors a(ptr);
}

StaticColors::~StaticColors() {

    color               = ColorEnum::none;
    backgroundColor     = BackgroundColorEnum::none;
    isLocalized         = {};
    ColorReturnStr      = "";
    BackgroundReturnStr = "";
    colors              = {};
}

StaticColors &StaticColors::operator=(const StaticColors &other) {
    if (this == &other) return *this;

    else {
        color               = other.color;
        backgroundColor     = other.backgroundColor;
        isLocalized         = other.isLocalized;
        ColorReturnStr      = other.ColorReturnStr;
        BackgroundReturnStr = other.BackgroundReturnStr;
        colors              = other.colors;
        return *this;
    }
}

StaticColors &StaticColors::operator=(const Colors &other) {

    if (this == &other) return *this;
    else {
        color               = other.color;
        backgroundColor     = other.backgroundColor;
        isLocalized         = other.isLocalized;
        ColorReturnStr      = other.ColorReturnStr;
        BackgroundReturnStr = other.BackgroundReturnStr;
        return *this;
    }
}
