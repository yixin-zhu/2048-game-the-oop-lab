#include <bits/stdc++.h>
//#include "player.h"
#include "host.h"
using namespace std;
const int BUFFLEN =1024;

host::host()
{
    mymap= gameMap(4,4,2048);
}

host::host(int mapsize)
{
    mymap= gameMap(mapsize,mapsize,2048);
    player1= player();
    player2= player();
}

void host::initial()
{
    ModeSelect(&mode);
    mymap.initial();
}

void host::singlemode()
{
    char buff[10001];
    player1.whatisyourname();
    printf("Let's begin the game!Please enter command.\n");
    while (fgets(buff, BUFFLEN, stdin))
    {
        buff[strlen(buff) - 1] = '\0';
        singleplay(buff);
        if (mymap.victory() == true)
        {
            printf("Congratulations! You win the game!\n");
            break;
        }
        if (mymap.defeat() == true)
        {
            printf("Sorry! You lose the game!\n");
            break;
        }
    }
}

void host::doublemode()
{
    char buff[10001];
    player1.whatisyourname();
    player2.whatisyourname();
    printf("Let's begin the game!Please enter command.\n");
    while (fgets(buff, BUFFLEN, stdin))
    {
        buff[strlen(buff) - 1] = '\0';
        doubleplay(buff);
        if (mymap.victory() == true)
        {
            endgame();
            break;
        }
        if (mymap.defeat() == true)
        {
            endgame();
            break;
        }
    }
}

int host::getmode()const
{
    return mode;
}

void host::ModeSelect(int *x)
{
    printf("Please select game mode \n");
    printf("1:Single Player Mode\n");
    printf("2:Double Player Mode\n");
    scanf("%d", x);
}

void host::doubleplay(char *buff)
{
    player *selection[2] = {&player1, &player2};
    player *now = selection[mymap.getround() % 2];
    mymap.flag = 0;
    static bool curse=false;
    int used=0;
    switch (now->operate(buff))
    {
    case 1:
        mymap.setwins(64);
        printf("The game will end when there is a 64 block.\n");
        break;
    case 2:
    case 3:
    case 4:
    case 5:
        system("cls");
        now->addScore(mymap.go(now->operate(buff)));
        now->displayScore();
        if(now->getSword()&&used==1)
        {
            used=2;
        }
        if(now->getSword())
        {
            curse=true;
        }
        now = selection[mymap.getround() % 2];
        if(curse&&now->getSword()==0)
            now->beingcheated=true;
        if(now->beingcheated)
        {
            if(curse&&mymap.onlyone()&&(used==0||used==1))
            {
                printf("%s If you agree,please enter %c \n",now->cheatsentence,mymap.onlyword);
                used=1;
            }
        }
        now->waittomove();
        break;
    default:
        ;
        break;
    }
}

void host::singleplay(char *buff)
{
    mymap.flag = 0;
    switch (player1.operates(buff))
    {
    case 1:
        mymap.setwins(64);
        printf("The game will end when there is a 64 block.\n");
        break;
    case 2:
    case 3:
    case 4:
    case 5:
        system("cls");
        player1.addScore(mymap.go(player1.operates(buff)));
        player1.displayScore();
        break;
    default:
        ;
        break;
    }
}

void host::endgame()const
{
    if((player1.getScore())>(player2.getScore()))
        printf("%s wins the game! \n",player1.name);
    else if ((player1.getScore())<(player2.getScore()))
        printf("%s wins the game! \n",player2.name);
    else
        printf("The game is draw!");
}
