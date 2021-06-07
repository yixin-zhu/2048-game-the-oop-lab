#include <bits/stdc++.h>
#include "Hostbase.h"
#include "Hostmulti.h"
using namespace std;

Hostmulti::Hostmulti()
{ 
    logMode=0;
    bonusMode=0;
}

Hostmulti::Hostmulti(int mapSize)
{
    myMap = gameMap(mapSize, mapSize, 2048);
    logMode=0;
    bonusMode=0;
}

Hostmulti::Hostmulti(int mapSize, int playerNum)
{
    myMap = gameMap(mapSize, mapSize, 2048);
    playerNumber = playerNum;
    logMode=0;
    bonusMode=0;
}

void Hostmulti::modeGame()
{
    Log kkLog;
    kkLog.clearLog();
    if (logMode){
        myMap.addObserver(kkLog.thisp());
    }
     myMap.initial();
    char buff[10001];
    playerNumber = 2; //修改本句可以实现多人游戏
    for (int i = 0; i < playerNumber; i++)
    {
        Player tempPlayer = Player();
        players.push_back(tempPlayer);
        players[i].whatIsYourName();
    }
    printf("Let's begin the game!Please enter command.\n");
    while (fgets(buff, BUFFLEN, stdin))
    {
        buff[strlen(buff) - 1] = '\0';
        playGame(buff);
        if (myMap.victory() == true || myMap.defeat() == true)
        {
            multiEndGame();
            break;
        }
    }
}

void Hostmulti::playGame(char *buff)
{
    int playerID = refreshPlayer();
    int newBonusScore = 1;
    Player *now = &players[playerID];
    myMap.flag = 0;
    if (buff[0] == 'c') //这是Cheat类的第一个插入处
    {
        if (myCheat.getCheatSentence(buff))
            cout << now->getName() << " is Cheating now!" << endl;
    }
    else
    {
        switch (now->operate(buff))
        {
        case 1:
            myMap.setwins(64);
            printf("The game will end when there is a 64 block.\n");
            break;
        case 2:
        case 3:
        case 4:
        case 5:
            myMap.dir = now->operate(buff);
            myMap.newAddScore = myMap.go(myMap.dir);
            now->addScore(myMap.scoreInfo(now->getName()));
            if (myMap.flag&&bonusMode)
                now->addScore(myBonus.bonusInfo(now->getName()));
            myMap.printMap();
            now->displayScore();
            myCheat.prepare(playerID); //Cheat类的第二个插入处
            playerID = refreshPlayer();
            now = &players[playerID];
            if (myMap.testFourDir() == 1) //Cheat类的第三个插入处
            {
                myCheat.tryToUseCheat(playerID, myMap.legalWords);
            }
            now->waitToMove();
            break;
        default:;
            break;
        }
    }
}

int Hostmulti::refreshPlayer() const
{
    return myMap.getround() % playerNumber;
}

void Hostmulti::multiEndGame() const
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

void Hostmulti::initial()
{
    myMap.initial();
}
