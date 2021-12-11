#include <iostream>
#include <string>
#include <cstdlib> /// system()
#include <sstream> /// to_string()
#include <ctime>
#include "guide.h"

using namespace std;

int main()
{
    guide phalanx;

    int stattype;
    string status;

    phalanx.Addrow();

    phalanx.mmenu();
    cin>>stattype;

    if (stattype==0) {
        phalanx.setg();
        phalanx.Outputcor();
    }
    else if (stattype==1) {
        status = "at ease";
        phalanx.SetWarriorStatus(status);
        phalanx.atease();
    }

    else if (stattype==2) {
        status = "at attention";
        phalanx.SetWarriorStatus(status);
        phalanx.setg();
        phalanx.Outputcor();
        phalanx.attention();
    }

    fstream fout1; /// data
    fstream fout2; /// gnuplot

    /// dynamic name
    string pngfile;
    string target2;
    string index;

    /// making the command file that gnuplot needs
    fout1.open("command.txt", ios::out);
    fout1<<"set xlabel \"X-Coordinate\""<<endl;
    fout1<<"set ylabel \"Y-Coordinate\""<<endl;
    fout1<<"set xrange [-20:20]"<<endl;
    fout1<<"set yrange [-20:20]"<<endl;
    fout1<<"set terminal png"<<endl;

    for (int i=1; i<21; i++) {
        index = to_string(i);
        target2 = "MyData" + index + ".dat";
        pngfile = "output" + index + ".png";
        fout1<<"set output\'"<<pngfile<<"\'"<<endl;
        fout1<<"plot \'"<<target2<<"\' with circles linecolor rgb \"#9ACD32\" fill solid noborder"<<endl;
    }
    fout1<<"pause -1"<<endl;
    fout1.close();
    system("gnuplot command.txt");

    ///phalanx.deleteg();

    return 0;
}
