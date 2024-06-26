#include "task_status.h"
#include <iostream>
using namespace std;

void Status::add_element(string task, string status)
{
    TaskStatus[task] = status;
}

void Status::remove_elements(string task)
{
    TaskStatus.erase(task);
}

void Status::clear_list()
{
    TaskStatus.clear();
}

void Status::change_status(string task , string new_status)
{
    TaskStatus[task] = new_status;
}

void Status::display_elements()
{
    cout << "Tasks:     " << "Status" << endl;
    for(pair<string, string> pair : TaskStatus)
    {
        cout << pair.first << ":     " << pair.second << endl;
    }
}
