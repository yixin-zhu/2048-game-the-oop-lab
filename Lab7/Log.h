#ifndef LOG_H
#define LOG_H
#include <bits/stdc++.h>
#include "Observer.h"
#include "Gamemap.h"
#include "Bonus.h"
using namespace std;

class Log : public Observer
{
public:
    Log();
    string getLogTime();
    void clearLog();
    void update(string playerName,gameMap* g);
    void response(string playerName,Bonus* b);

private:
   
    
};
#endif