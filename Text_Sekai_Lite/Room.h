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
};

struct Event {
    string event_name;
    string event_descrip;
    char event_type;
    string event_option;
    bool event_activated;
    string event_condition;
    bool event_checkpoint;

    Event();
};

class data_load {
public:
    //Loading function
    void LoadMaps();
    void LoadEvent();
    //Getting Variable function
    string GetCurrName();
    string GetCurrDes();
    char GetEventType();
    string GetEventName();
    string GetEventDes();
    string GetEventOpt();
    string GetEventCon();
    string GetNeighbors(int dir, string& keeper);
    string GetEventId(string&);
    bool GetEventAct();
    bool GetEventCheck();
    int GetLastCheck();
    //Changing variable function
    void ChangeCurr_id(int id);
    void ChangeEvent_id(int id);
    void ChangeEventToInAct();
    void ChangeLastCheck();
    //Just for testing zone
    void ShowingRoomInfo();
    //construtor and distrutors
    data_load();
    ~data_load();



    //void GetRoomStr(int id, string& s1, string& s2);


private:
    //Declare variable in need
    map<int, Room> roomStorage;
    map<int, Event> eventStorage;
    int* Curr_id;
    int* Event_id;
    int* last_check;
    string* NAME;
    string* DESCRIP;

};

/*
    Constructor and Distructor of structure
*/

data_load::data_load() {
    Curr_id = new int;
    last_check = new int;
    Event_id = new int;
    NAME = new string;
    DESCRIP = new string;
    
    *Curr_id = 0;
    *last_check = 0;
    *Event_id = 0;
    *NAME = "";
    *DESCRIP = "";

}

data_load::~data_load() {
    delete Curr_id;
    delete last_check;
    delete NAME;
    delete DESCRIP;
}

Event::Event() {
    event_activated = false;
    event_checkpoint = false;
    event_type = ' ';
}

/*
    Loading zone
*/

//loading maps from Map.txt and store it in roomStorage map.
void data_load::LoadMaps()
{
    cout << "Loading Maps";
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
            getline(file, holder_str);
            int temp = holder_str.find_first_of(" ");
            R.eventID = holder_str.substr(temp + 1);
            roomStorage.insert(pair<int, Room>(holder_int, R));
        }
    }
    file.close();
    cout << " Done" << endl;
}

//Loading event detail from Event.txt and store it in eventStorage Map.
void data_load::LoadEvent()
{
    cout << "loading Event";
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
            string temp, t2;
            getline(file, temp);
            int holder = temp.find_first_of(" ");
            t2 = temp.substr(holder + 1);
            eve.event_type = t2[0];
            getline(file, eve.event_option);
            getline(file, eve.event_condition);
            getline(file, temp);
            holder = temp.find_first_of(" ");
            t2 = temp.substr(holder + 1);
            (t2 == "YES") ? eve.event_checkpoint = true : eve.event_checkpoint = false;
            //Storing
            eventStorage.insert(pair<int, Event>(holder_int, eve));
        }
    }
    file.close();
    cout << " Done" << endl;
}

/*
    Accesor and Changing on command function
*/

//Ruturing a Neighbor id.
string data_load::GetNeighbors(int dir, string& keeper) {
    keeper = roomStorage[*Curr_id].Neighbor[dir];
    return roomStorage[*Curr_id].Neighbor[dir];

}

//Returning a current event id.
string data_load::GetEventId(string& keeper) {
    keeper = roomStorage[*Curr_id].eventID;
    return roomStorage[*Curr_id].eventID;
}

//Taken ID and change Current ID
void data_load::ChangeCurr_id(int id) {
    *Curr_id = id;
}

void data_load::ChangeEventToInAct() {
    eventStorage[*Event_id].event_activated = true;
}

void data_load::ChangeEvent_id(int id) {
    *Event_id = id;
}

void data_load::ChangeLastCheck()
{
    int x = *Curr_id;
    *last_check = x;
}

string data_load::GetCurrName()
{
    return roomStorage[*Curr_id].name;
}


string data_load::GetCurrDes()
{
    return roomStorage[*Curr_id].description;
}

char data_load::GetEventType()
{
    return eventStorage[*Event_id].event_type;
}

string data_load::GetEventName()
{
    return eventStorage[*Event_id].event_name;
}

string data_load::GetEventDes()
{
    return eventStorage[*Event_id].event_descrip;
}

string data_load::GetEventOpt()
{
    return eventStorage[*Event_id].event_option;
}

bool data_load::GetEventAct()
{
    return eventStorage[*Event_id].event_activated;
}

string data_load::GetEventCon()
{
    return eventStorage[*Event_id].event_condition;
}

bool data_load::GetEventCheck()
{
    return eventStorage[*Event_id].event_checkpoint;
}

int data_load::GetLastCheck()
{
    return *last_check;
}


//for printing string on console(for now);
void data_load::ShowingRoomInfo()
{
    *NAME = GetCurrName();
    *DESCRIP = GetCurrDes();
    cout << "\t" << *NAME << endl << *DESCRIP << endl;
}


#endif