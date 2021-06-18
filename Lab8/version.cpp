#include "version.h"
using namespace std;

Version::Version()
{
}

void Version::actionAccepted(Action *a)
{
    switch (a->type)
    {
    case 1:
    {
        Record *tempRecord = new Record(a->p, a->p->getScore(), *(a->g));
        records.push(tempRecord);
        int lastScore = records.top()->recordScore;
    }
    break;
    case 2:
        break;
    case 3:
        if (records.empty())
            return;
        int lastScore = records.top()->recordScore;
        a->score = lastScore - a->p->getScore();
        a->g->resetGameMap(records.top()->recordMap);
        Record *top = records.top();
        records.pop();
        delete top;
        break;
    }
}

void Version::actionPerformed(Action *a)
{
    switch (a->type)
    {
    case 1:
        if (a->g->flag==0)
        {
            Record *top = records.top();
            records.pop();
            delete top;
        }
        break;
    case 2:
        break;
    case 3:

        break;
    }
}
