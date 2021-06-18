#include <bits/stdc++.h>
#include "player.h"
using namespace std;
map<string, int> q = {{"-t", 1}, {"w", 2}, {"a", 3}, {"s", 4}, {"z", 5}};
const int UNDOCHANCE = 3;

Player::Player()
{
    score = 0;
    undoChance = UNDOCHANCE;
}

Player::Player(const string &newName)
{
    name = newName;
    score = 0;
    undoChance = UNDOCHANCE;
}

string Player::getName() const
{
    return name;
}

int Player::getScore() const
{
    return score;
}

void Player::addScore(int num)
{
    score += num;
}

void Player::displayScore() const
{
    cout << "Current score of " << name << " is " << score << endl;
}

int Player::operates(char *buff) const
{
    int branch = 0;
    auto it = q.find(buff);
    if (it == q.end())
        return -1;
    branch = it->second;
    return branch;
}

int Player::operate(char *buff) const
{
    int branch = 0;
    auto it = q.find(buff);
    branch = it->second;
    return branch;
}

void Player::waitToMove() const
{
    cout << name << " to move now! " << endl;
}

void Player::setName(string givenName)
{
    name = givenName;
}

void Player::whatIsYourName()
{
    printf("Please enter a Player's name.\n");
    cin >> name;
    cout << "my name is " << name << endl;
}

void Player::celebrate() const
{
    cout << name << " wins the game! " << endl;
}