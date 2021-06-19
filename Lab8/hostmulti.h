#ifndef HOSTMULTI_H
#define HOSTMULTI_H
#include <bits/stdc++.h>
#include "player.h"
#include "gamemap.h"
#include "hostbase.h"
#include "performmoveaction.h"
using namespace std;

class Hostmulti : public Hostbase
{
public:
    Hostmulti();
    ~Hostmulti();
    Hostmulti(int mapSize);
    Hostmulti(int mapSize, int playerNumber);
    void modeGame();

private:
    void playGame(char *buff);
    void multiEndGame() const;
    int refreshPlayer() const;
};
#endif