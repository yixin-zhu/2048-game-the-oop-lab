#include "actionexecuter.h"
using namespace std;

ActionExecuter::ActionExecuter()
{
    
}

void ActionExecuter::executeAction(Action* a){
     for(auto o : observers) 
          o->actionAccepted(a);
     a->execute();
     for(auto o : observers) 
          o->actionPerformed(a);
}

void ActionExecuter::addObserver(ActionObserver* o)
{
    observers.push_back(o);
}

void ActionExecuter::removeObserver(ActionObserver* o)
{
    observers.erase(
        find(observers.begin(), observers.end(), o));
}