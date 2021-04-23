#include <bits/stdc++.h>
//#include "player.h"
#include "player.cpp"
//#include "gamemap.h"
#include "gamemap.cpp"
//#include "host.h"
#include "host.cpp"
#define SIZEMODE "-s"
using namespace std;

int main(int argc, char* argv[])
{
    int mapsize=4;
    if(argc!=1)
    {
        if(!(strcmp(argv[1],SIZEMODE)))
        {
            mapsize= atoi(argv[2]);
            if(mapsize!=2&&mapsize!=3&&mapsize!=4&&mapsize!=5)
            {
                printf("invalid parameter!Please enter again.\n");
                return 0;
            }
        }
    }
    host myhost(mapsize);
    myhost.initial();
    switch(myhost.getmode())
    {
    case 1:
        myhost.singlemode();
        break;
    case 2:
        myhost.doublemode();
        break;
    }
    return 0;
}
