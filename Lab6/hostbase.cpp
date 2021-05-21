#include <bits/stdc++.h>
#include "hostbase.h"
using namespace std;
const int BUFFLEN = 1024;

hostbase::hostbase()
{
}

hostbase::hostbase(int mapSize)
{
    mymap = gameMap(mapSize, mapSize, 2048);
}

hostbase::hostbase(int mapSize, int playerNum)
{
    mymap = gameMap(mapSize, mapSize, 2048);
    playerNumber = playerNum;
}

void hostbase::initial()
{
    mymap.initial();
}

int hostbase::getMode() const
{
    return mode;
}

