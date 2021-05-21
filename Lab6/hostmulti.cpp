#include <bits/stdc++.h>
#include "hostbase.h"
#include "hostmulti.h"
using namespace std;

hostmulti::hostmulti()
{
}

hostmulti::hostmulti(int mapSize)
{
    mymap = gameMap(mapSize, mapSize, 2048);
}

hostmulti::hostmulti(int mapSize, int playerNum)
{
    mymap = gameMap(mapSize, mapSize, 2048);
    playerNumber = playerNum;
}

void hostmulti::modeGame()
{
    mymap.initial();
    char buff[10001];
    playerNumber = 2;
    for (int i = 0; i < playerNumber; i++)
    {
        player tempPlayer = player();
        players.push_back(tempPlayer);
        players[i].whatIsYourName();
    }
    printf("Let's begin the game!Please enter command.\n");
    while (fgets(buff, BUFFLEN, stdin))
    {
        buff[strlen(buff) - 1] = '\0';
        playGame(buff);
        if (mymap.victory() == true || mymap.defeat() == true)
        {
            multiEndGame();
            break;
        }
    }
}

void hostmulti::playGame(char *buff)
{
    int playerID = refreshPlayer();
    player *now = &players[playerID];
    mymap.flag = 0;
    if (buff[0] == 'c') //这是cheat类的第一个插入处
    {
        if (myCheat.getCheatSentence(buff))
            cout << now->getName() << " is cheating now!" << endl;
    }
    else
    {
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
            now->addScore(mymap.go(now->operate(buff)));
            mymap.printMap();
            now->displayScore();
            myCheat.prepare(playerID); //插入处
            playerID = refreshPlayer();
            now = &players[playerID];
            if (mymap.testFourDir() == 1) //又一个插入处
            {
                myCheat.tryToUseCheat(playerID, mymap.legalWords);
            }
            now->waitToMove();
            break;
        default:;
            break;
        }
    }
}

int hostmulti::refreshPlayer() const
{
    return mymap.getround() % playerNumber;
}

void hostmulti::multiEndGame() const
{
    vector<int> winnerIDs;
    int maxScore = -1;
    for (int i = 0; i < playerNumber; i++)
    {
        if (players[i].getScore() > maxScore)
        {
            while (!winnerIDs.empty())
                winnerIDs.pop_back();
            winnerIDs.push_back(i);
            maxScore = players[i].getScore();
        }
        else if (players[i].getScore() == maxScore)
            winnerIDs.push_back(i);
    }
    for (int i = 0; i < winnerIDs.size(); i++)
    {
        players[winnerIDs[i]].celebrate();
    }
}
