#include "CellPrinter.h"

namespace print {

  CellPrinter::CellPrinter() {
    _cellPrintStore[CellState::eAlive] = 'O';
    _cellPrintStore[CellState::eDead] = '.';
    _cellPrintStore[CellState::eUnknown] = '?';
  }

  CellPrinter::PrintSymbol CellPrinter::symbol(const CellState& iCellState) const {
    return _cellPrintStore.at(iCellState);
  }

}