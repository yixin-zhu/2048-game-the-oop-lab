#ifndef SUBJECT_H
#define SUBJECT_H
#include <bits/stdc++.h>
#include "Observer.h"
using namespace std;

class Subject
{
public:
    Subject();
    vector<Observer*> observers;
    void addObserver(Observer* Observer);
    void removeObserver(Observer *Observer);
    /* void notifyAllObservers(string s); */
private:
};


#endif
