#include <bits/stdc++.h>
//#include "player.h"
#include "player.cpp"
//#include "gamemap.h"
#include "gamemap.cpp"
//#include "host.h"
#include "host.cpp"
//#include "cheat.h"
#include "cheat.cpp"
#define SIZEMODE "-s"
using namespace std;

int getMapSize(int argc, char *argv[])
{
    int mapSize = 4;
    if (argc != 1)
    {
        if (!(strcmp(argv[1], SIZEMODE)))
        {
            mapSize = atoi(argv[2]);
            if (mapSize != 2 && mapSize != 3 && mapSize != 4 && mapSize != 5)
            {
                printf("Invalid parameter!Please enter again.\n");
                return 0;
            }
        }
    }
    return mapSize;
}

int main(int argc, char *argv[])
{
    int mapSize = getMapSize(argc, argv);
    if (!mapSize)
        return 0;
    int playerNumber = 2;
    host myHost(mapSize, playerNumber);
    myHost.initial();
    switch (myHost.getMode())
    {
    case 1:
        myHost.singleMode();
        break;
    case 2:
        myHost.multiMode();
        break;
    default:
        printf("Invalid mode!");
    }
    return 0;
}
