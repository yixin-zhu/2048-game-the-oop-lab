#ifndef HOSTBASE_H
#define HOSTBASE_H
#include <bits/stdc++.h>
#include "Player.h"
#include "Gamemap.h"
#include "Cheat.h"
#include "Log.h"
#include "Bonus.h"
using namespace std;
#define BUFFLEN 1024

class Hostbase 
{
public:
    Hostbase();
    Hostbase(int mapSize);
    Hostbase(int mapSize, int playerNumber);
    int getMode() const;         //继承
    virtual void modeGame() = 0; //虚函数
    Bonus myBonus;
    gameMap myMap;
    int logMode;
    int bonusMode;
    
private:
    vector<Player> players;
    Cheat myCheat;
    int playerNumber;
    int mode;
    virtual void playGame(char *buff) = 0; //虚函数
};
#endif