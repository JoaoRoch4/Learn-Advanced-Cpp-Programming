#pragma once

#include "MyTypes.hpp"

#include <iostream>
#include <string>
#include <memory>

enum class ColorEnum {

    none,
    reset,
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

enum class BackgroundColorEnum {

    none,
    reset,
    on_grey,
    on_red,
    on_green,
    on_yellow,
    on_blue,
    on_magenta,
    on_cyan,
    on_white,
    on_bright_grey,
    on_bright_red,
    on_bright_green,
    on_bright_yellow,
    on_bright_blue,
    on_bright_magenta,
    on_bright_cyan,
    on_bright_white
};

class Colors;
class StaticColors;

class Colors : public virtual MyTypes {

    friend class StaticColors;

public:
    // Default constructor
    Colors() noexcept;
    // copy constructor
    Colors(const Colors &c) noexcept;
    // copy constructor with unique_ptr
    Colors(const class std::unique_ptr<Colors> &ptr) noexcept;
    // copy constructor with shared_ptr
    Colors(const class std::shared_ptr<Colors> &ptr) noexcept;
    
protected:
    ColorEnum           color;
    BackgroundColorEnum backgroundColor;
    bool                isLocalized;
    std::string         ColorReturnStr;
    std::string         BackgroundReturnStr;
    Colors             *colors;

public:
    virtual const void         SetClassColor(const ColorEnum &color) noexcept;
    virtual const void         SetClassColor(const std::string &Txt);
    virtual const std::string &SetClassBackgroundColor(
      const BackgroundColorEnum &BackgroundColor);
    virtual const std::string &SetClassBackgroundColor(const std::string &BackgroundColor);
    virtual const void         SetLocale(const bool &locale) noexcept;

    virtual const ColorEnum           &GetColorEnum() const noexcept;
    virtual const BackgroundColorEnum &GetBackgroundColorEnum() const noexcept;
    virtual const bool                &GetLocale() const;
    virtual const std::string         &GetColorStr(const Colors &c);
    virtual const std::string         &GetColorStr() const noexcept;
    virtual const std::string         &GetBackgroundColorStr(const Colors &c);
    virtual const std::string         &GetBackgroundColorStr() const noexcept;

    virtual const bool CheckColorExists(const std::string &Color);
    virtual const bool CheckBackgroundExists(const std::string &BackgroundColor);

protected:
    const bool hasColor(const ColorEnum &color) noexcept;
    const bool hasColor(const BackgroundColorEnum &color) noexcept;
    const bool hasColor() noexcept;
    const bool hasBackgroundColor();

    const std::ostream &ostreamChangeColor(const ColorEnum &color);
    const std::ostream &ostreamBackgroundChangeColor(const BackgroundColorEnum &color);

    const std::string &stringChangeColor(const ColorEnum &color);
    const std::string &stringBackgroundChangeColor(const BackgroundColorEnum &color);

    const std::string &EnumToStr(const ColorEnum &color);
    const std::string &EnumToStr(const BackgroundColorEnum &color);
    const std::string &EnumToStrConst(const ColorEnum &color);
    const std::string &EnumToStrConst(const BackgroundColorEnum &BackgroundColor);

    const std::string &EnumToTxt(const ColorEnum &color);
    const std::string &EnumToTxt(const BackgroundColorEnum &BackgroundColor);

    const bool ClassEmpty() noexcept;
    const bool ClassEmpty(const Colors &c) noexcept;

public:
    virtual const std::string &ResetColor();
    virtual const std::string &ResetBackgroundColor() noexcept;

    virtual const std::ostream &PrintColor(
      const std::string &msg, const ColorEnum &color = ColorEnum::reset);

    virtual const std::string &UseColor(const ColorEnum &color);
    virtual const std::string &UseColor(const BackgroundColorEnum &color);
    virtual const std::string &UseBackgroundColor(const BackgroundColorEnum &color);

    virtual Colors       GetColors() noexcept;
    virtual Colors      *ColorsPtr() noexcept;
    static Colors       *StaticColorsPtr() noexcept;
    const static Colors *constColorsPtr() noexcept;

    ~Colors();

    bool    operator==(const Colors &other) const = default;
    Colors &operator=(const Colors &other);
    Colors &operator=(const StaticColors &other);
};

class StaticColors : private virtual Colors {

    friend class Colors;

    ColorEnum           color;
    BackgroundColorEnum backgroundColor;
    bool                isLocalized;
    std::string         ColorReturnStr;
    std::string         BackgroundReturnStr;

public:

    // Default constructor
    StaticColors() noexcept;
    // copy constructor
    StaticColors(const StaticColors &c) noexcept;
    // copy constructor with unique_ptr
    StaticColors(const std::unique_ptr<Colors> &ptr) noexcept;
    // copy constructor with shared_ptr
    StaticColors(const std::shared_ptr<Colors> &ptr) noexcept;
   
    __forceinline const static void SetClassColor(const ColorEnum &color) noexcept {
        return Colors().SetClassColor(color);
    }

    __forceinline const static void SetClassColor(const std::string &color) {
        return Colors().SetClassColor(color);
    }

    __forceinline const static std::string &SetClassBackgroundColor(
      const BackgroundColorEnum &BackgroundColor) noexcept {
        return Colors().SetClassBackgroundColor(BackgroundColor);
    }

    __forceinline const static std::string &SetClassBackgroundColor(
      const std::string &BackgroundColor) {
        return Colors().SetClassBackgroundColor(BackgroundColor);
    }

    __forceinline const static void SetLocale(const bool &locale) noexcept {
        return Colors().SetLocale(locale);
    }

    __forceinline const static std::string &EnumToStr(const ColorEnum &color) {
        return Colors().EnumToStr(color);
    }

    __forceinline const static std::string &ResetColors() { return Colors().ResetColor(); }

    __forceinline const static std::string &ResetBackgroundColor() noexcept {
        return Colors().ResetBackgroundColor();
    }

    const static std::ostream &PrintColor(
      const std::string &msg, const ColorEnum &color = ColorEnum::reset) {
        return Colors().PrintColor(msg, color);
    }

    __forceinline static Colors *staticColorsPtr() noexcept { return Colors().StaticColorsPtr(); }

    __forceinline const static std::string &GetColorStr(const Colors &colors) {
        return Colors().GetColorStr(colors);
    }

    __forceinline const static std::string &GetColorStr() noexcept {
        return Colors().GetColorStr();
    }
    __forceinline const static std::string &GetBackgroundColorStr(const Colors &c) {
        return Colors().GetBackgroundColorStr(c);
    }
    __forceinline const static std::string &GetBackgroundColorStr() noexcept {
        return Colors().GetBackgroundColorStr();
    };

    __forceinline const static std::string &UseColor(const ColorEnum &color) {
        return Colors().UseColor(color);
    }

    __forceinline const static std::string &UseColor(
      const BackgroundColorEnum &BackgroundColor) {
        return Colors().UseColor(BackgroundColor);
    }

    __forceinline const static std::string &UseBackgroundColor(
      const BackgroundColorEnum &BackgroundColor) {
        return Colors().UseBackgroundColor(BackgroundColor);
    }

    virtual ~StaticColors();

    bool          operator==(const StaticColors &other) const = default;
    StaticColors &operator=(const StaticColors &other);
    StaticColors &operator=(const Colors &other);
};
