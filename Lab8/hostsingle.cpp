#include "hostsingle.h"
using namespace std;

Hostsingle::Hostsingle()
{
}

Hostsingle::Hostsingle(int mapSize)
{
    myMap = GameMap(mapSize, mapSize, 2048);
}

Hostsingle::Hostsingle(int mapSize, int playerNum)
{
    myMap = GameMap(mapSize, mapSize, 2048);
    playerNumber = playerNum;
}

void Hostsingle::modeGame()
{
    myLog.clearLog();
    myMap.initial();
    myBonus.ae = &myActionExecuter;
    char buff[10001];
    Player tempPlayer = Player();
    players.push_back(tempPlayer);
    players[0].setName("Default Player");
    printf("Let's begin the game!Please enter command.\n");
    fflush(stdin);
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
    int direction = players[0].operates(buff);
    while (direction == -1)
    {
        puts("usless!Please enter again!");
        return;
    }
    PerformMoveAction myMove(&players[0], &myMap, players[0].operates(buff));
    myActionExecuter.executeAction(&myMove);
    myMap.printMap();
    players[0].displayScore();
    while (askForUndo(&players[0])) //Undo 有关操作
    {
        Undo myUndo(&players[0], &myMap);
        myActionExecuter.executeAction(&myUndo);
        players[0].displayScore();
    }
}
