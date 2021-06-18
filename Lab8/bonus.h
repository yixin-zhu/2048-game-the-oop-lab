#ifndef BONUS_H
#define BONUS_H
#include <bits/stdc++.h>
#include <windows.h>
#include <sys/time.h>
#include "action.h"
#include "actionobserver.h"
#include "actionexecuter.h"
#include "obtainbonusaction.h"
using namespace std;

class Bonus  : public ActionObserver
{
public:
    Bonus();
    void refreshTimeDifference();
    double getTimeDifference();
    double timeDifference;
    struct timeval lastTime;
    void actionAccepted(Action *a);
    void actionPerformed(Action* a);
    ActionExecuter* ae;
private:
   
    
};
#endif