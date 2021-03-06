#pragma once
#ifndef PROGRAM_HPP
#define PROGRAM_HPP

#include<cctype>
using namespace std;

#include "Room.h"
//#include "Utilities.hpp"

/*
    Program.h, is almost like our main game processor, it duties are:
    -     Get current room detail and pass it on to GUI
    -     Taking User command, process, and return a order;
*/

/*
    String Processing  Function
*/

//from lab17, thank prof.
void SplitKeyWord(string in_text, string& key, string& wanted) {
    int holder = in_text.find_first_of(" ");
    key = in_text.substr(0, holder);
    wanted = in_text.substr(holder + 1);

}

//Tolower is a cousin of ToUpperString
string Tolower(string text) {
    int i = text.size();
    string out = "";
    for (int j = 0; j < i; j++)
    {
        out += tolower(text[j]);
    }
    return out;
}

/*
    Creating Room object
*/
    Room Room_calling;

/*
    Class and constructor
*/

class Program
{
public:
    Program();
    //void Run();

private:
    string holder, in_key, in_wanted;
    bool is_running;

    void Action_checking();
    bool CheckingInputDir();
    void Event_checking();


};

//constructor, load maps and event, and set Current ID to start
Program::Program() {
    holder = "", in_key = "", in_wanted = "";
    is_running = true;
    Room_calling.LoadMaps();
    Room_calling.LoadEvent();
    Room_calling.ChangeCurr_id(1);
    //Room_calling.ShowingRoomInfo();
}

/*
    Decision Making Function
*/

//Checking for userinput, if key word is pasent, do a "act".
void Program::Action_checking() {
    cout << "> ";
    getline(cin, holder);
    SplitKeyWord(holder, in_key, in_wanted);
    if (Tolower(in_key) == "go")
    {
        if (in_wanted == "")cout << "where?" << endl;
        else if (CheckingInputDir())/*Display detail of current room*/;
        else { cout << "nothing there" << endl; }
    }
    else if (Tolower(in_key) == "exit") {
        cout << "hope you enjoy your stay";
        is_running = false;
    }
    else if (Tolower(in_key) == "look")
    {
        /*Display detail of current room*/;
    }
    else { cout << "Sorry not quite get that." << endl; }

}

/*
    Checking Function
*/

//checking for valid direction and change curr_id;
bool Program::CheckingInputDir() {
    string holder;
    bool check = true;
    in_wanted = Tolower(in_wanted);
    if (in_wanted == "north" && Room_calling.GetNeighbors(0, holder) != "NULL")
    {
        Room_calling.ChangeCurr_id(stoi(holder));
    }
    else if (in_wanted == "east" && Room_calling.GetNeighbors(1, holder) != "NULL")
    {
        Room_calling.ChangeCurr_id(stoi(holder));
    }
    else if (in_wanted == "west" && Room_calling.GetNeighbors(2, holder) != "NULL")
    {
        Room_calling.ChangeCurr_id(stoi(holder));
    }
    else if (in_wanted == "south" && Room_calling.GetNeighbors(3, holder) != "NULL")
    {
        Room_calling.ChangeCurr_id(stoi(holder));
    }
    else { check = false; }
    return check;
}

void Program::Event_checking()
{
    string holder;
    if (Room_calling.GetEventId(holder) != "NULL")
    {
        switch (Room_calling.GetEventType(stoi(holder)))
        {
        case'C':
            /*Enter Combat*/
            break;
        case'B':
            /*Take Curr event description, display, and wait for answer*/
            break;
        case'S':
            /*Take Curr event description and display*/
            break;
        default:
            break;
        }
    }
}



/*
//for runing the 'game'
void Program::Run() {
    do {
        Action_checking();
    } while (is_running);

}
*/



#endif