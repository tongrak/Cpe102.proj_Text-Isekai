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

    void LoadMaps();
    void ShowingRoomInfo();
    void SettingUpRoom(int id, string &s1, string &s2);
    string RuturnNeighbor(int dir, string &keeper);
    void ChangeCurr_id(int id);

}; 

//declare some variable
map<int,Room> Storage;
int *Curr_id = new int;
string *NAME = new string;
string *DESCRIP = new string;

//constructor, disable for now.
/* Room::Room()
{
    //LoadMaps();
    *Curr_id=0;
} */

//loading maps from Map.txt and store it in Storage map.
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
                string str_temp=holder_str.substr(temp+1);
                R.Neighbor[i]=str_temp;
            }
            Storage.insert(pair<int,Room>(holder_int,R));
        }
    }
    file.close();
}

//Ruturing a Neighbor id.
string Room::RuturnNeighbor(int dir, string &keeper){
    keeper = Storage[*Curr_id].Neighbor[dir];
    return Storage[*Curr_id].Neighbor[dir];

}
//as the name suggest, it change Curr_id
void Room::ChangeCurr_id(int id){
    *Curr_id=id;
}

//Setting up string to be print.
void Room::SettingUpRoom(int ID, string &inni_name, string &inni_des){
    inni_name=Storage[ID].name;
    inni_des=Storage[ID].description;
}


//for printing string on console(for now);
void Room::ShowingRoomInfo()
{
    SettingUpRoom(*Curr_id, *NAME, *DESCRIP);
    cout<<"\t"<<*NAME<<endl<<*DESCRIP<<endl;
}

#endif