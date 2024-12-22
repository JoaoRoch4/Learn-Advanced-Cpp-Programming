#pragma once

import std.compat;

#ifdef _WIN32
#define NOMINMAX
#include <Windows.h>
#define setUTF8()                                                                                  \
    setlocale(0, "");                                                                              \
    SetConsoleOutputCP(CP_UTF8);
#else
#define setUTF8() setlocale(LC_ALL, "en_US.UTF-8");
#endif // __WIN32

#define out  std::cout
#define wout std::wcout
#define in   std::cin
#define win  std::wcin


typedef std::string               str;
typedef std::wstring              wstr;
typedef std::vector<int>          vec;
typedef std::vector<std::string>  vecStr;
typedef std::vector<std::wstring> vecWstr;

void headerShow() noexcept;
void headerShow(const bool &show) noexcept;
