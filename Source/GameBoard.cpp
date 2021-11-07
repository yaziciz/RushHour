//
//  GameBoard.cpp
//  RushHour
//
//  Created by Ziya Ata Yazici on 6.11.2021.
//

#include "GameBoard.hpp"

GameBoard::GameBoard(){};

//Set the 2D vector indices as 1 if a vehicle occupies, 0 if not.
void GameBoard::UpdateBoard(){
    vector<Vehicle> vehicle = Vehicle::VehicleVector;
    
    board = vector<vector<int>>(CAPACITY, vector<int>(CAPACITY, 0));
    
    for(auto i:Vehicle::VehicleVector){
        if(i.GetDir() == 'x')
            for(int j = 0; j < i.GetLength(); j++)
                board[i.GetX()][i.GetY() + j] = 1;
        else
            for(int j = 0; j < i.GetLength(); j++)
                board[i.GetX() + j][i.GetY()] = 1;
    }
}

vector<vector<int>> GameBoard::GetBoard(){
    return board;
}
