#ifndef GAMEMAP_H
#define GAMEMAP_H
#include <bits/stdc++.h>
#include "Subject.h"
using namespace std;
#define MAXN 5

class gameMap : public Subject
{
public:
    gameMap();
    gameMap(int height, int width, int wins);
    void notifyAllObservers(string s);
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
    int dir;
    int newAddScore;
    int scoreInfo(string s);
    vector<char> legalWords;
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
