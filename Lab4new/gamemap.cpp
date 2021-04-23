#include <bits/stdc++.h>
//#include "player.h"
#include "gamemap.h"
using namespace std;

gameMap::gameMap()
{
    width = 4;
    height = 4;
    wins = 2048;
    round = 0;
}

gameMap::gameMap(int newWidth, int newHeight, int newWins)
{
    width = newWidth;
    height = newHeight;
    wins = newWins;
    round = 0;
}

void gameMap::clearmap()
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            a[i][j] = 0;
        }
    }
}

void gameMap::setwins(int win)
{
    wins = win;
}

int gameMap::getround() const
{
    return round;
}

void gameMap::begincheat()
{
    cheatingnow=1;
}

int gameMap::getcheatingnow()const
{
    return cheatingnow;
}

void gameMap::initial()
{
    clearmap();
    getRandomNumber();
    getRandomNumber();
    printHelp();
    printmap();
}

void gameMap::printmap() const
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

int gameMap::getremain() const
{
    int ans = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (a[i][j] == 0)
                ans++;
        }
    }
    return ans;
}

void gameMap::roundadd(int t)
{
    round += t;
}

void gameMap::getRandomNumber()
{
    time_t t;
    srand((unsigned)time(&t));
    int x = rand() % getremain();
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
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
    int y;
    switch (x)
    {
    case 2:
        y=goup();
        printmap();
        return y;
        break;
    case 3:
        y=goleft();
        printmap();
        return y;
        break;
    case 4:
        y=goright();
        printmap();
        return y;
        break;
    case 5:
        y=godown();
        printmap();
        return y;
        break;
    default:
        return 0;
        break;
    }
}

int gameMap::goup()
{
    int x = 0;
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
                    x += (a[k][w]);
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
    return x;
}

int gameMap::goleft()
{
    int x = 0;
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
                    x += (a[w][k]);
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
    return x;
}

int gameMap::goright()
{
    int x = 0;
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
                    x += (a[w][k]);
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
    return x;
}

int gameMap::godown()
{
    int x = 0;
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
                    x += (a[k][w]);
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
    return x;
}

bool gameMap::victory() const
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

bool gameMap::defeat() const
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

int gameMap::onlyone()
{
    gameMap copy1(height,width,wins);
    gameMap copy2(height,width,wins);
    gameMap copy3(height,width,wins);
    gameMap copy4(height,width,wins);
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy1.a[i][j]=copy2.a[i][j]=copy3.a[i][j]=copy4.a[i][j]=a[i][j];
        }
    }
    copy1.flag=copy2.flag=copy3.flag=copy4.flag=0;
    copy1.goup();
    int q=copy1.flag;
    copy2.goleft();
    int w=copy2.flag;
    copy3.goright();
    int e=copy3.flag;
    copy4.godown();
    int r=copy4.flag;
    if((q+w+e+r)==1)
    {
        if(q)
            onlyword='w';
        if(w)
            onlyword='a';
        if(e)
            onlyword='s';
        if(r)
            onlyword='z';
        return 1;
    }
    else
        return 0;
}
void gameMap::printHelp()
{
    printf("\t[-t]\tLet the game end when there is a 64 block.\n");
    printf("\t[w]\tgo up\n");
    printf("\t[a]\tgo left\n");
    printf("\t[s]\tgo right\n");
    printf("\t[z]\tgo down\n");
    printf("\tYou need to press 'enter'.\t\n");
}
