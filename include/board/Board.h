#pragma once

// board
#include "Cell.h"
#include "Position.h"
#include "Neighbours.h"

// rules
#include "Judge.h"
#include "Sentencer.h"

#include <vector>
#include <array>
#include <algorithm>

namespace print {
  template<board::Position::CoordinateElement BoardLength> class Printer;
}

namespace board {
  using board::Position;  

  // i own all the cells
  // i count neighbours and prepare the cells
  // then update() to make it real

  template<Position::CoordinateElement BoardLength>
  class Board
  {
    template<board::Position::CoordinateElement BoardLength> friend class print::Printer;

    typedef int CellCount;
    typedef std::array<board::Cell, BoardLength> CellRow; // single row, count elements horizontally
    typedef std::array<CellRow, BoardLength> CellRows; // collection of rows, count rows vertically
    typedef CellRows CellBoard;
    typedef board::WrappedPosition<BoardLength> WrappedPosition;
    typedef board::Neighbours<BoardLength> Neighbours;

  public:
    void setup(const std::vector<WrappedPosition>& iPositions) {
      for (const auto& p : iPositions) {
        board::Cell& aCell = _theBoard[p._x][p._y];
        aCell.stageBirth();
      }
      update();
    }

    void runLifeCycle() {
      for (Position::CoordinateElement aPosY = 0; aPosY < BoardLength; ++aPosY) {
        runLifeCycleRow(aPosY);
      }
      update();
    }

  private:

    void runLifeCycleRow(const Position::CoordinateElement& iPosY) {
      for (Position::CoordinateElement aPosX = 0; aPosX < BoardLength; ++aPosX) {
        const WrappedPosition aCellPosition(aPosX, iPosY);
        rules::Sentencer::sentence(rules::Judge::verdict(countLivingNeighbours(Neighbours::neighbourPositions(aCellPosition))), cellAt(aCellPosition));
      }
    }

    // update board
    void update() {
      std::for_each(begin(_theBoard), end(_theBoard), [this](auto& aColRow){update(aColRow);});
    }

    // update row of cells
    static void update(CellRow& iCellRow) {
      std::for_each(begin(iCellRow), end(iCellRow), [](auto& aCell){aCell.update();});
    }

    board::Cell& cellAt(const Position& iPosition) {
      return _theBoard[iPosition._x][iPosition._y];
    }


    CellCount countLivingNeighbours(const std::vector<WrappedPosition>& iNeighbourPositions) {
      return std::count_if(cbegin(iNeighbourPositions), cend(iNeighbourPositions), [this](const auto& aPosition) { return cellAt(aPosition).alive(); });
    }

  private:
    // [row num] x [column num]
    CellBoard _theBoard;
  };

}
  