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
    
    // main loop
    static void run(board::Board<BoardLength>& iBoard, 
                    const unsigned int iNumberOfCycles, 
                    const unsigned int sleepDuration) {
      for (unsigned int aCycle = 0; aCycle < iNumberOfCycles; ++aCycle) {
        // one life cycle
        iBoard.step();
        
        // print
        print::clearScreen();
        print::Printer<BoardLength>::print(iBoard);
        
        // sleep
        sleep(sleepDuration);
      }
    }

    static void sleep(const unsigned int sleepDuration) {
      std::this_thread::sleep_for(std::chrono::milliseconds(sleepDuration));
    }

    // inital conditions
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

    // inital conditions
    static void setup(board::Board<BoardLength>& iBoard) {
      iBoard.setup(initialPositions());      
    }

  };

}