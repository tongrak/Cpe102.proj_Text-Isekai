#ifndef PROGRAM_HPP
#define PROGRAM_HPP

#include<iostream>
#include<map>
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

    //int* hid_CurrRoomId;
    void Action_checking();
    void SplitKeyWord(string ,string &, string &);
    string Tolower(string);

};

//constructor
Program::Program(){
}

void Program::Action_checking(){
    getline(cin, holder);
    SplitKeyWord(holder, in_key, in_wanted);
    if(Tolower(in_key)=="go")
    {
        
    }
}

void Program::SplitKeyWord(string in_text, string &key, string &wanted){
	int N = in_text.size(), loca;	
	for(loca = 0; loca < N; loca++){
		if(in_text[loca] == ' '){
			break;
		}
	}
	
	key = "";
	for(int i = 0; i < loca;i++){
		key += in_text[i];
	}

    wanted="";
    for(int i = loca+1; i < N;i++){
		wanted += in_text[i];
	}
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