#pragma once


#include "Board.h"
#include "Cell.h"

#include <algorithm>
#include <iostream>

namespace print {

  // i print boards for fun

  template<board::Position::CoordinateElement BoardLength>
  class Printer {
  public:
    static void print(const board::Board<BoardLength>& board);
  };

  template<board::Position::CoordinateElement BoardLength>
  void print::Printer<BoardLength>::print(const board::Board<BoardLength>& board) {
    for (auto& colrow : board._theBoard) {
      for (auto& cell : colrow) {
        static CellPrinter aCellPrinter;
        std::cout << cell.print(aCellPrinter) << " ";
      }
      std::cout << std::endl;
    }
  }

  static void clearScreen() {
    std::cout << "\033[2J\033[1;1H";
  }
}