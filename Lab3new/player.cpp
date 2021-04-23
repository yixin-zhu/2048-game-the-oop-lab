#include <bits/stdc++.h>
#include "player.h"
using namespace std;
#define UP "w"
#define LEFT "a"
#define RIGHT "s"
#define DOWN "z"
#define EASY "-t"

player::player(char* newName)
{
    name = newName;
    score=0;
}

string player::getName()const
{
    return  name;
}

int player::getScore()const
{
    return score;
}

void player::addScore(int num)
{
    (score) += num;
}

void player::fight(player* b)const
{
    if((getScore())>(b->getScore()))
        celebrate();
    else if ((getScore())<(b->getScore()))
        b->celebrate();
    else
        printf("The game is draw!");
}

void player::displayScore()const
{
    printf("Current score of %s  is %d \n\n",name,score);
}

void player::celebrate()const
{
    printf("%s wins the game! \n",name);
}

int player::operate(char* buff)const
{
    int branch = 0;
    if (!strcmp(buff, EASY))
        branch = 1;
    if (!strcmp(buff, UP))
        branch = 2;
    if (!strcmp(buff, LEFT))
        branch = 3;
    if (!strcmp(buff, RIGHT))
        branch = 4;
    if (!strcmp(buff, DOWN))
        branch = 5;
    return branch;
}

void player::waittomove()const
{
    printf("%s to move now! \n",name);
}

void player::whatisyourname()
{
    printf("请输入一个玩家的名字\n");
    scanf("%s",name);
}

