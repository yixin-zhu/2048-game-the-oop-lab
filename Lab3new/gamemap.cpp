#include <bits/stdc++.h>
#include "gamemap.h"
#include "player.h"
using namespace std;

gameMap::gameMap()
{
    width = 4;
    height = 4;
    wins = 2048;
    round=0;
}

gameMap::gameMap(int newWidth, int newHeight, int newWins)
{
    width = newWidth;
    height = newHeight;
    wins = newWins;
    round=0;
}

void gameMap::clearmap()
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width ; j++)
        {
            a[i][j] = 0;
        }
    }
}

void gameMap::setwins(int win)
{
    wins = win;
}

int gameMap::getmode()const
{
    return mode;
}

int gameMap::getround()const
{
    return round;
}

void gameMap::initial()
{
    ModeSelect(&mode);
    clearmap();
    getRandomNumber();
    getRandomNumber();
    printHelp();
    printmap();
}

void gameMap::ModeSelect(int* x)
{
    printf("请进行模式选择\n");
    printf("1:单人模式\n");
    printf("2:双人模式\n");
    printf("请输入对应模式的序号\n");
    scanf("%d",x);
}

void gameMap::printmap()const
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            printf("+-----");
        }
        printf("+\n");
        for (int j = 0; j < width; j++)
        {
            printf("|");
            if (a[i][j] > 0)
                printf("%5d", a[i][j]);
            else
                printf("     ");
        }
        printf("|");
        printf("\n");
    }
    for (int j = 0; j < width; j++)
    {
        printf("+-----");
    }
    printf("+\n");
}

int gameMap::getremain()const
{
    int ans = 0;
    for (int i = 0; i < MAXN; i++)
    {
        for (int j = 0; j < MAXN; j++)
        {
            if (a[i][j] == 0)
                ans++;
        }
    }
    return ans;
}

void gameMap::roundadd(int t )
{
    round+=t;
}

void gameMap::getRandomNumber()
{
    time_t t;
    srand((unsigned)time(&t));
    int x = rand() % getremain();
    for (int i = 0; i < MAXN; i++)
    {
        for (int j = 0; j < MAXN; j++)
        {

            if (a[i][j] == 0)
            {
                if (x == 0)
                {
                    a[i][j] = 2;
                    return;
                }
                x--;
            }
        }
    }
}

int gameMap::go(int x)
{
    switch(x)
    {
    case 2:
        return  goup();
        break;
    case 3:
        return goleft();
        break;
    case 4:
        return goright();
        break;
    case 5:
        return godown();
        break;
    }
}

int gameMap::goup()
{
    int x=0;
    int w, j, k;
    for (w = 0; w < width; w++)
    {
        for (k = 0, j = 1; j < height; j++)
        {
            if (a[j][w] > 0)
            {
                if (a[k][w] == a[j][w])
                {
                    a[k][w] *= 2;
                    x+=(a[k][w]);
                    a[j][w] = 0;
                    k++;
                    flag = 1;
                }
                else if (a[k][w] == 0)
                {
                    a[k][w] = a[j][w];
                    a[j][w] = 0;
                    flag = 1;
                }
                else
                {
                    a[k + 1][w] = a[j][w];
                    if (j != k + 1)
                    {
                        a[j][w] = 0;
                        flag = 1;
                    }
                    k++;
                }
            }
        }
    }
    if (flag)
    {
        getRandomNumber();
        roundadd(1);
    }
    printmap();
    return x;
}

int gameMap::goleft()
{
    int x=0;
    int w, j, k;
    for (w = 0; w < height; w++)
    {
        for (k = 0, j = 1; j < width; j++)
        {
            if (a[w][j] > 0)
            {
                if (a[w][k] == a[w][j])
                {
                    a[w][k] *= 2;
                    x+=(a[w][k]);
                    a[w][j] = 0;
                    k++;
                    flag = 1;

                }
                else if (a[w][k] == 0)
                {
                    a[w][k] = a[w][j];
                    a[w][j] = 0;
                    flag = 1;
                }
                else
                {
                    a[w][k + 1] = a[w][j];
                    if (j != k + 1)
                    {
                        a[w][j] = 0;
                        flag = 1;
                    }
                    k++;
                }
            }
        }
    }
    if (flag)
    {
        getRandomNumber();
        roundadd(1);
    }
    printmap();
    return x;
}

int  gameMap::goright()
{
    int x=0;
    int w, j, k;
    for (w = 0; w < height; w++)
    {
        for (k = width - 1, j = width - 2; j >= 0; j--)
        {
            if (a[w][j] > 0)
            {
                if (a[w][k] == a[w][j])
                {
                    a[w][k] *= 2;
                    x+=(a[w][k]);
                    a[w][j] = 0;
                    k--;
                    flag = 1;

                }
                else if (a[w][k] == 0)
                {
                    a[w][k] = a[w][j];
                    a[w][j] = 0;
                    flag = 1;
                }
                else
                {
                    a[w][k - 1] = a[w][j];
                    if (j != k - 1)
                    {
                        a[w][j] = 0;
                        flag = 1;
                    }
                    k--;
                }
            }
        }
    }
    if (flag)
    {
        getRandomNumber();
        roundadd(1);
    }
    printmap();
    return x;
}

int gameMap::godown()
{
    int x=0;
    int w, j, k;
    for (w = 0; w < width; w++)
    {
        for (k = height - 1, j = height - 2; j >= 0; j--)
        {
            if (a[j][w] > 0)
            {
                if (a[k][w] == a[j][w])
                {
                    a[k][w] *= 2;
                    x+=(a[k][w]);
                    a[j][w] = 0;
                    k--;
                    flag = 1;

                }
                else if (a[k][w] == 0)
                {
                    a[k][w] = a[j][w];
                    a[j][w] = 0;
                    flag = 1;
                }
                else
                {
                    a[k - 1][w] = a[j][w];
                    if (j != k - 1)
                    {
                        a[j][w] = 0;
                        flag = 1;
                    }
                    k--;
                }
            }
        }
    }
    if (flag)
    {
        getRandomNumber();
        roundadd(1);
    }
    printmap();
    return x;
}

bool gameMap::victory()const
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (a[i][j] == wins)
            {
                return true;
            }
        }
    }
    return false;
}

bool gameMap::defeat()const
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (a[i][j] == 0)
            {
                return false;
            }
            if ((j != width - 1) && (i != height - 1))
            {
                if ((a[i][j] == a[i][j + 1]) || (a[i][j] == a[i + 1][j]))
                {
                    return false;
                }
            }
            if (j == width - 1 && (i != height - 1))
            {
                if (a[i][j] == a[i + 1][j])
                {
                    return false;
                }
            }
            if ((j != width - 1) && (i == height - 1))
            {
                if (a[i][j] == a[i][j + 1])
                {
                    return false;
                }
            }
        }
    }
    return true;
}

void gameMap::printHelp()
{
    printf("\t[-t]\t将结束条件改为出现一个64的方块\n");
    printf("\t[w]\t向上\n");
    printf("\t[a]\t向左\n");
    printf("\t[s]\t向右\n");
    printf("\t[z]\t向下\n");
    printf("\t需要回车哦！\t\n");
}

void gameMap::doubleplay(player* a,player* b,char* buff)
{
    player* selection[2]= {a,b};
    player* now=selection[getround()%2];
    flag = 0;
    switch (a->operate(buff))
    {
    case 1:
        setwins(64);
        printf("游戏结束条件已修改为出现一个64的方块\n");
        break;
    case 2:
    case 3:
    case 4:
    case 5:
        system("cls");
        now->addScore(go(a->operate(buff)));
        now->displayScore();
        now=selection[getround()%2];
        now->waittomove();
        break;
    }
}

void gameMap::singleplay(char* buff,player* r)
{
    flag = 0;
    switch (r->operate(buff))
    {
    case 1:
        setwins(64);
        printf("结束条件已修改为出现一个64的方块\n");
        break;
    case 2:

    case 3:

    case 4:

    case 5:
        system("cls");
        r->addScore(go(r->operate(buff)));
        r->displayScore();
        break;
    default:
        ;
        break;
    }

}
