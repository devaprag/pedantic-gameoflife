#include <iostream>
#include <algorithm>

#include "Board.h"
#include "Printer.h"
#include "Position.h"

#include <vector>

#include <chrono>
#include <thread>


int main() {
  constexpr int kBoardLength = 10;

  board::Board<kBoardLength> board;
  
  // init

  std::vector<position::WrappedPosition<kBoardLength>> aInitialPositions;
  aInitialPositions.push_back({ 4, 3 });  
  aInitialPositions.push_back({ 4, 4 });
  aInitialPositions.push_back({ 4, 5 }); 
  aInitialPositions.push_back({ 5, 2 });
  aInitialPositions.push_back({ 5, 3 });
  aInitialPositions.push_back({ 6, 3 });
  aInitialPositions.push_back({ 6, 4 });
  aInitialPositions.push_back({ 7, 3 });

  board.initialise(aInitialPositions);
  printer::Printer<kBoardLength>::print(board);
  
  
  for (int i = 0; i < 10; ++i) {
    std::cout << "\033[2J\033[1;1H"; // clears screen
    board.runLifeCycle();
    printer::Printer<kBoardLength>::print(board);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }

  
  return 0;
}