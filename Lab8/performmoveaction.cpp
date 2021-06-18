#include "performmoveaction.h"
using namespace std;
map<int, string> directions = {{2, "up"}, {3, "left"}, {4, "right"}, {5, "down"}};

PerformMoveAction::PerformMoveAction()
{
    type=1;
    valid=0;
}

PerformMoveAction::PerformMoveAction(Player* newp, GameMap* newg, int dir)
{
    p=newp;
    g=newg;
    type=1;
    score=0;
    direction=dir;
}

void PerformMoveAction::execute()
{  
    score=g->go(direction);
    valid=g->flag;
    p->addScore(score);
}

string PerformMoveAction::getDetail(){
    return directions[direction];
}