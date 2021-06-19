#ifndef VERSION_H
#define VERSION_H
#include <bits/stdc++.h>
#include "actionobserver.h"
#include "record.h"
using namespace std;
class Version : public ActionObserver
{
public:
    Version();
    Version(int newID, int newLastScore, const GameMap &g);   
    void actionAccepted(Action *a);
    void actionPerformed(Action *a);
    void clearRecords();
private:
    stack<Record*> records;
};
#endif