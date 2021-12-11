#include "guide.h"

using namespace std;

guide::guide() //constructor
{
    head = NULL;
    curr = NULL;
    next = NULL;
    last = this;

    ghead = NULL;
    gcurr = NULL;
    gnext = NULL;
    glast = this;

    x = 0;
    y = 0;
    fac = 0;

    facing = "North";
    WarriorStatus = "at ease";

}

guide::~guide()
{
    ///cout<<endl;
    ///cout<<"guide passed away"<<endl;
}

void guide::deleteg()
{
    glast = ghead;
    while (glast != NULL) {
        gcurr = glast->Getgnext();
        delete glast;
        glast = gcurr;
    }
}

void guide::addwarrior()
{
    last->Setnext(new warrior);
    last=last->Getnext();
    cout<<"warrior"<<endl;
}

void guide::Addrow()
{
    cout<<"how many warriors would you like to have in the each row?"<<endl;
    cin>>numwar;
    cout<<"how many rows would you like to have?"<<endl;
    cin>>numrow;

    for (int k=0; k<numwar-1; k++) {
        if (head == NULL) {
            head = new warrior;
            last = head;
        }
        else {
            curr = new warrior;
            last -> Setnext(curr);
            last = curr;
        }
        cout<<"warrior"<<endl;
    }

    for (i=0; i<numrow-1; i++){
        if (ghead==NULL) {
            ghead = new guide;
            glast = ghead;
        }
        else {
            gcurr = new guide;
            glast -> Setgnext(gcurr);
            glast = gcurr;
        }
        cout<<"guide"<<endl;
        for (int j=0; j<numwar-1; j++) {
            glast ->addwarrior();
        }
    }
}

void guide::atease()
{
    cout<<"Where would you like the head warrior to be located:"<<endl;

    cout<<"Type x coordinate"<<endl;
    cin>>xcor;
    Setx(xcor);

    cout<<"Type y coordinate"<<endl;
    cin>>ycor;
    Sety(ycor);

    cout<<"Where would you like the head warrior to face:"<<endl;
    cout<<"0 North"<<endl;
    cout<<"1 NorthEast"<<endl;
    cout<<"2 East"<<endl;
    cout<<"3 SouthEast"<<endl;
    cout<<"4 South"<<endl;
    cout<<"5 SouthWest"<<endl;
    cout<<"6 West"<<endl;
    cout<<"7 NorthWest"<<endl;
    cin>>fac;
    face();

    setg();
    Outputcor();
    counter++;
    attention();
}

void guide::attention()
{
    cout<<endl;
    cout<<"how many movements would you like to perform?"<<endl;
    cin>>nummove;

    for (i=0; i<nummove; i++) {
        momenu();
        int movem;
        cin>>movem;

        switch (movem) {
            case 1: {
                advance();
            } break;
            case 2: {
                hright();
            } break;
            case 3: {
                right();
            } break;
            case 4: {
                hleft();
            } break;
            case 5: {
                left();
            } break;
        }
    }
}

void guide::setg()
{
    cout<<"positioning warriors"<<endl;
    Setx(x);
    Sety(y);
    Setfacing(facing);
    SetWarriorStatus(WarriorStatus);
    Displaylist();
    last = head;
    int xval = x;
    while (last != NULL) {
        xval++;
        last->Setx(xval);
        last->Sety(y);
        last->Setfacing(facing);
        last->SetWarriorStatus(WarriorStatus);
        last->Displaylist();
        last = last->Getnext();
        cout<<endl;
    }
    int yval = y;
    yval--;
    glast = ghead;
    while (glast != NULL) {
        cout<<"-------------------------------------------------------"<<endl;
        glast->Setx(x);
        glast->Sety(yval);
        glast->Setfacing(facing);
        glast->SetWarriorStatus(WarriorStatus);
        glast->Displaylist();
        glast->setwar();
        glast = glast->Getgnext(); /// getting the next guide
        yval--; /// next guide is below the first
    }
}

void guide::setwar()
{
    last = next;
    int val = x;
    val++;
    while (next != NULL) {
        cout<<"-------------------------------------------------------"<<endl;
        next->Setx(val);
        val++;
        next->Sety(y);
        int tempx = next->Getx();
        int tempy = next->Gety();
        cout<<tempx<<"--"<<tempy<<endl<<"----------"<<endl;
        next->Setfacing(facing);
        next->SetWarriorStatus(WarriorStatus);
        next->Displaylist();
        next= next->Getnext();
        cout<<endl;
    } /// end of warrior linked list
    cout<<"-------------------------------------------------------"<<endl;
}

void guide::Outputcor()
{
    cout<<"file name -----------"<<fname<<"-----------"<<endl;
    temps = to_string(counter);
    fname = "MyData" + temps + ".dat";
    myfile.open(fname.c_str());
    myfile<<x<<" "<<y<<" "<<".25"<<endl;
    last = head;
    while (last != NULL) {
        int r = last->Getx();
        int e = last->Gety();
        cout<<"warrior values ------"<<r<<"-"<<e<<"-----------"<<endl;
        myfile<<r<<" "<<e<<" "<<".25"<<endl; /// ignore .25 it is for the purpose of other steps
        myfile<<endl;
        last = last->Getnext();
    }
    glast = ghead;
    while (glast != NULL) {
        myfile<<glast->Getx()<<" "<<glast->Gety()<<" "<<".25"<<endl; /// ignore .25 it is for the purpose of other steps
        glast->ocwar();
        myfile<<endl;
        glast = glast -> Getgnext();
    }
    myfile.close();
    counter++;
}

void guide::ocwar()
{
    temps = to_string(counter);
    fname = "MyData" + temps + ".dat";
    cout<<"file name -----------"<<fname<<"-----------"<<endl;
    myfile.open(fname.c_str(), ios_base::app);
    next = last;
    int g = 1;
    while (next != NULL) {
        cout<<"here"<<endl;
        int r = next->Getx();
        int e = next->Gety();
        cout<<"warrior values ------"<<r<<"-"<<e<<"-----------"<<endl;
        if (g==1) {
            myfile<<r<<" "<<e<<" "<<".25"<<endl; /// ignore .25 it is for the purpose of other steps
        }
        myfile<<r<<" "<<e<<" "<<".25"<<endl; /// ignore .25 it is for the purpose of other steps
        next= next->Getnext();
        g++;
    }
    myfile<<endl;
}

void guide::Outputcormov()
{
    index++;
    temps = to_string(index);
    fname = "MyData" + temps + ".dat";
    cout<<"file name -----------"<<fname<<"-----------"<<endl;
    myfile.open(fname.c_str());
    last = head;
    while (last != NULL) {
        int r = last->Getx();
        int e = last->Gety();
        cout<<"warrior values ------"<<r<<"-"<<e<<"-----------"<<endl;
        myfile<<r<<" "<<e<<" "<<".25"<<endl; /// ignore .25 it is for the purpose of other steps
        myfile<<endl;
        last = last->Getnext();
    }
    glast = ghead;
    while (glast != NULL) {
        int t = glast->Getx();
        int k = glast->Gety();
        cout<<"guide coordinates:        "<<t<<"-"<<k<<endl;
        myfile<<t<<" "<<k<<" "<<".25"<<endl; /// ignore .25 it is for the purpose of other steps
        glast->ocwarmov();
        myfile<<endl;
        glast = glast -> Getgnext();
    }
    myfile.close();
}

void guide::ocwarmov()
{
    ofstream output;
    counter++;
    temps = to_string(counter);
    fname = "MyData" + temps + ".dat";
    cout<<"file name -----------"<<fname<<"-----------"<<endl;
    output.open(fname.c_str(), ios_base::app);
    next = last;
    int g = 1;
    while (next != NULL) {
        cout<<"here"<<endl;
        int r = next->Getx();
        int e = next->Gety();
        cout<<"warrior x value ------"<<r<<"-"<<e<<"-----------"<<endl;
        if (g==1) {
            output<<r<<" "<<e<<" "<<".25"<<endl; /// ignore .25 it is for the purpose of other steps
        }
        output<<r<<" "<<e<<" "<<".25"<<endl; /// ignore .25 it is for the purpose of other steps
        next= next->Getnext();
        g++;
    }
    output<<endl;
}

void guide::advance()
{
    Advance();
    last = head;
    while (last != NULL) {
        last -> Advance();
        last = last -> Getnext();
    }
    glast = ghead;
    while (glast != NULL) {
        cout<<"-------------------------------------------------------"<<endl;
        glast->Advance();
        glast->Displaylist();
        glast->waradvance();
        glast = glast->Getgnext(); /// getting the next guide
    }
    ///outputting coordinates
    Outputcormov();
}

void guide::waradvance()
{
    next = last;
    while (next != NULL) {
        cout<<"-------------------------------------------------------"<<endl;
        next->Advance();
        next->Displaylist();
        next= next->Getnext();
        cout<<endl;
    } /// end of warrior linked list
    cout<<"-------------------------------------------------------"<<endl;
}

void guide::right()
{
    Right();
    last = head;
    while (last != NULL) {
        last -> Right();
        last = last -> Getnext();
    }
    glast = ghead;
    while (glast != NULL) {
        cout<<"-------------------------------------------------------"<<endl;
        glast->Right();
        glast->Displaylist();
        glast->wright();
        glast = glast->Getgnext(); /// getting the next guide
    }
    ///outputting coordinates
    Outputcormov();
}

void guide::wright()
{
    next = last;
    while (next != NULL) {
        cout<<"-------------------------------------------------------"<<endl;
        next->Right();
        next->Displaylist();
        next= next->Getnext();
        cout<<endl;
    } /// end of warrior linked list
    cout<<"-------------------------------------------------------"<<endl;
}

void guide::hright()
{
    HRight();
    last = head;
    while (last != NULL) {
        last -> HRight();
        last = last -> Getnext();
    }
    glast = ghead;
    while (glast != NULL) {
        cout<<"-------------------------------------------------------"<<endl;
        glast->HRight();
        glast->Displaylist();
        glast->whright();
        glast = glast->Getgnext(); /// getting the next guide
    }
    ///outputting coordinates
    Outputcormov();
}

void guide::whright()
{
    next = last;
    while (next != NULL) {
        cout<<"-------------------------------------------------------"<<endl;
        next->HRight();
        next->Displaylist();
        next= next->Getnext();
        cout<<endl;
    } /// end of warrior linked list
    cout<<"-------------------------------------------------------"<<endl;
}

void guide::left()
{
    Left();
    last = head;
    while (last != NULL) {
        last -> Left();
        last = last -> Getnext();
    }
    glast = ghead;
    while (glast != NULL) {
        cout<<"-------------------------------------------------------"<<endl;
        glast->Left();
        glast->Displaylist();
        glast->wleft();
        glast = glast->Getgnext(); /// getting the next guide
    }
    ///outputting coordinates
    Outputcormov();
}

void guide::wleft()
{
    next = last;
    while (next != NULL) {
        cout<<"-------------------------------------------------------"<<endl;
        next->Left();
        next->Displaylist();
        next= next->Getnext();
        cout<<endl;
    } /// end of warrior linked list
    cout<<"-------------------------------------------------------"<<endl;
}

void guide::hleft()
{
    HLeft();
    last = head;
    while (last != NULL) {
        last -> HLeft();
        last = last -> Getnext();
    }
    glast = ghead;
    while (glast != NULL) {
        cout<<"-------------------------------------------------------"<<endl;
        glast->HLeft();
        glast->Displaylist();
        glast->whleft();
        glast = glast->Getgnext(); /// getting the next guide
    }
    ///outputting coordinates
    Outputcormov();
}

void guide::whleft()
{
    next = last;
    while (next != NULL) {
        cout<<"-------------------------------------------------------"<<endl;
        next->HLeft();
        next->Displaylist();
        next= next->Getnext();
        cout<<endl;
    } /// end of warrior linked list
    cout<<"-------------------------------------------------------"<<endl;
}
