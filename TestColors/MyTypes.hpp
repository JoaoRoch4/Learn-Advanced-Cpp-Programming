#pragma once

class MyTypes {

public:
    MyTypes() = default;

    virtual ~MyTypes() = default;
};

#define SET_UTF8

#include "Colors.hpp"
#include "Error.hpp"

#include <iostream>
#include <string>
#include <locale>

#ifdef _WINDOWS_
#include <windows.h>
#define NOMINOMAX
#endif // !_WINDOWS_

#ifdef _VECTOR_
// Type definitions
#define vec     std ::vector<int>
#define vecStr  std::vector<std::string>
#define vecWstr std ::vector<std::wstring>
#define str     std::string
#define wstr    std::wstring
#endif // !_VECTOR_

#ifndef _MEMORY_
#define out  std::cout
#define wout std::wcout
#define in   std::cin
#define win  std::wcin
#endif

// UTF-8 setting macro
#if defined(SET_UTF8) && !defined(_WINDOWS_)

#define setUTF8() setlocale(0, "")

#elif defined(SET_UTF8) && defined(_WINDOWS_)

#define setUTF8()                                                                                  \
    setlocale(LC_ALL, "");                                                                         \
    SetConsoleOutputCP(CP_UTF8)

#endif

// Function declarations
void headerShow() noexcept;
void headerShow(const bool &show) noexcept;


