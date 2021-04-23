#include <bits/stdc++.h>
#include "player.h"
using namespace std;
map<string,int> q={{"-t",1},{"w",2},{"a",3},{"s",4},{"z",5}};

player::player( )
{
    score=0;
    setSword(0);
    beingcheated=false;
}

player::player(char* newName)
{
    name = newName;
    score=0;
    setSword(0);
    beingcheated=false;
}

string player::getName()const
{
    return  name;
}

int player::getScore()const
{
    return score;
}

int player::getSword()const
{
    return sword;
}

void player::setSword(int num)
{
    sword=num;
}

void player::addScore(int num)
{
    (score) += num;
}

void player::displayScore()const
{
    printf("Current score of %s  is %d \n\n",name,score);
}


int player::operates(char* buff)const
{
    int branch = 0;
    auto  it= q.find(buff);
    branch = it->second;
    return branch;
}

int player::operate(char* buff)
{
    int branch = 0;
    int k=0,t=0;
    if(buff[0]=='c')
    {
        if(getSword()==0&&beingcheated==false)
        {
            k++;
            while(buff[k]==' '||buff[k]=='\t')
                k++;
            while(buff[k]!='\0')
                cheatsentence[t++]=buff[k++];
            cheatsentence[t]='\0';
            printf("%s is cheating now! command parameter:%s\n",name,cheatsentence);
            setSword(1);
        }
    }
    else{auto  it= q.find(buff);
    branch = it->second;}
    return branch;
}

void player::waittomove()const
{
    printf("%s to move now! \n",name);
}

void player::whatisyourname()
{
    printf("Please enter a player's name.\n");
    scanf("%s",name);
}

