#ifndef RECORD_H
#define RECORD_H
#include <bits/stdc++.h>
#include "gamemap.h"
#include "player.h"
using namespace std;
class Record
{
public:
    Record();
    Record(Player* p, int newRecordScore,const GameMap& g );
    Player* recordPlayer;
    int recordScore;
    GameMap recordMap;
private:
    
};
#endif