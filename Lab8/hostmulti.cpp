#include "hostmulti.h"

Hostmulti::Hostmulti()
{
}
Hostmulti::~Hostmulti()
{
    // delete
}
Hostmulti::Hostmulti(int mapSize)
{
    myMap = GameMap(mapSize, mapSize, 2048);
}

Hostmulti::Hostmulti(int mapSize, int playerNum)
{
    myMap = GameMap(mapSize, mapSize, 2048);
    playerNumber = playerNum;
}

void Hostmulti::modeGame()
{
    myLog.clearLog();
    myMap.initial();
    myBonus.ae = &myActionExecuter;
    char buff[10001];
    playerNumber = 2; //这是暂时之计，今后可以简单实现两人以上多人游戏
    for (int i = 0; i < playerNumber; i++)
    {
        Player *tempPlayer = new Player();
        players.push_back(*tempPlayer);
        players[i].whatIsYourName();
    }
    printf("Let's begin the game!Please enter command.\n");
    fflush(stdin);
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
    myVersion.clearRecords();
}

void Hostmulti::playGame(char *buff)
{
    int playerID = refreshPlayer();
    Player *now = &players[playerID];
    if (buff[0] == 'c') //这是Cheat类的第一个插入处
    {
        if (myCheat.getCheatSentence(buff))
            cout << now->getName() << " is Cheating now!" << endl;
    }
    else
    {
        int direction = now->operates(buff);
        while (direction == -1)
        {
            puts("usless!Please enter again!");
            return;
        }
        PerformMoveAction myMove(now, &myMap, direction);
        myActionExecuter.executeAction(&myMove);
        myMap.printMap();
        myCheat.prepare(playerID); //Cheat类的第二个插入处
        now->displayScore();
        if (askForUndo(now)) //Undo 有关操作
        {
            Undo myUndo(now, &myMap);
            myActionExecuter.executeAction(&myUndo);
            now->displayScore();
        }
        else
        {
            playerID = refreshPlayer();
            now = &players[playerID];
            if (myMap.testFourDir() == 1) //Cheat类的第三个插入处
            {
                myCheat.tryToUseCheat(playerID, myMap.legalWords);
            }
        }
    }
    now->waitToMove();
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
