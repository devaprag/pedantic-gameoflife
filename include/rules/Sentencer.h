#pragma once

#include "Judge.h"

#include <map>

// interpret and apply judgement
class Cell;
class Sentencer {
public:
  static void sentence(const Judgement& aJudgement, Cell& aCell);

private:
  static const bool stay(const Judgement& aJudgement);
  static const bool shouldDie(const Judgement& aJudgement);
  static const bool shouldBeBorn(const Judgement& aJudgement);
};
