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

    // one step (of lifecycle) board
    void step() {
      for (Position::CoordinateElement aPosY = 0; aPosY < BoardLength; ++aPosY) {
        step(aPosY);
      }
      update();
    }

  private:
    // one step (of lifecycle) row
    void step(const Position::CoordinateElement& iPosY) {
      for (Position::CoordinateElement aPosX = 0; aPosX < BoardLength; ++aPosX) {
        step(WrappedPosition(aPosX, iPosY));
      }
    }

    // one step (of lifecycle) cell
    void step(const WrappedPosition& iCellPosition) {
      const CellCount aNeighbourCount(countLivingNeighbours(Neighbours::neighbourPositions(iCellPosition)));
      rules::Sentencer::sentence(rules::Judge::verdict(aNeighbourCount), cellAt(iCellPosition));
    }    

    // update board
    void update() {
      std::for_each(begin(_theBoard), end(_theBoard), [this](auto& aColRow){update(aColRow);});
    }

    // update row of cells
    static void update(CellRow& iCellRow) {
      std::for_each(begin(iCellRow), end(iCellRow), [](auto& aCell){aCell.update();});
    }

    // cell accessor
    board::Cell& cellAt(const Position& iPosition) {
      return _theBoard[iPosition._x][iPosition._y];
    }

    // neighbour count
    CellCount countLivingNeighbours(const std::vector<WrappedPosition>& iNeighbourPositions) {
      return std::count_if(cbegin(iNeighbourPositions), cend(iNeighbourPositions), [this](const auto& aPosition) { 
        return cellAt(aPosition).alive(); 
      });
    }

  private:
    // [row num] x [column num]
    CellBoard _theBoard;
  };

}
  