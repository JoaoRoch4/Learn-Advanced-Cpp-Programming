#include "MyTypes.hpp"

// clang-format off



void headerShow() noexcept {

    const char *Msg {

      "覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧"
      "覧覧覧覧覧覧覧覧覧覧覧覧覧|\n|"
      "\t\t\t\t"
      "Made by: 覧 Jo縊 Andr� Rocha de Almeida 覧 "
      "\t\t\t\t\t    "
      "|\n| "
      "\t\t\t\t"
      "Now:"
      "\t    " __DATE__ "  --  " __TIME__ "Hs"
      "\t\t\t\t\t\t    "
      "|\n|\t\t\t\t"
      "覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧�"
      "\t\t\t\t\t            "
      "|\n|\t"
      "File path: "
      "\t\t\t\t\t\t\t\t\t\t\t\t    "
      "|\n|" __FILE__ "    |"
      "\n|覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧�"
      "覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧|\n\n"
    };
    out << Msg;
}

void headerShow(const bool &show) noexcept {

    if (!show) return;

    const char *Msg {

      "覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧"
      "覧覧覧覧覧覧覧覧覧覧覧覧覧|\n|"
      "\t\t\t\t"
      "Made by: 覧 Jo縊 Andr� Rocha de Almeida 覧 "
      "\t\t\t\t\t    "
      "|\n| "
      "\t\t\t\t"
      "Now:"
      "\t    " __DATE__ "  --  " __TIME__ "Hs"
      "\t\t\t\t\t\t    "
      "|\n|\t\t\t\t"
      "覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧�"
      "\t\t\t\t\t            "
      "|\n|\t"
      "File path: "
      "\t\t\t\t\t\t\t\t\t\t\t\t    "
      "|\n|" __FILE__ "    |"
      "\n|覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧�"
      "覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧|\n\n"};

    out << Msg;
}

// clang-format on


