#ifndef PROGRAM_HPP
#define PROGRAM_HPP
//Here lay a main program

#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include "room.hpp"

class Program
{
    public:
    Program();
    void Run();

    private:
    void LoadingRooms();
    Room* hid_ptrCurrPosi;
    vector<Room*> hid_roomLoader;
    bool hid_projRunning;
    int CreateRoom(string name, string description);
    int roomId;

};

//setting up variable in use.
Program::Program(){
    Program::hid_ptrCurrPosi = nullptr;
    hid_projRunning=true;
    roomId=-1;
    LoadingRooms();
}   

//for running a "game"
void Program::Run(){
    string user_input;
    while(hid_projRunning){
        hid_ptrCurrPosi->ShowingRoomInfo();
        
        cout<<"Your action> ";
        getline(cin, user_input);
        if(user_input!="")hid_projRunning=false;
    }
}

int Program::CreateRoom(string name, string description)
{
    Room *id= new Room;
    id->Set(name,description);
    hid_roomLoader.push_back(id);
    roomId++;
    return roomId;
}

void Program::LoadingRooms(){
    //setting up the rooms.
    int str_room=CreateRoom("Strating room", "Testing, if program running or not");
    int North_room=CreateRoom("Northen Room","Nothing special here");
    int East_room=CreateRoom("Easten room","Nothing speacial here either");
    int West_room=CreateRoom("Westen Room", "a squre room with nothing inside");
    int South_room=CreateRoom("Southen room","A deadend");
    hid_ptrCurrPosi=hid_roomLoader[str_room]; 

    //out of order zone
    hid_roomLoader[str_room]->SetNeighbors(hid_roomLoader[1],hid_roomLoader[2],hid_roomLoader[3],hid_roomLoader[4]);
}


#endif