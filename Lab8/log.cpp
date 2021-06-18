#include "log.h"
using namespace std;

Log::Log()
{
}

string Log::getLogTime()
{
    time_t rawtime;
    struct tm *info;
    char buffer[80];
    time(&rawtime);
    info = localtime(&rawtime);
    strftime(buffer, 80, "%Y/%m/%d/%H:%M:%S", info);
    return buffer;
}

void Log::clearLog()
{
    ofstream afile;
    afile.open("log.txt", ios::trunc);
    afile.close();
}

void Log::actionAccepted(Action *a)
{
    switch (a->type)
    {
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    }
}

void Log::actionPerformed(Action *a)
{
    ofstream afile;
    afile.open("log.txt", ios::app);
    string timeBuffer = getLogTime();
    switch (a->type)
    {
    case 1:
        if (a->score > 0)
            afile << "Move Score:" << a->p->getName() << " " << timeBuffer << " " << a->getDetail() << " " << a->score << endl;
        break;
    case 2:
        afile << "Bonus Score:" << a->p->getName() << " " << timeBuffer << " " << a->getDetail() << " " << a->score << endl;
        break;
    case 3:
        afile << "Undo Deduct Score:" << a->p->getName() << " " << timeBuffer << " " << a->getDetail() << " " << a->score << endl;
        break;
    }
    afile.close();
}
