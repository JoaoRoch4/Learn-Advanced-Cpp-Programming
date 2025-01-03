﻿#include "MyTypes.hpp"

// clang-format off

void headerShow() noexcept {

    const char *Msg {

      "——————————————————————————————————————————————————————————————————————————————————————————"
      "——————————————————————————|\n|"
      "\t\t\t\t"
      "Made by: —— João André Rocha de Almeida —— "
      "\t\t\t\t\t    "
      "|\n| "
      "\t\t\t\t"
      "Now:"
      "\t    " __DATE__ "  --  " __TIME__ "Hs"
      "\t\t\t\t\t\t    "
      "|\n|\t\t\t\t"
      "———————————————————————————————————————"
      "\t\t\t\t\t            "
      "|\n|\t"
      "File path: "
      "\t\t\t\t\t\t\t\t\t\t\t\t    "
      "|\n|" __FILE__ "    |"
      "\n|—————————————————————————————————————————————————————————————————————————————————"
      "——————————————————————————————————|\n\n"
    };
    std::cout << Msg;
}

void headerShow(const bool &show) noexcept {

    if (!show) return;

    const char *Msg {

      "——————————————————————————————————————————————————————————————————————————————————————————"
      "——————————————————————————|\n|"
      "\t\t\t\t"
      "Made by: —— João André Rocha de Almeida —— "
      "\t\t\t\t\t    "
      "|\n| "
      "\t\t\t\t"
      "Now:"
      "\t    " __DATE__ "  --  " __TIME__ "Hs"
      "\t\t\t\t\t\t    "
      "|\n|\t\t\t\t"
      "———————————————————————————————————————"
      "\t\t\t\t\t            "
      "|\n|\t"
      "File path: "
      "\t\t\t\t\t\t\t\t\t\t\t\t    "
      "|\n|" __FILE__ "    |"
      "\n|—————————————————————————————————————————————————————————————————————————————————"
      "——————————————————————————————————|\n\n"};

    std::cout << Msg;
}

// clang-format on

