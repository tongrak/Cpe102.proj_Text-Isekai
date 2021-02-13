#ifndef ROOM_HPP
#define ROOM_HPP

// Here lay a room setup

#include <iostream>
#include <string>
using namespace std;

//create room "type", or storage type, or data structure if you are a nerd.
struct Room{
    //Prototypign some "room" function
    Room();
    Room(string name, string description);
    void SetNeighbors( Room* North, Room* East, Room* West, Room* South);
    void Set(string name ="", string description="");
    void ShowingNeighbors();
    void ShowingRoomInfo();

    string name;
    string description;
    Room* ptrNearNorth;
    Room* ptrNearSouth;
    Room* ptrNearEast;
    Room* ptrNearWest;
};
Room::Room(){
    Set();
}

Room::Room(string name, string description){
    Set(name, description);
}

void Room::SetNeighbors( Room* ptrNorth, Room* ptrEast, Room* ptrWest, Room* ptrSouth)
{
    ptrNearNorth= ptrNorth;
    ptrNearEast= ptrEast;
    ptrNearWest= ptrWest;
    ptrNearSouth= ptrSouth;
}

void Room::ShowingNeighbors()
{
    cout<<"you can go:";
    if(ptrNearNorth!=nullptr)cout<<" North";
    if(ptrNearEast!=nullptr)cout<<" East";
    if(ptrNearWest!=nullptr)cout<<" West";
    if(ptrNearSouth!=nullptr)cout<<" South";
    cout<<endl;
}

void Room::ShowingRoomInfo()
{
    cout<<name<<endl<<description<<endl;
    ShowingNeighbors();
}

void Room::Set(string name /*= ""*/, string description /*=""*/){
    this->name=name;
    this->description=description;
    ptrNearNorth=nullptr;
    ptrNearSouth=nullptr;
    ptrNearEast=nullptr;
    ptrNearWest=nullptr;

}

#endif