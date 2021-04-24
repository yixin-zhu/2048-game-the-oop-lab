#ifndef HOST_H
#define HOST_H
#include <bits/stdc++.h>
#include "player.h"

using namespace std;

class host
{
public:
    host();
    host(int mapsize);
    void initial();
    void singlemode();
    void doublemode();
    int getmode()const;
private:
    gameMap mymap;
    player player1;
    player player2;
    int mode;
    bool curse;
    void setmode();
    void ModeSelect(int* x);
    void doubleplay(char* buff);
    void singleplay(char* buff);
    void endgame()const;
};
#endif
