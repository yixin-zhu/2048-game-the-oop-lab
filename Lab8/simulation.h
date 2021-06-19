#ifndef SIMULATION_H
#define SIMULATIONT_H
#include <bits/stdc++.h>
#include "Gamemap.h"
using namespace std;
#define MAXN 5


class Simulation
{
public:
    Simulation();
    void simulate(char *argv[]);
private:
    void readIn(char *argv[]);
    void playSimulation(char *argv[]);
    int convert(char* buff)const;
    int randomNumber=2;
    GameMap simulationMap;
    char command[1001];
};


#endif