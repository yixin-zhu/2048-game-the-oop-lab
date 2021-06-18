#include <bits/stdc++.h>
#include "instream.h"
using namespace std;

Instream::Instream()
{
}

int Instream::modeSelect()
{
    int mode;
    printf("Please select game mode \n");
    printf("1:Single Player Mode\n");
    printf("2:Multi Player Mode\n");
    scanf("%d", &mode);
    return mode;
}
