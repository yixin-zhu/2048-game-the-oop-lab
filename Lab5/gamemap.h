#ifndef GAMEMAP_H
#define GAMEMAP_H
#include <bits/stdc++.h>
#include "player.h"
using namespace std;
#define MAXN 5
class gameMap
{
public:
    gameMap();
    gameMap(int height, int width, int wins);
    gameMap(const gameMap &obj);
    void printMap() const;
    void initial();
    bool victory() const;
    bool defeat() const;
    void setwins(int win);
    int getround() const;
    int go(int x);
    int onlyOne() ;
    int flag;
    char onlyWord;

private:
    int height;
    int width;
    int wins;
    int round;
    int getRemain() const;
    void roundAdd(int t);
    void getRandomNumber();
    void clearMap();
    void printHelp() const;
    void modeSelect(int *x);
    int goup();
    int goleft();
    int goright();
    int godown();
    int a[MAXN][MAXN];
};
#endif
