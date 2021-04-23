#ifndef GAMEMAP_H
#define GAMEMAP_H
#include <bits/stdc++.h>
#include "player.h"
using namespace std;
#define MAXN 5
class host;
class gameMap
{
public:
    gameMap();
    gameMap(int height, int width, int wins);
    gameMap(const gameMap& obj);
    friend host;
private:
    int height;
    int width;
    int wins;
    int round;
    int cheatingnow;
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
    void initial();
    int flag;
    void setwins(int win);
    int getround()const;
    void begincheat();
    int getcheatingnow()const;
    int go(int x);
    bool victory() const;
    bool defeat() const;
    int onlyone();
    int a[MAXN][MAXN];
    char onlyword;
};
#endif
