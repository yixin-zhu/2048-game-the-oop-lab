#include "record.h"

Record::Record()
{
}

Record::Record(Player *p, int newRecordScore, const GameMap &g)
{
    recordPlayer = p;
    recordScore = newRecordScore;
    recordMap = GameMap(g);
}
