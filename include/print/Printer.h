#pragma once


#include "Board.h"
#include "Cell.h"

#include <algorithm>
#include <iostream>

namespace printer {

  // i print boards for fun

  template<position::Position::CoordinateElement BoardLength>
  class Printer {
  public:
    static void print(const board::Board<BoardLength>& board);
  };

  template<position::Position::CoordinateElement BoardLength>
  void printer::Printer<BoardLength>::print(const board::Board<BoardLength>& board) {
    for (auto& colrow : board._theBoard) {
      for (auto& cell : colrow) {
        static CellPrinter aCellPrinter;
        std::cout << cell.print(aCellPrinter) << " ";
      }
      std::cout << std::endl;
    }
  }

}