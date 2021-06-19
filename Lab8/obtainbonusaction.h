#ifndef OBTAINBONUSSACTION_H
#define OBTAINBONUSSACTION_H
#include <bits/stdc++.h>
#include "player.h"
#include "gamemap.h"
#include "action.h"

using namespace std;

class ObtainBonusAction :  public Action
{
public:
    ObtainBonusAction();
    ObtainBonusAction(Player* p, double timeDifference); 
    void execute();
    string getDetail();
private:
    double timeDifference;
};
#endif