#ifndef PLAYER_H
#define PLAYER_H
#include <bits/stdc++.h>
using namespace std;
class player
{
public:
    player();
    player(char *newName);
    void whatIsYourName();
    int operates(char *buff) const;
    int operate(char *buff) const;
    void celebrate() const;
    void displayScore() const;
    void addScore(int t);
    string getName() const;
    int getScore() const;
    void waitToMove() const;

private:
    string name;
    int score;
};
#endif
