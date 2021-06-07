#include <bits/stdc++.h>
#include "Simulation.h"
using namespace std;
map<string, int> p = {{"w", 2}, {"a", 3}, {"s", 4}, {"z", 5}};

Simulation::Simulation()
{
}

void Simulation::simulate(char *argv[])
{
    readIn(argv);
    playSimulation(argv);
}

void Simulation::readIn(char *argv[])
{
    int mapSize;
    int i = 1;
    FILE *fp;
    while (!strcmp(argv[i], "-i"))
        i++;
    fp = fopen(argv[i + 1], "r");
    fscanf(fp, "%d", &mapSize);
    simulationMap = gameMap(mapSize, mapSize, 2048);
    for (int i = 0; i < mapSize; i++)
    {
        for (int j = 0; j < mapSize; j++)
        {
            fscanf(fp, "%d", &simulationMap.a[i][j]);
        }
    }
    fscanf(fp, "%s", command);
    fclose(fp);
}

void Simulation::playSimulation(char *argv[])
{
    int i = 1;
    while (!strcmp(argv[i], "-o"))
        i++;
    freopen(argv[i + 1], "w", stdout);
    printf("%d ", simulationMap.testFourDir());
    for (int i = 0; i < simulationMap.legalWords.size(); i++)
    {
        printf("%c ", simulationMap.legalWords[i]);
    }
    printf("\n");
    int newScore = simulationMap.goWithoutRefresh(convert(command));
    simulationMap.printMapWithoutWall();
    printf("%d\n", randomNumber);
    for (int i = 0; i < simulationMap.getRandomNumberPlace().size(); i++)
    {
        printf("%d ", simulationMap.getRandomNumberPlace()[i]);
    }
    printf("\n");
    printf("%d", newScore);
    fclose(stdout);
}

int Simulation::convert(char *buff) const
{
    int branch = 0;
    auto it = p.find(buff);
    branch = it->second;
    return branch;
}