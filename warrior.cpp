#include "warrior.h"
#include <iostream>
#include <fstream>
#include <sstream> //string stream


warrior::warrior() //constructor
{
    next = NULL;

    x = 0;
    y = 0;
    fac = 0;

    facing = "North";
    WarriorStatus = "at ease";
}

warrior::~warrior() //destructor
{
    ///cout<<endl;
    ///cout<<"warrior passed away"<<endl;
    if (next != NULL) {
        delete next;
    }
}

void warrior::face()
{
    if (fac==0) {facing="North";}
    if (fac==1) {facing="NorthEast";}
    if (fac==2) {facing="East";}
    if (fac==3) {facing="SouthEast";}
    if (fac==4) {facing="South";}
    if (fac==5) {facing="SouthWest";}
    if (fac==6) {facing="West";}
    if (fac==7) {facing="NorthWest";}
    Setfacing(facing);
}

void warrior::mmenu()
{

    cout<<"What would you like the status of the warriors to be:"<<endl;
    cout<<"Type 0 to view default coordinates, facing, and warrior status; then exit"<<endl;
    cout<<"Type 1 for (at ease) or 2 for (at attention using default), then control warriors"<<endl;

}

void warrior::momenu()
{
    cout<<"Movement Options:"<<endl;
    cout<<"1 Advance"<<endl;
    cout<<"2 Turn Half-Right and Advance"<<endl;
    cout<<"3 Turn Right and Advance"<<endl;
    cout<<"4 Turn Half-Left and Advance"<<endl;
    cout<<"5 Turn Left and Advance"<<endl;
    cout<<"press any key to exit"<<endl;
}

void warrior::Advance()
{
    face();
    cout<<endl;
    switch (fac){
        case 0: {y++;} break;
        case 1: {x++; y++;} break;
        case 2: {x++;} break;
        case 3: {x++, y--;} break;
        case 4: {y--;} break;
        case 5: {x--; y--;} break;
        case 6: {x--;} break;
        case 7: {x--; y++;} break;
    }
}

void warrior::HRight()
{
    face();
    cout<<endl;
    fac++;
    if (fac==8) {fac=0;}
    if (fac==-1) {fac=7;}
    face();
    Advance();
}

void warrior::Right()
{
    face();
    cout<<endl;
    fac++;
    fac++;
    if (fac==8) {fac=0;}
    if (fac==-1) {fac=7;}
    face();
    Advance();
}

void warrior::HLeft()
{
    face();
    cout<<endl;
    fac--;
    if (fac==8) {fac=0;}
    if (fac==-1) {fac=7;}
    face();
    Advance();
}

void warrior::Left()
{
    face();
    cout<<endl;
    fac--;
    fac--;
    if (fac==8) {fac=0;}
    if (fac==-1) {fac=7;}
    face();
    Advance();
}

void warrior::Displaylist()
{
    cout<<endl;
    cout<<"warrior is "<<WarriorStatus<<endl;
    cout<<"warrior is facing "<<facing<<endl;
    cout<<"warrior is located at ("<<x<<","<<y<<")"<<endl;
}
