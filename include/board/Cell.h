#pragma once

#include "CellState.h"
#include "CellPrinter.h"

namespace cell {
  // hello I am a cell
  // I am alive or dead
  // 
  // What is a board? I do not know 
  // (ie I don't know neighbours or position)
  // I don't even know how to print myself.
  // 
  // i can be prepared for birth or death
  // and will update to that state

  class Cell {

  public:
    Cell()
      : _currentState(CellState::eDead)
      , _nextState(CellState::eDead) {}

    // move to next state
    void update();

    // next state
    void stageBirth();
    void stageDeath();
    void stageSame();

    // current state
    const bool alive() const;
    const bool dead() const;

    // printer helper
    printer::CellPrinter::PrintSymbol print(const printer::CellPrinter& iPrinter) const;

  private:
    CellState _currentState;
    CellState _nextState;
  };

}
