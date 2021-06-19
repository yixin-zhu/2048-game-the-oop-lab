#ifndef PLAYER_H
#define PLAYER_H
#include <bits/stdc++.h>
using namespace std;
class Player
{
public:
    Player();
    Player(const string& newName);
    void setName(string name);
    void whatIsYourName();
    int operates(char *buff) const;
    int operate(char *buff) const;
    void celebrate() const;
    void displayScore() const;
    void addScore(int t);
    string getName() const;
    int getScore() const;
    void waitToMove() const;
    int undoChance;
private:
    string name;
    int score;


    
};
#endif
