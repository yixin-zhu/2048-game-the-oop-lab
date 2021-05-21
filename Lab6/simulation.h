#ifndef SIMULATION_H
#define SIMULATIONT_H
#include <bits/stdc++.h>
#include "gamemap.h"
using namespace std;
#define MAXN 5


class simulation
{
public:
    simulation();
    gameMap simulationMap;
    char command[1001];
    void simulate(char *argv[]);
    void readIn(char *argv[]);
    void playSimulation(char *argv[]);
    int randomNumber=2;
private:
    int convert(char* buff)const;
};

#endif