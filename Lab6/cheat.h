#ifndef CHEAT_H
#define CHEAT_H
#include <bits/stdc++.h>
using namespace std;
class cheat
{
public:
    cheat();
    void tryToUseCheat(int playerID, vector<char> legalWords);
    void prepare(int playerID);
    int getCheatSentence(char *buff);

private:
    int cheaterID;
    int curse;      // 0 场上没有诅咒  1场上已经存在诅咒
    int cheatStage; // 0诅咒还没使用  1诅咒正在使用 2诅咒使用完毕
    static char cheatSentence[10001];
    bool testIsCheater(int playerID) const;
};
char cheat::cheatSentence[10001] = {"\0"};
#endif