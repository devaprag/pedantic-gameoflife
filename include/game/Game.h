#pragma once

#include "Printer.h"
#include "Position.h"
#include "Board.h"  

#include <chrono>
#include <thread>

namespace game {
  template<board::Position::CoordinateElement BoardLength>
  class Game {
    public:
    static std::vector<board::WrappedPosition<BoardLength>> initialPositions() {
      std::vector<board::WrappedPosition<BoardLength>> aInitialPositions;
      aInitialPositions.push_back({ 4, 3 });  
      aInitialPositions.push_back({ 4, 4 });
      aInitialPositions.push_back({ 4, 5 }); 
      aInitialPositions.push_back({ 5, 2 });
      aInitialPositions.push_back({ 5, 3 });
      aInitialPositions.push_back({ 6, 3 });
      aInitialPositions.push_back({ 6, 4 });
      aInitialPositions.push_back({ 7, 3 });
      return aInitialPositions;
    }

    static void setup(board::Board<BoardLength>& iBoard) {
      iBoard.setup(initialPositions());      
    }

    static void run(board::Board<BoardLength>& iBoard, const unsigned int iNumberOfCycles, const unsigned int sleepDurationMillseconds) {
      for (unsigned int aCycle = 0; aCycle < iNumberOfCycles; ++aCycle) {
        print::clearScreen();
        iBoard.runLifeCycle();
        print::Printer<BoardLength>::print(iBoard);
        sleep(sleepDurationMillseconds);
      }
    }

    static void sleep(int sleepDuration) {
      std::this_thread::sleep_for(std::chrono::milliseconds(sleepDuration));
    }
  };

}