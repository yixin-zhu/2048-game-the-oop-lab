#include <bits/stdc++.h>
#include "action.cpp"
#include "actionexecuter.cpp"
#include "actionobserver.cpp"
#include "bonus.cpp"
#include "cheat.cpp"
#include "gamemap.cpp"
#include "hostbase.cpp"
#include "hostmulti.cpp"
#include "hostsingle.cpp"
#include "instream.cpp"
#include "log.cpp"
#include "obtainbonusaction.cpp"
#include "performmoveaction.cpp"
#include "player.cpp"
#include "record.cpp"
#include "simulation.cpp"
#include "undo.cpp"
#include "version.cpp"
#define SIZEMODE "-s"
#define SIMULATIONMODEINPUT "-i"
#define SIMULATIONMODEOUTPUT "-o"
#define EASYMODE "-t"
#define LOGMODE "-log"
#define BONUSMODE "-p"
using namespace std;

int main(int argc, char *argv[])
{
    for (int i = 0; i < argc; i++)
    {
        if (!(strcmp(argv[i], SIMULATIONMODEINPUT)))
        {   
            Simulation mySimulation;
            mySimulation.simulate(argv);
            return 0;
        }
    }
    int mapSize = 4, logMode = 0, bonusMode = 0, easyMode = 0;
    for (int i = 0; i < argc; i++)
    {
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
        if (!(strcmp(argv[i], EASYMODE)))
        {
            easyMode = 1;
        }
    }
    Instream myInstream;
    Hostmulti myMultiHost(mapSize);
    Hostsingle mySingleHost(mapSize);
    Hostbase *myHost = nullptr;
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
        myHost->myActionExecuter.addObserver(&(myHost->myBonus));
    }
    if (logMode)
    {
        myHost->myActionExecuter.addObserver(&(myHost->myLog));
    }
    if (easyMode)
    {
        myHost->myMap.setwins(64);
    }
    myHost->myActionExecuter.addObserver(&(myHost->myVersion));
    myHost->modeGame();
    return 0;
}
