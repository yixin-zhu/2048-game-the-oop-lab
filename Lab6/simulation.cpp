#include <bits/stdc++.h>
#include "simulation.h"
using namespace std;
map<string, int> p = { {"w", 2}, {"a", 3}, {"s", 4}, {"z", 5}};

simulation::simulation()
{
}

void simulation::simulate(char *argv[])
{
    readIn(argv);
    playSimulation(argv);
}

void simulation::readIn(char *argv[])
{
    int mapSize;
    FILE *fp;
    fp = fopen(argv[2], "r");
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

void simulation::playSimulation(char* argv[])
{
    freopen(argv[4], "w", stdout);
    printf("%d ",simulationMap.testFourDir());
    for (int i = 0; i < simulationMap.legalWords.size(); i++)
    {
        printf("%c ",simulationMap.legalWords[i]);
    } 
    printf("\n");
    int newScore=simulationMap.goWithoutRefresh(convert(command));
    simulationMap.printMapWithoutWall();
    printf("%d\n",randomNumber);
    for (int i = 0; i < simulationMap.getRandomNumberPlace().size(); i++)
    {
        printf("%d ",simulationMap.getRandomNumberPlace()[i]);
    } 
    printf("\n");
    printf("%d",newScore);
    fclose(stdout);
}

int simulation::convert(char* buff) const
{
    int branch = 0;
    auto it = p.find(buff);
    branch = it->second;
    return branch;
}