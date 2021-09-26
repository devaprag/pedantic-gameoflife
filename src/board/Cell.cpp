#include "Cell.h"

namespace board {

  // move to next state
  void Cell::update() {
    _currentState = _nextState;
    _nextState = CellState::eUnknown;
  }

  // next state
  void Cell::stageBirth() {
    _nextState = CellState::eAlive;
  }

  void Cell::stageDeath() {
    _nextState = CellState::eDead;
  }

  void Cell::stageSame() {
    _nextState = _currentState;
  }

  // current state
  const bool Cell::alive() const {
    return _currentState == CellState::eAlive;
  }

  const bool Cell::dead() const {
    return _currentState == CellState::eDead;
  }

  // printer helper
  print::CellPrinter::PrintSymbol Cell::print(const print::CellPrinter& iPrinter) const {
    return iPrinter.symbol(_currentState);
  }

}
