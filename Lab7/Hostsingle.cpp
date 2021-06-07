#include <bits/stdc++.h>
#include "Hostbase.h"
#include "Hostsingle.h"
using namespace std;

Hostsingle::Hostsingle()
{
    logMode=0;
    bonusMode=0;
}

Hostsingle::Hostsingle(int mapSize)
{
    myMap = gameMap(mapSize, mapSize, 2048);
    logMode=0;
    bonusMode=0;
}

Hostsingle::Hostsingle(int mapSize, int playerNum)
{
    myMap = gameMap(mapSize, mapSize, 2048);
    playerNumber = playerNum;
    logMode=0;
    bonusMode=0;
}

void Hostsingle::modeGame()
{
    Log kkLog;
    kkLog.clearLog();
    if (logMode)
        myMap.addObserver(kkLog.thisp());
    myMap.initial();
    char buff[10001];
    Player tempPlayer = Player();
    players.push_back(tempPlayer);
    players[0].setName("Default Player");
    printf("Let's begin the game!Please enter command.\n");
    while (fgets(buff, BUFFLEN, stdin))
    {
        buff[strlen(buff) - 1] = '\0';
        playGame(buff);
        if (myMap.victory() == true)
        {
            printf("Congratulations! You win the game!\n");
            break;
        }
        if (myMap.defeat() == true)
        {
            printf("Sorry! You lose the game!\n");
            break;
        }
    }
}

void Hostsingle::playGame(char *buff)
{
    int newBonusScore = 1;
    myMap.flag = 0;
    switch (players[0].operates(buff))
    {
    case 1:
        myMap.setwins(64);
        printf("The game will end when there is a 64 block.\n");
        break;
    case 2:
    case 3:
    case 4:
    case 5:
        myMap.dir = players[0].operate(buff);
        myMap.newAddScore = myMap.go(myMap.dir);
        players[0].addScore(myMap.scoreInfo(players[0].getName()));
        if (myMap.flag && bonusMode)
            players[0].addScore(myBonus.bonusInfo(players[0].getName()));
        myMap.printMap();
        players[0].displayScore();
        break;
    default:;
        break;
    }
}

void Hostsingle::initial()
{
    Log myLog;
    myLog.clearLog();
    if (logMode)
        myMap.addObserver(myLog.thisp());
    if (bonusMode&&logMode)
        myBonus.addObserver(myLog.thisp());
    myMap.initial();
    myMap.printMap();
}