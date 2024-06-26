#include "meeting_queue.h"
#include <iostream>
using namespace std;

void Meeting::add_meeting(string title)
{
    meetings.push(title);
}

void Meeting::delete_latest_meeting()
{
    meetings.pop();
}

void Meeting::display_meetings()
{
    int count = 1;
    while( !meetings.empty())
    {
        string current_meeting = meetings.front();
        cout << "Meeting " << count << ":" << current_meeting << endl;
        count++;
        delete_latest_meeting();
    }
}