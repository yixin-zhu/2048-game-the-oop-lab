#ifndef ACTIONOBSERVER_H
#define ACTIONOBSERVER_H
#include <bits/stdc++.h>
#include "action.h"
using namespace std;

class ActionObserver
{
public:
    ActionObserver();
    virtual void actionAccepted(Action *a)=0;
    virtual void actionPerformed(Action *a)=0;

private:
};

#endif