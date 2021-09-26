#pragma once

#include "Judge.h"

#include <map>

namespace cell {
  class Cell;
}

namespace rules {

  // interpret and apply judgement

  class Sentencer {
  public:
    static void sentence(const Judgement& aJudgement, cell::Cell& aCell);

  private:
    static const bool stay(const Judgement& aJudgement);
    static const bool shouldDie(const Judgement& aJudgement);
    static const bool shouldBeBorn(const Judgement& aJudgement);
  };

}