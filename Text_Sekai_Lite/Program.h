#pragma once
#ifndef PROGRAM_HPP
#define PROGRAM_HPP

#include<cctype>
using namespace std;

#include "Room.h"
//#include "Utilities.hpp"

/*
    Program.h, is almost like our main game processor(Or Engine, if you will), it duties are:
    -     Get current room detail and pass it on to GUI
    -     Taking User command, process, and return a order;

    TODO:
    -   All Data loading and processing and Gui load, shall be called for use in Program.h or Main.cpp
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
data_load Room_calling;

/*
    Class and constructor
*/

class Program
{
public:
    Program();
    void Run();

private:
    string holder, in_key, in_wanted;
    bool is_running;
    bool is_kicking;

    void Action_checking();
    bool CheckingInputDir();
    void Event_checking();
    void Checkpoint_checking();
    void Dead();


};

//constructor, load maps and event, and set Current ID to start
Program::Program() {
    holder = "", in_key = "", in_wanted = "";
    is_running = true;
    is_kicking = true;
    Room_calling.LoadMaps();
    Room_calling.LoadEvent();
    Room_calling.ChangeCurr_id(1);
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
        else if (CheckingInputDir())
        {
            Event_checking();
            Room_calling.ShowingRoomInfo();
        }
        else { cout << "nothing there" << endl; }
    }
    else if (Tolower(in_key) == "exit") {
        cout<<"Do you want to exit"<<endl;
        string t1;
        bool bo = true;
        do{
            getline(cin,t1);
            cout<<"> ";
            if(Tolower(t1)=="yes")
            {
                bo = false;
                is_running = false;
            }
            else if(Tolower(t1)=="no")
            {
                break;
            }
            else cout<<"Yes or No"<<endl;
        }while(bo);
    }
    else if (Tolower(in_key) == "look")
    {
        Room_calling.ShowingRoomInfo();
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
        Room_calling.ChangeEvent_id(stoi(holder));
        Checkpoint_checking();
        switch (Room_calling.GetEventType())
        {
        case'C':
            /*Enter combat*/
            break;
        case'B':
            if (!Room_calling.GetEventAct())
            {
                bool q = true;
                string x, a1, a2, b1, b2;
                cout<<"\t"<<Room_calling.GetEventName()<<endl<<Room_calling.GetEventDes()<<endl;
                SplitKeyWord(Room_calling.GetEventOpt(), a1, a2);
                SplitKeyWord(Room_calling.GetEventCon(), b1, b2);
                cout<<a1<<" or "<<a2;
                do {
                    cout<<"> ";
                    getline(cin, x);
                    if (Tolower(x) == Tolower(a1))
                    {

                        if (b1 == "DEAD") Dead();
                        q = false;
                        
                    }
                    else if (Tolower(x) == Tolower(a2))
                    {
                        if (b2 == "DEAD") Dead();
                        q = false;
                      
                    }
                    else {
                        cout<<"Not what I asked"<<endl;
                    }
                } while (q);
                Room_calling.ChangeEventToInAct();
            }
            break;
        case'S':
            if (!Room_calling.GetEventAct())
            {
                cout<<"\t"<<Room_calling.GetEventName()<<endl<<Room_calling.GetEventDes()<<endl;
                system("pause");
                Room_calling.ChangeEventToInAct();
                if(Room_calling.GetEventCon()=="DEAD") Dead();
            }
            break;
        default:
            break;
        }
    }
}

void Program::Checkpoint_checking() {
    bool x1 =Room_calling.GetEventCheck();
    if (x1){
        cout<<x1<<endl;
        Room_calling.ChangeLastCheck();
        }
}

void Program::Dead() {
    is_kicking = false;
    cout<<"you are history"<<endl;
}

void Program::Run()
{
    Event_checking();
    Room_calling.ShowingRoomInfo();
    do{
        Action_checking();
        if(!is_kicking)
        {
            cout<<"Do you want to go to last checkpoint??"<<endl;
            string t1;
            bool bo = true;
            do{
                cout<<"> ";
                getline(cin,t1);
                if(Tolower(t1)=="yes")
                {
                    is_kicking = true;
                    Room_calling.ChangeCurr_id(Room_calling.GetLastCheck());
                    bo = false;
                    Room_calling.ShowingRoomInfo();
                }
                else if(Tolower(t1)=="no")
                {
                    is_running = false;
                    bo = false;
                }
                else cout<<"Yes or No"<<endl;
            }while(bo);
        }
    }while(is_running);
}

#endif