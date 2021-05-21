#include <bits/stdc++.h>
#include "cheat.h"
using namespace std;

cheat::cheat()
{
    cheaterID = -1;
    curse = 0;
    cheatStage = 0;
}

int cheat::getCheatSentence(char *buff)
{
    int k = 0, t = 0, valid = 0;
    if (curse == 0)
    {
        k++;
        while (buff[k] == ' ' || buff[k] == '\t')
            k++;
        while (buff[k] != '\0')
            cheatSentence[t++] = buff[k++];
        cheatSentence[t] = '\0';
        printf("Command parameter is:%s\n", cheatSentence);
        curse = 1;
        cheatStage = 0;
        valid = 1;
    }
    return valid;
}

bool cheat::testIsCheater(int playerID) const
{
    if (playerID == cheaterID)
        return true;
    return false;
}

void cheat::tryToUseCheat(int playerID, vector<char> legalWords)
{
    if (curse && !testIsCheater(playerID))
    {
        if (cheatStage == 0 || cheatStage == 1)
        {
            printf("%s If you agree,please enter %c \n", cheatSentence, legalWords[0]);
            cheatStage = 1;
        }
    }
}

void cheat::prepare(int playerID)
{
    if (testIsCheater(playerID) && cheatStage == 1)
    {
        cheatStage = 2;
    }
    if (testIsCheater(playerID))
    {
        curse = true;
    }
}