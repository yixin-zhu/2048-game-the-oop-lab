#ifndef HOST_H
#define HOST_H
#include <bits/stdc++.h>
#include "player.h"
#include "cheat.h"

using namespace std;

class host
{
public:
    host();
    host(int mapSize);
    host(int mapSize, int playerNumber);
    void initial();
    void singleMode();
    void multiMode();
    int getMode() const;

private:
    gameMap mymap;
    vector<player> players;
    cheat myCheat;
    int playerNumber;
    int mode;
    bool curse;
    void setmode();
    void modeSelect();
    void multiPlay(char *buff);
    void singlePlay(char *buff);
    void multiEndGame() const;
    int refreshPlayer() const;
};
#endif
