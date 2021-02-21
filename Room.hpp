#ifndef ROOM_HPP
#define ROOM_HPP

#include<iostream>
#include<fstream> 
#include<string>
using namespace std;
#include "Program.hpp"

class Room
{
    public:
    Room();
    void ShowingRoomInfo();
    
    
    private:
    string holder, name, descrip;
    string store[10][7]; //Store Room_ID, Title, Description, connection between room.
    string (*hid_CurrID)[7];
    int x;
    
    void LoadMaps();
    void SettingUpRoom(string (*)[7]);
    void SettingConnection();
};

Room::Room()
{
    string holder="",id ="",name="",descrip="";
    LoadMaps();
    hid_CurrID=store; //sett room to starter.

}

void Room::LoadMaps()
{
    ifstream file("Maps.txt");
    x=-1;
    while(getline(file, holder))
    {
        if(holder=="ROOM_BEGIN")
        {
            x++;
            for(int i=0;i<3;i++){
                getline(file, store[x][i]);
            }
            /* for(int j=3;j<7;j++){

            } */


        }

    }
    file.close();
}

/* void Room::SettingConnection(){
    string form[]={"NORTH","EAST","WEST","SOUTH"};
    //for(int i=0;i<)
} */

void Room::SettingUpRoom(string (*in_ptr)[7]){
    name=*(*in_ptr+1);
    descrip=*(*in_ptr+2);
}

void Room::ShowingRoomInfo()
{
    SettingUpRoom(hid_CurrID);
    cout<<"\t"<<name<<endl<<descrip<<endl;
}

#endif