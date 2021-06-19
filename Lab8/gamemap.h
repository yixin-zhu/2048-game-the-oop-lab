#ifndef GAMEMAP_H
#define GAMEMAP_H
#include <bits/stdc++.h>
using namespace std;
#define MAXN 5

class GameMap 
{
public:
    GameMap();
    GameMap(int height, int width, int wins);
    GameMap(const GameMap& g);
    void resetGameMap(const GameMap& g);
    void printMap() const;
    void printMapWithoutWall() const;
    void initial();
    bool victory() const;
    bool defeat() const;
    void setwins(int win);
    int getround() const;
    int go(int x);
    int goWithoutRefresh(int x);
    int testFourDir() ;
    int flag;
    string legalWords;
    int a[MAXN][MAXN];
    vector<int> getRandomNumberPlace(); 

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
    int goup();
    int goleft();
    int goright();
    int godown();
};
#endif
