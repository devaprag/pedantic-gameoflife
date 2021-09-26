#pragma once

#include "CellState.h"
#include <map>

namespace print {
  using board::CellState;

  struct CellPrinter {
    typedef char PrintSymbol;

    CellPrinter();
    PrintSymbol symbol(const CellState& iCellState) const;

  private:
    std::map<CellState, PrintSymbol> _cellPrintStore;
  };

}