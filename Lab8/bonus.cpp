#include "bonus.h"
Bonus::Bonus()
{
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

double Bonus::getTimeDifference()
{
    return timeDifference;
}

void Bonus::actionAccepted(Action *a)
{
    switch (a->type)
    {
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    }
}

void Bonus::actionPerformed(Action *a)
{
    switch(a->type)
    {
    case 1:
        if (a->valid)
        {
            refreshTimeDifference();
            if (timeDifference < 1.00000)
            {
                ObtainBonusAction b(a->p, timeDifference);
                ae->executeAction(&b);
            }
        }
        break;
    }
}
