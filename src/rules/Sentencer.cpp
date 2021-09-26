#include "Sentencer.h"

#include "Cell.h"

namespace rules {

  void Sentencer::sentence(const Judgement& aJudgement, board::Cell& aCell) {
    if (stay(aJudgement)) {
      aCell.stageSame();
    }

    if (shouldBeBorn(aJudgement)) {
      aCell.stageBirth();
    }

    if (shouldDie(aJudgement)) {
      aCell.stageDeath();
    }
  }

  const bool Sentencer::stay(const Judgement& aJudgement) {
    return aJudgement == Judgement::eStayTheSame;
  }

  const bool Sentencer::shouldDie(const Judgement& aJudgement) {
    return aJudgement == Judgement::eDie;
  }

  const bool Sentencer::shouldBeBorn(const Judgement& aJudgement) {
    return aJudgement == Judgement::eBeBorn;
  }

}
