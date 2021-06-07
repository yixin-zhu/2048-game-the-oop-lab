#ifndef HOSTMULTI_H
#define HOSTMULTI_H
#include <bits/stdc++.h>
#include "Player.h"
#include "Gamemap.h"
#include "Cheat.h"
#include "Log.h"
#include "Hostbase.h"

using namespace std;

class Hostmulti : public Hostbase
{
public:
    Hostmulti();
    Hostmulti(int mapSize);
    Hostmulti(int mapSize, int playerNumber);
    void modeGame();
    void modeInitial();
    void initial();
private:
    gameMap myMap;
    vector<Player> players;
    Cheat myCheat;
    int playerNumber;
    int mode;
    void modeSelect();
    void playGame(char *buff);
    void multiEndGame() const;
    int refreshPlayer() const;
};
#endif