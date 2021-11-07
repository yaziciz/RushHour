//
//  Vehicle.hpp
//  RushHour
//
//  Created by Ziya Ata Yazici on 6.11.2021.
//

#ifndef Vehicle_hpp
#define Vehicle_hpp

#include <stdio.h>
#include <vector>

using namespace std;

class Vehicle{
  
private:
    int id;
    int length;
    int x;
    int y;
    char direction;
    
    
public:
    Vehicle(int, int, int, int, char);
    void SetX(int);
    void SetY(int);
    int GetId();
    int GetLength();
    int GetX();
    int GetY();
    char GetDir();
    
    static vector<Vehicle> VehicleVector;
};

#endif /* Vehicle_hpp */
