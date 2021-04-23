#ifndef HOST_H
#define HOST_H
#include <bits/stdc++.h>
#include "gamemap.h"
using namespace std;

class player
{
public:
    player();
    player(char* newName);
    string getName()const;
    int getScore()const;
    void displayScore()const;
    void addScore( int t);
    void fight(player* b)const;
    int operate(char* buff)const;
    void waittomove()const;
    void whatisyourname();
private:
    char* name;
    int score;
    void celebrate()const;
};
#endif

