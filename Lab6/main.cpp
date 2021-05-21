#include <bits/stdc++.h>
//#include "player.h"
#include "player.cpp"
//#include "gamemap.h"
#include "gamemap.cpp"
//#include "hostbase.h"
#include "hostbase.cpp"
//#include "hostmulti.h"
#include "hostmulti.cpp"
//#include "hostsingle.h"
#include "hostsingle.cpp"
//#include "cheat.h"
#include "cheat.cpp"
//#include "simulation.h"
#include "simulation.cpp"
//#include "instream.h"
#include "instream.cpp"
#define SIZEMODE "-s"
#define SIMULATIONMODE "-i"
using namespace std;

int getMapSize(int argc, char *argv[])
{
    int mapSize = 4;
    if ((argc > 1) && !(strcmp(argv[1], SIZEMODE)))
    {
        mapSize = atoi(argv[2]);
        if (mapSize != 2 && mapSize != 3 && mapSize != 4 && mapSize != 5)
        {
            printf("Invalid parameter!Please enter again.\n");
            return 0;
        }
    }
    return mapSize;
}

int main(int argc, char *argv[])
{
    if ((argc > 1) && !(strcmp(argv[1], SIMULATIONMODE))) //此处应当是唯一的simulation类调用处
    {
        simulation mySimulation;
        mySimulation.simulate(argv);
    }
    else
    {
        int mapSize = getMapSize(argc, argv);
        if (!mapSize)
        {
            return 0;
        }
        instream myInstream;
        hostsingle mySingleHost(mapSize);
        hostmulti myMultiHost(mapSize);
        hostbase *myHost;
        switch (myInstream.modeSelect())
        {
        case 1:
            myHost = &mySingleHost;
            break;
        case 2:
            myHost = &myMultiHost;
            break;
        default:
            printf("Invalid mode!");
            break;
        }
    myHost->modeGame();
    }
return 0;
}
