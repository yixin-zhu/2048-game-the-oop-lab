#ifndef LOG_H
#define LOG_H
#include <bits/stdc++.h>
#include <windows.h>
#include <sys/time.h>
#include "actionobserver.h"
#include "gamemap.h"
#include "bonus.h"
#include "action.h"
#include "performmoveaction.h"
#include "obtainbonusaction.h"
using namespace std;

class Log : public ActionObserver
{
public:
    Log();
    string getLogTime();
    void clearLog();
    void update(string playerName, GameMap *g);
    void response(string playerName, Bonus *b);
    void actionAccepted(Action *a);
    void actionPerformed(Action *a);

private:
};
#endif