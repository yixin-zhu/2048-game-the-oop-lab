#include <bits/stdc++.h>
#include "gamemap.h"
#include "gamemap.cpp"
#include "player.h"
#include "player.cpp"
using namespace std;
const int BUFFLEN =1024;
char a[]="LiLei";
char b[]="HanMeimei";
char w[]="you";

void singlemode(gameMap* c)
{
    char buff[10001];
    player player1(w);
    while (fgets(buff, BUFFLEN, stdin))
    {
        buff[strlen(buff) - 1] = '\0';
        c->singleplay(buff,&player1);
        if (c->victory() == true)
        {
            printf("Congratulations! You win the game!\n");
            break;
        }
        if (c->defeat() == true)
        {
            printf("Sorry! You lose the game!\n");
            break;
        }
    }
}

void doublemode(gameMap* c)
{
    char buff[10001];
    player player1(a);
    player player2(b);
    player1.whatisyourname();
    player2.whatisyourname();
    printf("Let's begin the game!Please enter command.\n");

    while (fgets(buff, BUFFLEN, stdin))
    {
        buff[strlen(buff) - 1] = '\0';
        c->doubleplay(&player1,&player2,buff);
        if (c->victory() == true)
        {
            player1.fight(&player2);
            break;
        }
        if (c->defeat() == true)
        {
            player1.fight(&player2);
            break;
        }
    }
}

int main()
{
    gameMap mymap(4, 4, 2048);
    mymap.initial();
    switch(mymap.getmode())
    {
    case 1:
        singlemode(&mymap);
        break;
    case 2:
        doublemode(&mymap);
        break;
    }
    return 0;
}
