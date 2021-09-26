#pragma once

// I decide if cells live or die!

enum struct Judgement {
  eBeBorn,
  eDie,
  eStayTheSame
};

namespace {
  typedef int NeighbourCount;  
  constexpr NeighbourCount kTooFew = 1;
  constexpr NeighbourCount kGoodForBirth = 3;
  constexpr NeighbourCount kTooMany = 4;
}

class Judge {
public:
  static Judgement verdict(const NeighbourCount iNeighbourCount);

private:
  static bool shouldDie(const NeighbourCount iNeighbourCount);
  static bool shouldBirth(const NeighbourCount iNeighbourCount);
};
