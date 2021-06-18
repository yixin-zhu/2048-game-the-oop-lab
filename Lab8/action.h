#ifndef ACTION_H
#define ACTION_H
#include <bits/stdc++.h>
#include "gamemap.h"
#include "player.h"
using namespace std;

class Action
{
public:
    Action();
    Player* p;
    GameMap* g;
    int score;
    int type;  //1 移动 2 奖励 3 悔棋
    virtual void execute()=0;
    virtual string getDetail()=0;
    bool valid;
private:

};


#endif
