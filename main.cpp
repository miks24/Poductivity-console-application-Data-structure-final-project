#include <iostream>
#include "todo_list.h"
#include "task_status.h"
#include "meeting_queue.h"
#include <set>
using namespace std;

int main()
{
    //initiating data structures / variables / classes
    set<string> login_users; //for manager to know who logged in and created as a set so that if the same person logged in twice it will only show once
    Todo to_do; 
    Status Task;
    Meeting meeting;
    int role = 0;
    int program = 0;
    int choice = 0;

    string name;
    cout << "\t\tWELCOME\n";
    cout <<"\t\t-------\n\n";
    cout << "ENTER YOUR ROLE: \n1-DEVELOPER\n" << "2-MANAGER\n" << "0-EXIT PROGRAM" << endl;
    cin >> role;

    while(role != 0) //infinite loop until user press 0 to exit
    {
        if(role == 1) //everything in this if is for the developer part
        {
            cout << "TO LOGIN WRITE YOUR FULL NAME PLEASE: ";
            cin.ignore();
            getline(cin, name);
            cout << "\n\nWELCOME " << name << endl;
            login_users.insert(name); //add user to logged in users so that the manager can see

            cout << "ENTER WHAT YOU WANT TO ACCESS : \n1-TO-DO LIST\n" << "2-TASKS FOR THE DAY\n" << "0-EXIT" << endl;
            cin >> program;

            while(program != 0) //another ifinite loop that is done when user press 0
            {
                if (program == 1) //to do list part
                {
                    cout << "WHAT WOULD YOU LIKE TO DO: \n1-ADD ITEM\n" << "2-REMOVE ITEM\n" << "3-DISPLAY YOUR TO-DO LIST\n" << "4-DISPLAY THE LAST ITEM YOU FINISHED\n" << "5-DISPLAY ALL THE ITEMS YOU FINISHED\n" << "0-RETURN TO HOME SCREEN" << endl;
                    cin >> choice;

                    if(choice == 1)
                    {
                        string to_add;
                        cout << "What would you like to add: ";
                        cin.ignore();
                        getline(cin, to_add);
                        to_do.add_element(to_add);
                        cout << "\nItem has been added\n\n";
                    }
                    else if(choice == 2)
                    {
                        string to_remove;
                        cout << "What would you like to remove: ";
                        cin.ignore();
                        getline(cin, to_remove);
                        cout << endl;
                        to_do.remove_element(to_remove);                
                    }
                    else if(choice == 3)
                    {
                        to_do.display_list();
                    }
                    else if(choice == 4)
                    {
                        to_do.display_last_finished();
                    }
                    else if(choice == 5)
                    {
                        to_do.display_all_finished();
                    }
                    else if(choice == 0)
                    {
                        cout << "ENTER WHAT YOU WANT TO ACCESS : \n1-TO-DO LIST\n" << "2-TASKS FOR THE DAY\n" << "0-EXIT" << endl;
                        cin >> program;
                    }
                    else //if user enter a wrong number he can write the number again
                    {
                        cout << "You entered a wrong number plz enter a number between 0 and 5" << endl;
                        cin >> choice;
                        continue;
                    }
                    

                }
                if (program == 2) //task / status part
                {
                    cout << "CHOOSE WHAT TO DO: \n1-ADD TASK\n" << "2-REMOVE TASK\n" << "3-CHANGE STATUS OF A TASK\n" << "4-DISPLAY TASKS\n" << "0-EXIT" << endl;
                    cin >> choice;
                    
                    if(choice == 1)
                    {
                        string task;
                        string status;
                        cout << "Enter the task: ";
                        cin.ignore();
                        getline(cin, task);
                        cout << "\nEnter your status on your task: ";
                        cin.ignore();
                        getline(cin, status);
                        cout << endl;
                        Task.add_element(task, status);
                    }
                    else if(choice == 2)
                    {
                        string task_to_remove;
                        cout << "Enter the task to remove: ";
                        cin.ignore();
                        getline(cin, task_to_remove);                
                        Task.remove_elements(task_to_remove);
                    }
                    else if(choice == 3)
                    {
                        string task;
                        string changed_Status;
                        cout << "Enter the task which status you like to change: \n";
                        cin.ignore();
                        getline(cin, task);                        
                        cout << "What to you want to change your status to: \n";
                        cin.ignore();
                        getline(cin, changed_Status);
                        Task.change_status(task, changed_Status);
                    }
                    else if(choice == 4)
                    {
                        Task.display_elements();
                    }
                    else if(choice == 0)
                    {
                        cout << "ENTER WHAT YOU WANT TO ACCESS : \n1-TO-DO LIST\n" << "2-TASKS FOR THE DAY\n" << "0-EXIT" << endl;
                        cin >> program;
                    }
                    else
                    {
                        cout << "You entered a wrong number plz enter a number between 0 and 4" << endl;
                        cin >> choice;
                        continue;
                    }
                }
            }
            cout << "ENTER YOUR ROLE: \n1-DEVELOPER\n" << "2-MANAGER\n" << "0-EXIT PROGRAM" << endl;
            cin >> role;

        }
        if(role == 2) //manager part
        {
            cout << "WELCOME\n\n";
            cout << "ENTER WHAT YOU WOULD LIKE TO ACCESS: \n1-MEETINGS\n" << "2-CURRENTLY LOOGED IN EMPLOYEE TASKS\n" << "3-NAME OF EMPLOYEES THAT LOGGED IN TODAY\n" << "0-EXIT" << endl;
            cin >> program;

            while(program != 0) //loop until user enter 0 to exit
            {
                if (program == 1) //meetings part
                {
                    cout << "WHAT WOULD YOU LIKE TO DO: \n1-ADD MEETING(in the order that they will be taken today)\n" << "2-MARK THE CURRENT MEETING AS DONE\n" << "3-DISPLAY ALL MEETINGS\n" << "0-EXIT\n";
                    cin >> choice;

                    if (choice == 1)
                    {
                        string meetin_name;
                        cout << "write a title for the meeting to add\n";
                        cin.ignore();
                        getline(cin, meetin_name);
                        meeting.add_meeting(meetin_name);
                    }
                    else if (choice == 2)
                    {
                        meeting.delete_latest_meeting();
                    }
                    else if(choice == 3)
                    {
                        meeting.display_meetings();
                    }
                    else if (choice == 0)
                    {
                        cout << "ENTER WHAT YOU WOULD LIKE TO ACCESS: \n1-MEETINGS\n" << "2-EMPLOYEES TASKS\n" << "3-NAME OF EMPLOYEES THAT LOGGED IN TODAY\n" << "0-EXIT" << endl;
                        cin >> program;
                    }
                    else
                    {
                        cout << "You entered a wrong number plz enter a number between 0-3";
                        cin >> choice;
                        continue;
                    }
                
                }
                if (program == 2) //shows the current logged in developer's tasks that he is working on
                {
                    Task.display_elements();
                }
                if(program == 3) //display the name of all the developers that logged in
                {
                    for(string users : login_users)
                    {
                        cout << users << endl;
                    }
                }
            }
            cout << "ENTER YOUR ROLE: \n1-DEVELOPER\n" << "2-MANAGER\n" << "0-EXIT PROGRAM" << endl;
            cin >> role;
            
        }
    }
    
}