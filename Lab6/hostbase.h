#ifndef HOSTBASE_H
#define HOSTBASE_H
#include <bits/stdc++.h>
#include "player.h"
#include "gamemap.h"
#include "cheat.h"
using namespace std;

class hostbase
{
public:
    hostbase();
    hostbase(int mapSize);
    hostbase(int mapSize, int playerNumber);
    void initial();//继承
    int getMode() const; //继承
    virtual void modeGame()=0;  //虚函数

private:
    gameMap mymap; 
    vector<player> players;
    cheat myCheat;
    int playerNumber; 
    int mode;
    virtual void playGame(char *buff)=0;//虚函数
    
};
#endif