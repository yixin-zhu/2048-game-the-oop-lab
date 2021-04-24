#ifndef PLAYER_H
#define PLAYER_H
#include <bits/stdc++.h>
using namespace std;
class host;
class player
{
public:
    player();
    player(char* newName);
    friend host;
private:
    string name;
    int score;
    int sword;
    string getName()const;
    int getScore()const;
    void displayScore()const;
    void addScore( int t);
    int operates(char* buff)const;
    int operate(char* buff);
    void waittomove()const;
    void whatisyourname();
    static char cheatsentence[10001];
    void setSword(int num);
    int getSword()const;
    bool beingcheated;
};
    char player::cheatsentence[10001]={"\0"};
#endif

