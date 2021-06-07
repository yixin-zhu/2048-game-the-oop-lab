#ifndef HOSTSINGLE_H
#define HOSTSINGLE_H
#include <bits/stdc++.h>
#include "Player.h"
#include "Gamemap.h"
#include "Cheat.h"
#include "Log.h"
#include "Hostbase.h"
using namespace std;

class Hostsingle : public Hostbase
{
public:
    Hostsingle();
    Hostsingle(int mapSize);
    Hostsingle(int mapSize, int playerNumber);
    void modeGame();
    void initial();

private:
    gameMap myMap;
    vector<Player> players;
    Cheat myCheat;
    int playerNumber;
    int mode;
    void modeSelect();
    void playGame(char *buff);
};
#endif