#ifndef BONUS_H
#define BONUS_H
#include <bits/stdc++.h>
#include <windows.h>
#include <windows.h>
#include <sys/time.h>
#include "Subject.h"
using namespace std;

class Bonus  : public Subject
{
public:
    Bonus();
    int bonusInfo(string s);
    int bonusStage; // 0奖励模式没开动  1奖励模式开动
    void refreshTimeDifference();
    double getTimeDifference();
    double timeDifference;
    struct timeval lastTime;
    void notifyAllObservers(string s);
private:
   
    
};
#endif