#ifndef ROOM_HPP
#define ROOM_HPP

#include<iostream>
#include<fstream> 
#include<string>
using namespace std;

class Room
{
    public:
    Room();
    void ShowingRoomInfo();
    
    
    private:
    string holder, name, descrip;
    string store[10][6]; //Key check, room ID, room name, descip, Key_id*4;
    string (*hid_CurrID)[6];
    int x;
    
    void LoadMaps();
    void SettingUpRoom(string (*)[6]);
};

Room::Room()
{
    string holder="",id ="",name="",descrip="";
    LoadMaps();
    hid_CurrID=store+0;

}

void Room::LoadMaps()
{
    ifstream file("maps.txt");
    x=-1;
    while(getline(file, holder))
    {
        if(holder=="ROOM_BEGIN")
        {
            x++;
            for(int i=0;i<6;i++){
                getline(file, store[x][i]);
            }
        }

    }
    file.close();
}

void Room::SettingUpRoom(string (*in_ptr)[6]){
    name=**in_ptr;
    descrip=*(*in_ptr+1);
}

void Room::ShowingRoomInfo()
{
    SettingUpRoom(hid_CurrID);
    cout<<"\t"<<name<<endl<<descrip<<endl;
}

#endif