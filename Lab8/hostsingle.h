#ifndef HOSTSINGLE_H
#define HOSTSINGLE_H
#include <bits/stdc++.h>
#include "player.h"
#include "gamemap.h"
#include "hostbase.h"
#include "performmoveaction.h"
using namespace std;

class Hostsingle : public Hostbase
{
public:
    Hostsingle();
    Hostsingle(int mapSize);
    Hostsingle(int mapSize, int playerNumber);
    void modeGame();

private:
    void playGame(char *buff);
};
#endif