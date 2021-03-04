#ifndef ROOM_HPP
#define ROOM_HPP

#include<iostream>
#include<fstream> 
#include<string>
#include<map>
using namespace std;

/*
    Room.hpp duties are to:
    -   load Maps and store into map
    -   Load Event and store into map
    -   Get name and description, from given id, and return them
    -   Get Neighbor id, from given id, and return them
    -   Change Current position ID;

*/

//damn include guard;
//#include "Program.hpp"

//Goodbye, my old friend.
// class Room

struct Room{
    string name; 
    string description;
    string Neighbor[4];
    string eventID;

    void InitVar();
    void LoadMaps();
    void LoadEvent();
    void ShowingRoomInfo();
    void SettingUpRoom(int id, string &s1, string &s2);
    string ReturnNeighbor(int dir, string &keeper);
    string ReturnEventId();
    void ChangeCurr_id(int id);

    //constructor and distructor
    Room();
    ~Room();

};

struct Event{
    string event_name;
    string event_descrip;
    char event_type[2];
    string event_option;
};

//declare some variable
map<int,Room> roomStorage;
map<int,Event> eventStorage;
int *Curr_id = new int;
string *NAME = new string;
string *DESCRIP = new string;

void Room::InitVar()
{
    *Curr_id=0;
    *NAME="";
    *DESCRIP="";
}

//constructor, starting with Initialize some dynamics;
Room::Room()
{
    this->InitVar();
} 

//distructor, delete all dynamic
Room::~Room()
{
    delete Curr_id;
    delete NAME;
    delete DESCRIP;
}

//loading maps from Map.txt and store it in roomStorage map.
void Room::LoadMaps()
{
    string holder_str;
    int holder_int;
    ifstream file("Maps.txt");
    while(getline(file, holder_str))
    {
        if(holder_str=="ROOM_BEGIN")
        {
            Room R;
            getline(file, holder_str);
            holder_int=stoi(holder_str);
            getline(file, R.name);
            getline(file, R.description);
            for(int i=0;i<4;i++)
            {
                getline(file, holder_str);
                int temp=holder_str.find_first_of(" ");
                R.Neighbor[i]=holder_str.substr(temp+1);
            }
            getline(cin, holder_str);
            int temp=holder_str.find_first_of(" ");
            R.eventID=holder_str.substr(temp+1);
            roomStorage.insert(pair<int,Room>(holder_int,R));
        }
    }
    file.close();
}

void Room::LoadEvent()
{
    string holder_str;
    int holder_int;
    ifstream file("Events.txt");
    while(getline(file, holder_str))
    {
        if(holder_str=="EVENT_BEGIN")
        {
            Event eve;
            getline(file, holder_str);
            holder_int=stoi(holder_str);
            getline(file, eve.event_name);
            getline(file, eve.event_descrip);
            string temp;
            getline(file,temp);
            strcpy(eve.event_type, temp.c_str());
            getline(file, eve.event_option);
            eventStorage.insert(pair<int,Event>(holder_int,eve));   
        }
    }
    file.close();
}

//Ruturing a Neighbor id.
string Room::ReturnNeighbor(int dir, string &keeper){
    keeper = roomStorage[*Curr_id].Neighbor[dir];
    return roomStorage[*Curr_id].Neighbor[dir];

}

string Room::ReturnEventId(){
    return roomStorage[*Curr_id].eventID;
}

//as the name suggest, it change Curr_id
void Room::ChangeCurr_id(int id){
    *Curr_id=id;
}

//Setting up string to be print.
void Room::SettingUpRoom(int ID, string &inni_name, string &inni_des){
    inni_name=roomStorage[ID].name;
    inni_des=roomStorage[ID].description;
}


//for printing string on console(for now);
void Room::ShowingRoomInfo()
{
    SettingUpRoom(*Curr_id, *NAME, *DESCRIP);
    cout<<"\t"<<*NAME<<endl<<*DESCRIP<<endl;
}

#endif