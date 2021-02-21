#ifndef PROGRAM_HPP
#define PROGRAM_HPP

#include<iostream>
//#include<map>
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

    //int* hid_CurrRoomId;
    void Action_checking();
    void SplitKeyWord(string ,string &, string &);
    string Tolower(string);

};

//constructor
Program::Program(){
    holder="",in_key="",in_wanted="";
    is_running=true;

}

void Program::Action_checking(){
    do{
    cout<<"> ";
    getline(cin, holder);
    SplitKeyWord(holder, in_key, in_wanted);
    if(Tolower(in_key)=="go"){cout<<"Got key as go"<<endl;}
    else if(Tolower(in_key)=="exit"){is_running=false;}
    else if(Tolower(in_key)=="look")
    {
        Room calling;
        calling.ShowingRoomInfo();
    }
    else{cout<<"Sorry not quite get that."<<endl;}
    }while(is_running);
        
}

void Program::SplitKeyWord(string in_text, string &key, string &wanted){
	int holder= in_text.find_first_of(" ");
    key=in_text.substr(0,holder);
    wanted=in_text.substr(holder+1);

} 

string Program::Tolower(string text){
    int i=text.size();
    string out="";
    for(int j=0;j<i;j++)
    {
        out+=tolower(text[j]);
    }
    return out;
}
//for runing 'game'
void Program::Run(){
    Room room_calling;
    room_calling.ShowingRoomInfo();
    Action_checking();
}



#endif