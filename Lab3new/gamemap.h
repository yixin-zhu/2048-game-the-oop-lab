#ifndef GAMEMAP_H
#define GAMEMAP_H
#include <bits/stdc++.h>
#include "player.h"
using namespace std;
#define MAXN 4

class gameMap
{
public:
    gameMap();
    gameMap(int height, int width, int wins);
    int flag;
    void initial();
    void setwins(int win);
    int getmode()const;
    void setmode();
    int getround()const;
    int go(int x);
    bool victory() const;
    bool defeat() const;
    int a[MAXN][MAXN];
    void doubleplay(player* a,player* b,char* buff);
    void singleplay(char* buff,player* r);
private:
    int height;
    int width;
    int wins;
    int mode;
    int round;
    void printmap() const;
    int getremain() const;
    void roundadd(int t);
    void getRandomNumber();
    void clearmap();
    void printHelp();
    void ModeSelect(int* x);
    int goup();
    int goleft();
    int goright();
    int godown();
};
#endif
