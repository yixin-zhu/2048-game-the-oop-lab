#include "Hostbase.h"
using namespace std;

Hostbase::Hostbase()
{
}

Hostbase::Hostbase(int mapSize)
{
    myMap = gameMap(mapSize, mapSize, 2048);
}

Hostbase::Hostbase(int mapSize, int playerNum)
{
    myMap = gameMap(mapSize, mapSize, 2048);
    playerNumber = playerNum;
}

int Hostbase::getMode() const
{
    return mode;
}

