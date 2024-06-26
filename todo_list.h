#ifndef todo_list
#define todo_list

#include <string>
#include <list>
#include <stack>
using namespace std;

class Todo
{
    private:
        list<string> TODO_list;
        stack<string> UNDO;
    
    public:
        void add_element(string);
        void remove_element(string);
        void display_list();
        void add_finished(string);
        void display_all_finished();
        void display_last_finished();
};


#endif

/*this class is about a todo list where the elements in the todo list is stored in a linked list
The developer can add as much elements as he wants then when done with an element remove it
from the to do list and every removed item is stored in a stack so that the user can 
remember what is the last thing he did*/