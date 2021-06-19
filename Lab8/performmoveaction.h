#ifndef PERFORMMOVEACTION_H
#define PERFORMMOVEACTION_H
#include <bits/stdc++.h>
#include "player.h"
#include "gamemap.h"
#include "action.h"

using namespace std;

class PerformMoveAction : public Action
{
public:
    PerformMoveAction();
    PerformMoveAction(Player* p, GameMap* g, int dir);
    void execute();
    string getDetail();

private:
    int direction; //2 up 3 left 4 right 5 down 

};
#endif