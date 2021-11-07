//
//  main.cpp
//  RushHour
//
//  Created by Ziya Ata Yazici on 5.11.2021.
//  @ Istanbul Technical University, M.Sc.

#include <iostream>
#include <string>
#include "GameBoard.hpp"

using namespace std;

bool SolveRecursively(GameBoard, string);

int main(int argc, const char * argv[]) {
   
    GameBoard gameBoard;
    
    //Place the vehicles on board.
    // id, length, x, y, ditection
    Vehicle v1(0, 2, 0, 0, 'x'); //main
    Vehicle v2(1, 2, 0, 2, 'y');
    Vehicle v3(2, 2, 2, 0, 'y');
    Vehicle v4(3, 2, 2, 1, 'x');
    Vehicle v5(4, 2, 2, 3, 'x');
    Vehicle v6(5, 2, 0, 4, 'y');
    Vehicle v7(6, 2, 4, 1, 'x');
    Vehicle v8(7, 1, 4, 2, 'x');
    
    /*  (main)
        0    0    1      5       -> EXIT
                  1      5
        3    3         4    4
                  
        2    6    6     7
        2
     
     */
        
    SolveRecursively(gameBoard, " ");
    
    return 0;
}

bool SolveRecursively(GameBoard gb, string to){
    gb.UpdateBoard();

    vector<vector<int>> board = gb.GetBoard(); //Our game board
    vector<Vehicle> vehVec = Vehicle::VehicleVector;
    
    //Check if the main vehicle [0] does not have any vehicle front throught the EXIT.
    for(int i = vehVec[0].GetY() + vehVec[0].GetLength(); i < CAPACITY; i++){
        if(board[vehVec[0].GetX()][i] != 0) break;
        else if(i == CAPACITY - 1)
            return true;
    }
    
    
    //We use a random vehicle approach in each while loop until it passes to a recursive function.
    //An optimal solution could be implemented such that the algorithm returns
    //the fastest route in the multiple solutions found.
    while(true){
        int r = rand() % Vehicle::VehicleVector.size();
        Vehicle vR = vehVec[r];
        
        if(vR.GetDir() == 'x'){
            //X Positive
            for(int j = vR.GetY() + vR.GetLength(); (j < CAPACITY) &&
                (board[vR.GetX()][j] != 1) && (to != to_string(vR.GetId()) + "l"); j++){
                
                Vehicle::VehicleVector[vR.GetId()].SetY(vR.GetY() + 1);
                vR.SetY(vR.GetY() + 1);
                
                bool status = SolveRecursively(gb, to_string(vR.GetId()) + "r");
                
                Vehicle::VehicleVector[vR.GetId()].SetY(vR.GetY() - 1);
                vR.SetY(vR.GetY() - 1);
                
                if(status){
                    cout<<"Move: " + to_string(vR.GetId()) + ", in X by +1" <<endl;
                    return true;
                }
                else{
                    continue;
                }
            }
            
            //X Negative
            for(int j = vR.GetY() - 1; (j >= 0) &&
                (board[vR.GetX()][j] != 1) && (to != to_string(vR.GetId()) + "r"); j++){
                
                Vehicle::VehicleVector[vR.GetId()].SetY(vR.GetY() - 1);
                vR.SetY(vR.GetY() - 1);
                
                bool status = SolveRecursively(gb, to_string(vR.GetId()) + "l");
                
                Vehicle::VehicleVector[vR.GetId()].SetY(vR.GetY() + 1);
                vR.SetY(vR.GetY() + 1);
                
                if(status){
                    cout<<"Move: " + to_string(vR.GetId()) + ", in X by -1" <<endl;
                    return true;
                }
                else{
                    continue;
                }
            }
        }
        if(vR.GetDir() == 'y'){
            //Y Positive
            for(int j = vR.GetX() + vR.GetLength(); (j < CAPACITY) &&
                (board[j][vR.GetY()] != 1) && (to != to_string(vR.GetId()) + "u"); j++){
                
                Vehicle::VehicleVector[vR.GetId()].SetX(vR.GetX() + 1);
                vR.SetX(vR.GetX() + 1);
                
                bool status = SolveRecursively(gb, to_string(vR.GetId()) + "d");
                
                Vehicle::VehicleVector[vR.GetId()].SetX(vR.GetX() - 1);
                vR.SetX(vR.GetX() - 1);
                
                if(status){
                    cout<<"Move: " + to_string(vR.GetId()) + ", in Y by +1" <<endl;
                    return true;
                }
            }
            
            //Y Negative
            for(int j = vR.GetX() - 1; (j >= 0) && (board[j][vR.GetY()] != 1) &&
                (to != to_string(vR.GetId()) + "d"); j++){
                
                Vehicle::VehicleVector[vR.GetId()].SetX(vR.GetX() - 1);
                vR.SetX(vR.GetX() - 1);
                
                bool status = SolveRecursively(gb, to_string(vR.GetId()) + "u");
                
                Vehicle::VehicleVector[vR.GetId()].SetX(vR.GetX() + 1);
                vR.SetX(vR.GetX() + 1);
                
                if(status){
                    cout<<"Move: " + to_string(vR.GetId()) + ", in Y by -1" <<endl;
                    return true;
                }
            }
        }
    }
    
    return false;
}
