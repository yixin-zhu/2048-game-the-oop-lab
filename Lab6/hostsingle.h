#ifndef HOSTSINGLE_H
#define HOSTSINGLE_H
#include <bits/stdc++.h>
#include "player.h"
#include "gamemap.h"
#include "cheat.h"
#include "hostbase.h"

using namespace std;

class hostsingle : public hostbase
{
public:
    hostsingle();
    hostsingle(int mapSize);
    hostsingle(int mapSize, int playerNumber);
    void modeGame();

private:
    gameMap mymap;
    vector<player> players;
    cheat myCheat;
    int playerNumber;
    int mode;
    void modeSelect();
    void playGame(char *buff);
};
#endif