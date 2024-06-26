#include "todo_list.h"
#include <iostream>
#include <list>
#include <string>
using namespace std;

void Todo::add_element(string value) { 
    TODO_list.push_back(value);
}

void Todo::remove_element(string value) { 
    bool is_found = false;
    list<string>::iterator it;

    for(it = TODO_list.begin(); it != TODO_list.end();)
    {
        string current_value = *it;
        if(current_value == value)
        {
            add_finished(value);
            TODO_list.erase(it);
            cout << "task: " << value << " was removed from your to-do list." << endl;
            is_found = true;
            break;

        }

    }
    if (is_found == false)
    {
        cout << "task: " << value << " was not found" << endl;
    }
}

void Todo::display_list() {
    
    if(TODO_list.empty() == true)
    {
        cout << "Your to-do list is empty\n";
        return;
    }

    for(string value : TODO_list)
    {
        cout << "\u2022" << "- " << value << "\n";
    }
}

void Todo::add_finished(string finished)
{
    UNDO.push(finished);
}

void Todo::display_last_finished()
{
    string last_finished = UNDO.top();
    cout << "Last task you done is: " << last_finished << endl;
}

void Todo::display_all_finished()
{
    cout << "Your finished to-do list elements: \n";
    while(!UNDO.empty())
    {
        string top = UNDO.top();
        cout << top << endl;
        UNDO.pop();
    }
}