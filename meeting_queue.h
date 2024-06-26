#ifndef meeting_queue
#define meeting_queue

#include <queue>
#include <string>
using namespace std;

class Meeting
{
    private:
        queue<string> meetings;
    
    public:
        void add_meeting(string);
        void delete_latest_meeting();
        void display_meetings();
};

#endif

/*this is a simple class that represents a queue in which the manager adds the meetings he have in a day
in the order that he has those meetings and then delete the first meeting in that queue and display all the meetings he have left*/