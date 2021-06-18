#ifndef ACTIONEXECUTER_H
#define ACTIONEXECUTER_H
#include <bits/stdc++.h>
#include "action.h"
#include "actionobserver.h"
using namespace std;

class ActionExecuter
{
public:
    ActionExecuter();
    vector<ActionObserver *> observers;
    void addObserver(ActionObserver *o);
    void removeObserver(ActionObserver *o);
    void executeAction(Action *a);

private:
};
#endif