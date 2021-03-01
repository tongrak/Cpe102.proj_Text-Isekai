#ifndef PROGRAM_HPP
#define PROGRAM_HPP

#include<iostream>
#include<string>
#include<cctype>
using namespace std;

#include "Room.hpp"

class Program
{
    public:
    Program();
    void Run();

    private:
    string holder, in_key, in_wanted;
    bool is_running;

    void Action_checking();
    bool CheckingInputDir();
    void SplitKeyWord(string ,string &, string &);
    string Tolower(string);

};

//constructor
Program::Program(){
    holder="",in_key="",in_wanted="";
    is_running=true;
}

//Checking for userinput, if key word is pasent, do a "act".
void Program::Action_checking(){
    Room room;
    cout<<"> ";
    getline(cin, holder);
    SplitKeyWord(holder, in_key, in_wanted);
    if(Tolower(in_key)=="go")
    {
        if(in_wanted=="")cout<<"go where?"<<endl;
        else if(CheckingInputDir())room.ShowingRoomInfo();
        else{cout<<"nothing there"<<endl;}
    }
    else if(Tolower(in_key)=="exit"){
        cout<<"hope you enjoy your stay";
        is_running=false;
        }
    else if(Tolower(in_key)=="look")
    {
        room.ShowingRoomInfo();
    }
    else{cout<<"Sorry not quite get that."<<endl;}
        
}

//from lab17, thank prof.
void Program::SplitKeyWord(string in_text, string &key, string &wanted){
	int holder= in_text.find_first_of(" ");
    key=in_text.substr(0,holder);
    wanted=in_text.substr(holder+1);

} 
//Tolower is a cousin of ToUpperString
string Program::Tolower(string text){
    int i=text.size();
    string out="";
    for(int j=0;j<i;j++)
    {
        out+=tolower(text[j]);
    }
    return out;
}

//checking for valid direction and change curr_id;
bool Program::CheckingInputDir(){
    Room R;
    string holder;
    bool check=false;
    in_wanted=Tolower(in_wanted);
    if(in_wanted=="north"&&R.RuturnNeighbor(0, holder)!="NULL")
    {
        R.ChangeCurr_id(stoi(holder));
        check=true;
    }
    if(in_wanted=="east"&&R.RuturnNeighbor(1, holder)!="NULL")
    {
        R.ChangeCurr_id(stoi(holder));
        check=true;
    }
    if(in_wanted=="west"&&R.RuturnNeighbor(2, holder)!="NULL")
    {
        R.ChangeCurr_id(stoi(holder));
        check=true;
    }
    if(in_wanted=="south"&&R.RuturnNeighbor(3, holder)!="NULL")
    {
        R.ChangeCurr_id(stoi(holder));
        check=true;
    }
    return check;
} 

//for runing the 'game'
void Program::Run(){
    Room room_calling;
    room_calling.LoadMaps();
    room_calling.ChangeCurr_id(1);
    room_calling.ShowingRoomInfo();
    do{
    Action_checking();
    }while(is_running);

}



#endif
