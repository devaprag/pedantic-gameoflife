#pragma once

#include "CellState.h"
#include <map>

struct CellPrinter {
  typedef char PrintSymbol;

  CellPrinter();
  PrintSymbol symbol(const CellState& iCellState) const;

private:
  std::map<CellState, PrintSymbol> _cellPrintStore;
};
