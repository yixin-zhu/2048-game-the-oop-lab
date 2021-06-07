#include "Bonus.h"
Bonus::Bonus()
{
    bonusStage = 0;
}

double calculateTimeDifference(struct timeval *last, struct timeval *now)
{
    double time1, time2, timeDif;
    time1 = last->tv_sec + (last->tv_usec / 1000000.0);
    time2 = now->tv_sec + (now->tv_usec / 1000000.0);
    timeDif = time1 - time2;
    return timeDif;
}

void Bonus::refreshTimeDifference()
{
    struct timeval currentTime;
    gettimeofday(&currentTime, NULL);
    timeDifference = calculateTimeDifference(&currentTime, &lastTime);
    lastTime = currentTime;
}

int Bonus::bonusInfo(string s)
{
    refreshTimeDifference();
    if (timeDifference < 1.00000)
    {
        notifyAllObservers(s);
        return 1;
    }
    return 0;
}

double Bonus::getTimeDifference()
{
    return timeDifference;
}

void Bonus::notifyAllObservers(string s)
{   
    for (auto ob : observers)
    {   
        ob->response(s, this);
    }
}
