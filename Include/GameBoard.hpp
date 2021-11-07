//
//  GameBoard.hpp
//  RushHour
//
//  Created by Ziya Ata Yazici on 6.11.2021.
//

#ifndef GameBoard_hpp
#define GameBoard_hpp

#include <stdio.h>
#include "Vehicle.hpp"

const int CAPACITY = 6;

class GameBoard{
private:
    vector<vector<int>> board;
    
public:
    GameBoard();
    void UpdateBoard();
    vector<vector<int>> GetBoard();
};

#endif /* GameBoard_hpp */
