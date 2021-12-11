#ifndef ROW_
#define ROW_

#include "warrior.h"
#include <string>
#include <iostream>

using namespace std;

class guide: public warrior
{
    public:
        guide();
        virtual ~guide();

        warrior * Gethead() { return head; };
        void Sethead(warrior * val) { head = val; };

        warrior * Getcurr() { return curr; };
        void Setcurr(warrior * val) { curr = val; };

        guide * Getgnext() { return gnext; };
        void Setgnext(guide * val) { gnext = val; };

        void Addrow();

        void addwarrior();

        void deleteg();

        void deletew();

        void atease();

        void attention();

        void setg();

        void setwar();

        void Display();

        void Displaywar();

        void ocwar();

        void ocwarmov();

        void Outputcor();

        void Outputcormov();

        void advance();

        void waradvance();

        void right();

        void wright();

        void hright();

        void whright();

        void left();

        void wleft();

        void hleft();

        void whleft();

    protected:
        warrior * head;
        warrior * curr;
        warrior * last;
        guide * gnext;
        guide * ghead;
        guide * gcurr;
        guide * glast;

        ofstream myfile;
        string fname;
        string temps;

        int index=1;
        int nrows;
        int xcor;
        int ycor;
        int numwar;
        int numrow;
        int i;
        int iter;
};

#endif // ROW_
