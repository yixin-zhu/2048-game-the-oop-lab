#include "obtainbonusaction.h"
using namespace std;

ObtainBonusAction::ObtainBonusAction()
{
    type=2;
    valid=1;
}

ObtainBonusAction::ObtainBonusAction(Player *newp, double newT)
{
    p = newp;
    timeDifference = newT;
    type=2;
}

void ObtainBonusAction::execute()
{
    score = 1;
    p->addScore(score);
}

string ObtainBonusAction::getDetail(){
    string s="0.";
    s+=char(int(10*timeDifference+48));
    return s;
}