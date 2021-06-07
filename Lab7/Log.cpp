#include <bits/stdc++.h>
#include "Log.h"
using namespace std;
map<int, string> directions = {{2, "up"}, {3, "left"}, {4, "right"}, {5, "down"}};

Log::Log()
{
}

string Log::getLogTime()
{
    time_t rawtime;
    struct tm *info;
    char buffer[80];
    time(&rawtime);
    info = localtime(&rawtime);
    strftime(buffer, 80, "%Y/%m/%d/%H:%M:%S", info);
    return buffer;
}

void Log::clearLog()
{
    ofstream afile;
    afile.open("log.txt", ios::trunc);
    afile.close();
}

void Log::update(string playerName, gameMap *g)
{   
    ofstream afile;
    afile.open("log.txt", ios::app);
    string timeBuffer = getLogTime();
    afile << "Move Score:" << playerName << " " << timeBuffer << " " << directions[g->dir] << " " << g->newAddScore << endl;
    afile.close();
}

void Log::response(string playerName, Bonus *b)
{
    ofstream afile;
    afile.open("log.txt", ios::app);
    string timeBuffer = getLogTime();
    if (b->timeDifference < 1.000000)
        afile << "Bonus Score:" << playerName << " " << timeBuffer << " " << setprecision(1) << b->timeDifference << " "
              << "1" << endl;
    afile.close();
}