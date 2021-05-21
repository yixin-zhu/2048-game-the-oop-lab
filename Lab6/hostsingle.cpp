#include <bits/stdc++.h>
#include "hostbase.h"
#include "hostsingle.h"
using namespace std;

hostsingle::hostsingle()
{
}

hostsingle::hostsingle(int mapSize)
{
    mymap = gameMap(mapSize, mapSize, 2048);
}

hostsingle::hostsingle(int mapSize, int playerNum)
{
    mymap = gameMap(mapSize, mapSize, 2048);
    playerNumber = playerNum;
}

void hostsingle::modeGame()
{
    mymap.initial();
    char buff[10001];
    player tempPlayer = player();
    players.push_back(tempPlayer);
    players[0].whatIsYourName();
    printf("Let's begin the game!Please enter command.\n");
    while (fgets(buff, BUFFLEN, stdin))
    {
        buff[strlen(buff) - 1] = '\0';
        playGame(buff);
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

void hostsingle::playGame(char *buff)
{
    mymap.flag = 0;
    switch (players[0].operates(buff))
    {
    case 1:
        mymap.setwins(64);
        printf("The game will end when there is a 64 block.\n");
        break;
    case 2:
    case 3:
    case 4:
    case 5:
        ("cls");
        players[0].addScore(mymap.go(players[0].operates(buff)));
        mymap.printMap();
        players[0].displayScore();
        break;
    default:;
        break;
    }
}
