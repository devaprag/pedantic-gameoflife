#include "Game.h"

int main() {

  constexpr int kBoardLength = 10;
  constexpr unsigned int numberOfCycles = 10;
  constexpr unsigned int sleepDurationMillseconds = 100;
  
  board::Board<kBoardLength> board;
  game::Game<kBoardLength>::setup(board);
  game::Game<kBoardLength>::run(board, numberOfCycles, sleepDurationMillseconds);
  
  return 0;
}
