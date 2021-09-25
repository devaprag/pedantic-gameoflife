#pragma once

#include "Cell.h"
#include "Position.h"
#include "Judge.h"
#include "Sentencer.h"

#include <vector>
#include <array>
#include <algorithm>

// i own all the cells
// i count neighbours and prepare the cells
// then update() to make it real

template<Position::CoordinateElement BoardLength>
class Board
{
  template<Position::CoordinateElement BoardLength> friend class Printer;

  typedef int CellCount;
  typedef std::array<Cell, BoardLength> CellRow; // single row, count elements horizontally
  typedef std::array<CellRow, BoardLength> CellRows; // collection of rows, count rows vertically
  typedef CellRows CellBoard;
  typedef WrappedPosition<BoardLength> WrappedPosition;

public:
  void initialise(const std::vector<WrappedPosition>& iPositions) {
    for (const auto& p : iPositions) {
      Cell& aCell = _theBoard[p._x][p._y];
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
      Sentencer::sentence(Judge::verdict(countLivingNeighbours(neighbourPositions(aCellPosition))), cellAt(aCellPosition));
    }
  }

  // update board
  void update() {
    for (auto& aColRow : _theBoard) {
      update(aColRow);
    }
  }

  // update row of cells
  void update(CellRow& iCellRow) {
    for (auto& aCell : iCellRow) {
      aCell.update();
    }
  }

  Cell& cellAt(const Position& iPosition) {
    return _theBoard[iPosition._x][iPosition._y];
  }

  std::vector<WrappedPosition> neighbourPositions(WrappedPosition iPosition) {
    return { iPosition.left(),
             iPosition.right(),
             iPosition.up(),
             iPosition.down(),
             iPosition.up().left(),
             iPosition.up().right(),
             iPosition.down().left(),
             iPosition.down().right() };
  }
  
  CellCount countLivingNeighbours(const std::vector<WrappedPosition>& iNeighbourPositions) {
    return std::count_if(cbegin(iNeighbourPositions), cend(iNeighbourPositions), [&](const auto& aPosition) { return cellAt(aPosition).alive(); });
  }

private:
  // [row num] x [column num]
  CellBoard _theBoard;
};



  
  