#ifndef UNDO_H
#define UNDO_H
#include <bits/stdc++.h>
#include "player.h"
#include "gamemap.h"
#include "action.h"

using namespace std;

class Undo : public Action
{
public:
    Undo();
    Undo(Player* p, GameMap* g);
    void execute();
    string getDetail();

private:
};
#endif
