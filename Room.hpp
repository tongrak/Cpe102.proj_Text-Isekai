#ifndef ROOM_HPP
#define ROOM_HPP

#include<iostream>
#include<fstream> 
#include<string>
#include<map>
using namespace std;

//damn include guard;
//#include "Program.hpp"

//Goodbye, my old friend.
// class Room

struct Room{
    string name; 
    string description;
    string Neighbor[4];

    Room();
    void LoadMaps();
    void ShowingRoomInfo();
    void SettingUpRoom(int id, string &s1, string &s2);

}; 

//declare some variable
map<int,Room> Storage;
int *Curr_id = new int;
string *NAME = new string;
string *DESCRIP = new string;

//constructor
Room::Room()
{
    LoadMaps();
    *Curr_id=0;
}

//loading maps from Map.txt and store it in store arrays.
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
            string holder;
            getline(file, holder);
            holder_int=stoi(holder);
            getline(file, R.name);
            getline(file, R.description);
            for(int i=0;i<4;i++)
            {
                getline(file, holder_str);
                int temp=holder_str.find_first_of(" ");
                string str_temp=holder_str.substr(temp+1);
                R.Neighbor[i]=str_temp;
            }
            //cout<<endl;
            Storage.insert(pair<int,Room>(holder_int,R));
        }
    }
    file.close();
}

//Move to Program.hpp
// bool Room::CheckingInputDir(){


void Room::SettingUpRoom(int ID, string &s1, string &s2){
    s1=Storage[ID].name;
    s2=Storage[ID].description;
}

void Room::ShowingRoomInfo()
{
    SettingUpRoom(*Curr_id, *NAME, *DESCRIP);
    cout<<"\t"<<name<<endl<<description;
}

#endif