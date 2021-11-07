//
//  Vehicle.cpp
//  RushHour
//
//  Created by Ziya Ata Yazici on 6.11.2021.
//

#include "Vehicle.hpp"

vector<Vehicle> Vehicle::VehicleVector;

Vehicle::Vehicle(int _id, int _length, int _x, int _y, char _dir){
    id = _id;
    length = _length;
    x = _x;
    y = _y;
    direction = _dir;
    
    //Add the created vehicle automatically to the vehicle vector.
    VehicleVector.push_back(*this);
}

int Vehicle::GetId(){
    return id;
}

int Vehicle::GetLength(){
    return length;
}

void Vehicle::SetX(int _x){
    x = _x;
}

void Vehicle::SetY(int _y){
    y = _y;
}

int Vehicle::GetX(){
    return x;
}

int Vehicle::GetY(){
    return y;
}

char Vehicle::GetDir(){
    return direction;
}
