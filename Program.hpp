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
    string out_wanted;

    private:
    string holder, in_key, in_wanted;
    bool is_running;

    void Action_checking();
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
    do{
    Room room;
    cout<<"> ";
    getline(cin, holder);
    SplitKeyWord(holder, in_key, in_wanted);
    if(Tolower(in_key)=="go")
    {
        out_wanted=Tolower(in_wanted);
        
        if(room.CheckingInputDir())room.ShowingRoomInfo();
        else{cout<<"nothing there"<<endl;}
    }
    else if(Tolower(in_key)=="exit"){is_running=false;}
    else if(Tolower(in_key)=="look")
    {
        room.ShowingRoomInfo();
    }
    else{cout<<"Sorry not quite get that."<<endl;}
    }while(is_running);
        
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

//for runing the 'game'
void Program::Run(){
    Room room_calling;
    room_calling.ShowingRoomInfo();
    Action_checking();
}



#endif