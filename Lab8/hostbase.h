#ifndef HOSTBASE_H
#define HOSTBASE_H
#include <bits/stdc++.h>
#include "gamemap.h"
#include "player.h"
#include "log.h"
#include "bonus.h"
#include "record.h"
#include "undo.h"
#include "version.h"
using namespace std;
#define BUFFLEN 1024

class Hostbase 
{
public:
    Hostbase();
    Hostbase(int mapSize);
    Hostbase(int mapSize, int playerNumber);
    int playerNumber;
    Bonus myBonus;
    Log myLog;
    Version myVersion;
    Cheat myCheat;
    vector<Player> players;
    GameMap myMap;
    ActionExecuter myActionExecuter;
    virtual void modeGame() = 0; //虚函数r;

protected:
    bool askForUndo(Player* p);
    virtual void playGame(char *buff) = 0; //虚函数
};
#endif