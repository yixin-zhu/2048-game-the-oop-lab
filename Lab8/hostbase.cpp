#include "hostbase.h"
using namespace std;

Hostbase::Hostbase()
{
}

Hostbase::Hostbase(int mapSize)
{
    myMap = GameMap(mapSize, mapSize, 2048);
}

Hostbase::Hostbase(int mapSize, int playerNum)
{
    myMap = GameMap(mapSize, mapSize, 2048);
    playerNumber = playerNum;
}

bool Hostbase::askForUndo(Player *p)
{
    string a;
    if (p->undoChance > 0)
    {
        cout << "You have " << p->undoChance << " undo chance left. Do you want to undo? Enter y if you agree." << endl;
        cout << "If there is no previous situation to go back , you will waste your chance!" << endl;
        cin >> a;
        fflush(stdin);
        if (a.length() == 1 && a[0] == 'y')
        {
            p->undoChance -= 1;
            return true;
        }
        else
            return false;
    }
    return false;
}

