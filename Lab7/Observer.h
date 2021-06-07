#ifndef OBSERVER_H
#define OBSERVER_H
#include <bits/stdc++.h>
using namespace std;

class Bonus;
class gameMap;
class Observer
{
public:
    Observer();
    virtual void response(string s, Bonus* b)=0;
    virtual void update(string s, gameMap* h)=0;
    Observer* thisp();
private:
    
};

#endif