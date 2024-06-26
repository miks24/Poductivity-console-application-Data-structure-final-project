#ifndef task_status
#define task_status

#include <string>
#include <map> 
using namespace std;

class Status
{
    private:
        map<string, string> TaskStatus;
    
    public:
        void add_element(string, string);
        void remove_elements(string);
        void clear_list(); //the user adds at the beginning of each day the tasks he has for the day and at the end of the day the list gets cleared
        void change_status(string, string);
        void display_elements();
};

#endif
/*this class is created to have a map that stores all the task of a developer
in a company and with each task there is a status (working on it, done, ...) so that the 
manager can then see where the developer is at*/