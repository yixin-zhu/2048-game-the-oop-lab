#ifndef HOSTMULTI_H
#define HOSTMULTI_H
#include <bits/stdc++.h>
#include "player.h"
#include "gamemap.h"
#include "cheat.h"
#include "hostbase.h"

using namespace std;

class hostmulti : public hostbase
{
public:
    hostmulti();
    hostmulti(int mapSize);
    hostmulti(int mapSize, int playerNumber);
    void modeGame();

private:
    gameMap mymap;
    vector<player> players;
    cheat myCheat;
    int playerNumber;
    int mode;
    void modeSelect();
    void playGame(char *buff);
    void multiEndGame() const;
    int refreshPlayer() const;
};
#endif