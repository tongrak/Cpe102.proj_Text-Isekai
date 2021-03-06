#pragma once
#ifndef ROOM_HPP
#define ROOM_HPP

#include<iostream>
#include<fstream> 
#include<string>
#include<map>
using namespace std;

/*
    Room.h duties are to:
    -   load Maps detail and store into Map type arrays
    -   Load Event detail and store into Map type arrays
    -   Returning Name and Description, for a  given room id, in string type
    -   Returning Neightbor IDs in string type
    -   Taking ID and change Current ID

*/

/*
    Structure of Room and Event
*/

struct Room {
    string name;
    string description;
    string Neighbor[4];
    string eventID;

    void InitVar();
    void LoadMaps();
    void LoadEvent();
    //void ShowingRoomInfo();
    //void GetRoomStr(int id, string& s1, string& s2);
    string GetCurrName();
    string GetCurrDes();
    char GetEventType(int );
    string GetNeighbors(int dir, string& keeper);
    string GetEventId(string&);
    void ChangeCurr_id(int id);

    //constructor and distructor
    Room();
    ~Room();

};

struct Event {
    string event_name;
    string event_descrip;
    char event_type;
    string event_option;
};

//declare some variable
map<int, Room> roomStorage;
map<int, Event> eventStorage;
int* Curr_id = new int;
string* NAME = new string;
string* DESCRIP = new string;


/*
    Constructor and Distructor of structure
*/

//Initialize variables in needs.
void Room::InitVar()
{
    *Curr_id = 0;
    *NAME = "";
    *DESCRIP = "";
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

/*
    Loading zone
*/

//loading maps from Map.txt and store it in roomStorage map.
void Room::LoadMaps()
{
    string holder_str;
    int holder_int;
    ifstream file("Maps.txt");
    while (getline(file, holder_str))
    {
        if (holder_str == "ROOM_BEGIN")
        {
            Room R;
            getline(file, holder_str);
            holder_int = stoi(holder_str);
            getline(file, R.name);
            getline(file, R.description);
            for (int i = 0; i < 4; i++)
            {
                getline(file, holder_str);
                int temp = holder_str.find_first_of(" ");
                R.Neighbor[i] = holder_str.substr(temp + 1);
            }
            getline(cin, holder_str);
            int temp = holder_str.find_first_of(" ");
            R.eventID = holder_str.substr(temp + 1);
            roomStorage.insert(pair<int, Room>(holder_int, R));
        }
    }
    file.close();
}

//Loading event detail from Event.txt and store it in eventStorage Map.
void Room::LoadEvent()
{
    string holder_str;
    int holder_int;
    ifstream file("Events.txt");
    while (getline(file, holder_str))
    {
        if (holder_str == "EVENT_BEGIN")
        {
            Event eve;
            getline(file, holder_str);
            holder_int = stoi(holder_str);
            getline(file, eve.event_name);
            getline(file, eve.event_descrip);
            string temp;
            getline(file, temp);
            eve.event_type = temp[0];
            getline(file, eve.event_option);
            eventStorage.insert(pair<int, Event>(holder_int, eve));
        }
    }
    file.close();
}

/*
    Accesor and Changing on command function
*/

//Ruturing a Neighbor id.
string Room::GetNeighbors(int dir, string& keeper) {
    keeper = roomStorage[*Curr_id].Neighbor[dir];
    return roomStorage[*Curr_id].Neighbor[dir];

}

//Returning a current event id.
string Room::GetEventId(string &keeper) {
    keeper = roomStorage[*Curr_id].eventID;
    return roomStorage[*Curr_id].eventID;
}

//Taken ID and change Current ID
void Room::ChangeCurr_id(int id) {
    *Curr_id = id;
}

/*
//Setting up string to be print.
void Room::GetRoomStr(int ID, string& inni_name, string& inni_des) {
    inni_name = roomStorage[ID].name;
    inni_des = roomStorage[ID].description;
}
*/

//returning Current room name, in string
string Room::GetCurrName()
{
    return roomStorage[*Curr_id].name;
}


//returning Current room description, in string
string Room::GetCurrDes()
{
    return roomStorage[*Curr_id].description;
}

char Room::GetEventType(int key)
{
    return eventStorage[key].event_type;
}


/*
//for printing string on console(for now);
void Room::ShowingRoomInfo()
{
    SettingUpRoom(*Curr_id, *NAME, *DESCRIP);
    cout << "\t" << *NAME << endl << *DESCRIP << endl;
}
*/

#endif