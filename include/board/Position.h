#pragma once

namespace board {

  // 2-dimensional coordinates
  // not stored in board, used for temporary indexing really
  struct Position {
    typedef int CoordinateElement;

    Position(const CoordinateElement& x, const CoordinateElement& y)
      : _x(x), _y(y) {}

    CoordinateElement _x;
    CoordinateElement _y;

  protected:
    static const CoordinateElement increment(const CoordinateElement& iCoordinateElement) {
      return iCoordinateElement + 1;
    }

    static const CoordinateElement decrement(const CoordinateElement& iCoordinateElement) {
      return iCoordinateElement - 1;
    }

    static const CoordinateElement keep(const CoordinateElement& iCoordinateElement) {
      return iCoordinateElement;
    }

  };


  // don't worry, i will wrap and keep in bounds for you
  template<Position::CoordinateElement BoardLength>
  struct WrappedPosition : Position {
    WrappedPosition(const CoordinateElement& x, const CoordinateElement& y)
      : Position(wrap(x), wrap(y)) {}

    Position::CoordinateElement wrap(const Position::CoordinateElement& iCoordinateElement) {
      return (iCoordinateElement + BoardLength) % BoardLength;
    }

    WrappedPosition left() { return WrappedPosition(decrement(_x), keep(_y)); }
    WrappedPosition right() { return WrappedPosition(increment(_x), keep(_y)); }
    WrappedPosition up() { return WrappedPosition(keep(_x), decrement(_y)); }
    WrappedPosition down() { return WrappedPosition(keep(_x), increment(_y)); }
  };

}
