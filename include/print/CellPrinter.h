#pragma once

#include "CellState.h"
#include <map>

namespace printer {
  using cell::CellState;

  struct CellPrinter {
    typedef char PrintSymbol;

    CellPrinter();
    PrintSymbol symbol(const CellState& iCellState) const;

  private:
    std::map<CellState, PrintSymbol> _cellPrintStore;
  };

}