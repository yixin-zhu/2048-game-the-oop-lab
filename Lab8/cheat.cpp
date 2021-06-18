#include "Cheat.h"
char Cheat::cheatSentence[10001] = {"\0"};
Cheat::Cheat()
{
    cheaterID = -1;
    curse = 0;
    cheatStage = 0;
}

int Cheat::getCheatSentence(char *buff)
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

bool Cheat::testIsCheater(int playerID) const
{
    if (playerID == cheaterID)
        return true;
    return false;
}

void Cheat::tryToUseCheat(int playerID, string legalWords)  // 0诅咒还没使用  1诅咒正在使用 2诅咒使用完毕
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

void Cheat::prepare(int playerID)
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