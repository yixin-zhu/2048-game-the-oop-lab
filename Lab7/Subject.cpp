using namespace std;
#include "Subject.h"
#include <bits/stdc++.h>

Subject::Subject()
{
}

void Subject::addObserver(Observer *Observer)
{
    observers.push_back(Observer);
}

void Subject::removeObserver(Observer *Observer)
{
    observers.erase(
        find(observers.begin(), observers.end(), Observer));
}
