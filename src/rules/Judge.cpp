#include "Judge.h"

Judgement Judge::verdict(const NeighbourCount iNeighbourCount) {
  if (shouldDie(iNeighbourCount)) {
    return Judgement::eDie;
  }

  if (shouldBirth(iNeighbourCount)) {
    return Judgement::eBeBorn;
  }

  return Judgement::eStayTheSame;
}


 bool Judge::shouldDie(const NeighbourCount iNeighbourCount) {
  return (iNeighbourCount <= kTooFew) || (iNeighbourCount >= kTooMany);
}

 bool Judge::shouldBirth(const NeighbourCount iNeighbourCount) {
  return (iNeighbourCount == kGoodForBirth);
}