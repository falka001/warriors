#ifndef WARRIOR_
#define WARRIOR_
#include <string>
#include <fstream>
#include <sstream> //string stream

using namespace std;

class warrior
{
    public:
        warrior();
        virtual ~warrior();

        int Getx() { return x; };
        void Setx(int val) { x = val; };

        int Gety() { return y; };
        void Sety(int val) { y = val; };

        string Getfacing() { return facing; };
        void Setfacing(string val) { facing = val; };

        string GetWarriorStatus() { return WarriorStatus; };
        void SetWarriorStatus(string val) { WarriorStatus = val; };

        warrior * Getnext() { return next; };
        void Setnext(warrior * val) { next = val; };

        void face();

        void Advance();

        void Right();

        void HRight();

        void Left();

        void HLeft();

        void mmenu();

        void momenu();

        void Displaylist();

    protected:
        int x;
        int y;
        int fac;
        int nummove;
        int stattype;
        int counter=1;
        warrior * next;
        string facing;
        string WarriorStatus;
        string status;
};

#endif // WARRIOR_
