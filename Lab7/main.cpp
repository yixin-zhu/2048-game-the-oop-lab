#include <bits/stdc++.h>
#include "Gamemap.h"
#include "Hostbase.h"
#include "Hostmulti.h"
#include "Hostsingle.h"
#include "Simulation.h"
#include "Instream.h"
#include "Log.h"
#include "Bonus.h"
#define SIZEMODE "-s"
#define SIMULATIONMODEINPUT "-i"
#define SIMULATIONMODEOUTPUT "-o"
#define LOGMODE "-log"
#define BONUSMODE "-p"
using namespace std;

int main(int argc, char *argv[])
{
    int mapSize = 4, logMode = 0, bonusMode = 0;
    for (int i = 0; i < argc; i++)
    {
        if (!(strcmp(argv[i], SIMULATIONMODEINPUT)))
        {
            Simulation mySimulation;
            mySimulation.simulate(argv);
            break;
        }
        if (!(strcmp(argv[i], SIZEMODE)))
        {
            mapSize = atoi(argv[i + 1]);
            if (mapSize != 2 && mapSize != 3 && mapSize != 4 && mapSize != 5)
            {
                printf("Invalid parameter!Please enter parameters again.\n");
                return 0;
            }
        }
        if (!(strcmp(argv[i], LOGMODE)))
        {
            logMode = 1;
        }
        if (!(strcmp(argv[i], BONUSMODE)))
        {
            bonusMode = 1;
        }
    }
    Instream myInstream;
    Hostsingle mySingleHost(mapSize);
    Hostmulti myMultiHost(mapSize);
    Hostbase *myHost = nullptr;
    Log observerLog;
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
    if (bonusMode)
    {
        myHost->bonusMode = 1;
        if (logMode)
            myHost->myBonus.addObserver(&observerLog);
    }
    if (logMode)
    {
        myHost->logMode = 1;
    }
    myHost->modeGame();
    return 0;
}
