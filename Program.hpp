#ifndef PROGRAM_HPP
#define PROGRAM_HPP

#include<cctype>
using namespace std;

#include "Room.hpp"
#include "Utilities.hpp"

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
    void Event_checking();

    void SplitKeyWord(string ,string &, string &);
    string Tolower(string);

};

//constructor
Room Room_calling;

Program::Program(){
    holder="",in_key="",in_wanted="";
    is_running=true;
    Room_calling.LoadMaps();
    Room_calling.LoadEvent();
    Room_calling.ChangeCurr_id(1);
    //Room_calling.ShowingRoomInfo();
}

//Checking for userinput, if key word is pasent, do a "act".
void Program::Action_checking(){
    Menu display;
    cout<<"> ";
    getline(cin, holder);
    SplitKeyWord(holder, in_key, in_wanted);
    if(Tolower(in_key)=="go")
    {
        if(in_wanted=="")cout<<"where?"<<endl;
        else if(CheckingInputDir())Room_calling.ShowingRoomInfo();
        else{cout<<"nothing there"<<endl;}
    }
    else if(Tolower(in_key)=="exit"){
        cout<<"hope you enjoy your stay";
        is_running=false;
        }
    else if(Tolower(in_key)=="look")
    {
        display.ClearScreen();
        Room_calling.ShowingRoomInfo();
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
    string holder;
    bool check=true;
    in_wanted=Tolower(in_wanted);
    if(in_wanted=="north"&&Room_calling.ReturnNeighbor(0, holder)!="NULL")
    {
        Room_calling.ChangeCurr_id(stoi(holder));
    }
    else if(in_wanted=="east"&&Room_calling.ReturnNeighbor(1, holder)!="NULL")
    {
        Room_calling.ChangeCurr_id(stoi(holder));
    }
    else if(in_wanted=="west"&&Room_calling.ReturnNeighbor(2, holder)!="NULL")
    {
        Room_calling.ChangeCurr_id(stoi(holder));
    }
    else if(in_wanted=="south"&&Room_calling.ReturnNeighbor(3, holder)!="NULL")
    {
        Room_calling.ChangeCurr_id(stoi(holder));
    }
    else{check=false;}
    return check;
} 

void Program::Event_checking()
{
    if(Room_calling.ReturnEventId() != "NULL")
    {
        
    }
}

//for runing the 'game'
void Program::Run(){
    do{
    Action_checking();
    }while(is_running);

}



#endif