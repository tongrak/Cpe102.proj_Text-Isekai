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
    bool CheckingInputDir();
    
    
    private:
    string holder_str, name, descrip;
    string store[10][7]; //Store Room_ID, Title, Description, North, west, east, south connnector.
    int holder_int, *CurrID=new int;
    
    void LoadMaps();
    void SettingUpRoom(int ID);
};

//constructor
Room::Room()
{
    string holder="",name="",descrip="";
    LoadMaps();
    *CurrID=0; //sett room to starter.

}

//loading maps from Map.txt and store it in store arrays.
void Room::LoadMaps()
{
    ifstream file("Maps.txt");
    int x=-1;
    while(getline(file, holder_str))
    {
        if(holder_str=="ROOM_BEGIN")
        {
            x++;
            for(int i=0;i<3;i++){
                getline(file, store[x][i]);
            }
            for(int j=3;j<7;j++){
                getline(file, holder_str);
                int temp=holder_str.find_first_of(" ");
                string str_temp=holder_str.substr(temp+1);
                store[x][j]=str_temp;
            }


        }


    }
    file.close();
}

//Checking User directive input, if valid change CurrID
bool Room::CheckingInputDir(){
    //couldn't make this to work.
    /*
    Program pro;
    holder_str=pro.out_wanted;
    */
    bool temp_bool=false;
    if(holder_str=="north"&&store[*CurrID][3]!="NULL"){
        *CurrID=stoi(store[*CurrID][3]);
        temp_bool=true;
    }else if(holder_str=="west"&&store[*CurrID][4]!="NULL"){
        *CurrID=stoi(store[*CurrID][4]);
        temp_bool=true;
    }else if(holder_str=="east"&&store[*CurrID][5]!="NULL"){
        *CurrID=stoi(store[*CurrID][5]);
        temp_bool=true;
    }else if(holder_str=="south"&&store[*CurrID][6]!="NULL"){
        *CurrID=stoi(store[*CurrID][6]);
        temp_bool=true;
    }
    return temp_bool;
}


void Room::SettingUpRoom(int ID){
    name=store[ID][1];
    descrip=store[ID][2];
}

void Room::ShowingRoomInfo()
{
    SettingUpRoom(*CurrID);
    cout<<"\t"<<name<<endl<<descrip<<endl;
}

#endif