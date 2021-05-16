#include <bits/stdc++.h>
//#include "player.h"
#include "host.h"
using namespace std;
const int BUFFLEN = 1024;

host::host()
{
    mymap = gameMap(4, 4, 2048);
}

host::host(int mapSize, int playerNum)
{
    mymap = gameMap(mapSize, mapSize, 2048);
    for (int i = 1; i <= playerNumber; i++)
    {
        player tempPlayer = player();
        players.push_back(tempPlayer);
    }
    playerNumber = playerNum;
}

void host::initial()
{
    modeSelect();
    mymap.initial();
}

int host::getMode() const
{
    return mode;
}

void host::singleMode()
{
    char buff[10001];
    players[1].whatIsYourName();
    printf("Let's begin the game!Please enter command.\n");
    while (fgets(buff, BUFFLEN, stdin))
    {
        buff[strlen(buff) - 1] = '\0';
        singlePlay(buff);
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

void host::multiMode()
{
    char buff[10001];
    for (int i = 0; i < playerNumber; i++)
    {
        players[i].whatIsYourName();
    }
    printf("Let's begin the game!Please enter command.\n");
    while (fgets(buff, BUFFLEN, stdin))
    {
        buff[strlen(buff) - 1] = '\0';
        multiPlay(buff);
        if (mymap.victory() == true || mymap.defeat() == true)
        {
            multiEndGame();
            break;
        }
    }
}

void host::modeSelect()
{
    printf("Please select game mode \n");
    printf("1:Single Player Mode\n");
    printf("2:Multi Player Mode\n");
    scanf("%d", &mode);
}

int host::refreshPlayer() const
{
    return mymap.getround() % playerNumber;
}

void host::multiPlay(char *buff)
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
            system("cls");
            now->addScore(mymap.go(now->operate(buff)));
            mymap.printMap();
            now->displayScore();
            myCheat.prepare(playerID); //插入处
            playerID = refreshPlayer();
            now = &players[playerID];
            if (mymap.onlyOne()) //又一个插入处
            {
                myCheat.tryToUseCheat(playerID, mymap.onlyWord);
            }
            now->waitToMove();
            break;
        default:;
            break;
        }
    }
}

void host::singlePlay(char *buff)
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
        system("cls");
        players[0].addScore(mymap.go(players[0].operates(buff)));
        mymap.printMap();
        players[0].displayScore();
        break;
    default:;
        break;
    }
}

void host::multiEndGame() const
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
