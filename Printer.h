#pragma once

#include "Board.h"
#include "Cell.h"

#include <algorithm>
#include <iostream>

// i print boards for fun

template<Position::CoordinateElement BoardLength>
class Printer {
public:
  static void print(const Board<BoardLength>& board);
};

template<Position::CoordinateElement BoardLength>
void Printer<BoardLength>::print(const Board<BoardLength>& board) {
  for (auto& colrow : board._theBoard) {
    for (auto& cell : colrow) {
      static CellPrinter aCellPrinter;
      std::cout << cell.print(aCellPrinter) << " ";
    }
    std::cout << std::endl;
  }
}

