#pragma once

#include "Position.h"
#include <vector>

namespace board {

  template<Position::CoordinateElement BoardLength>
  class Neighbours {
    typedef board::WrappedPosition<BoardLength> WrappedPosition;
public:
    static std::vector<WrappedPosition> neighbourPositions(WrappedPosition iPosition) {
      return { iPosition.left(),
               iPosition.right(),
               iPosition.up(),
               iPosition.down(),
               iPosition.up().left(),
               iPosition.up().right(),
               iPosition.down().left(),
               iPosition.down().right() };
    }
 };

}
