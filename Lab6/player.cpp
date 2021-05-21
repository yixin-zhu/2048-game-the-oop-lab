#include <bits/stdc++.h>
#include "player.h"
using namespace std;
map<string, int> q = {{"-t", 1}, {"w", 2}, {"a", 3}, {"s", 4}, {"z", 5}};

player::player()
{
    score = 0;
}

player::player(char *newName)
{
    name = newName;
    score = 0;
}

string player::getName() const
{
    return name;
}

int player::getScore() const
{
    return score;
}

void player::addScore(int num)
{
    (score) += num;
}

void player::displayScore() const
{
    cout << "Current score of " << name << " is " << score << endl;
}

int player::operates(char *buff) const
{
    int branch = 0;
    auto it = q.find(buff);
    branch = it->second;
    return branch;
}

int player::operate(char *buff) const
{
    int branch = 0;
    auto it = q.find(buff);
    branch = it->second;
    return branch;
}

void player::waitToMove() const
{
    cout << name << " to move now! " << endl;
}

void player::whatIsYourName()
{
    printf("Please enter a player's name.\n");
    cin >> name;
    cout << "my name is " << name << endl;
}

void player::celebrate() const
{
    cout << name << " wins the game! " << endl;
}