#include "undo.h"
using namespace std;

Undo::Undo()
{
    type=3;valid=1;
}

Undo::Undo(Player* newp, GameMap* newg)
{
    p=newp;
    g=newg;
    type=3;
    score=0;
}

void Undo::execute()
{   
    p->addScore(score);
}

string Undo::getDetail(){
    return "";
}