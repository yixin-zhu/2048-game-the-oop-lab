#include "gamemap.h"

GameMap::GameMap()
{
    width = 4;
    height = 4;
    wins = 2048;
    round = 0;
    flag = 0;
    legalWords="";
}

GameMap::GameMap(int newWidth, int newHeight, int newWins)
{
    width = newWidth;
    height = newHeight;
    wins = newWins;
    round = 0;
    flag = 0;
    legalWords="";
}

GameMap::GameMap(const GameMap &g)
{
    width=g.width;
    height=g.height;
    wins = g.wins;
    round = g.round;
    flag = g.flag;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            a[i][j] = g.a[i][j];
        }
    }
    legalWords=g.legalWords;
}

void GameMap::resetGameMap(const GameMap &g)
{
    g.printMap();
    width=g.width;
    height=g.height;
    wins = g.wins;
    round = g.round;
    flag = g.flag;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            a[i][j] = g.a[i][j];
        }
    }
    legalWords=g.legalWords;
}

void GameMap::clearMap()
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            a[i][j] = 0;
        }
    }
}

void GameMap::setwins(int win)
{
    wins = win;
    printf("The game will end when there is a 64 block.\n");
}

int GameMap::getround() const
{
    return round;
}

void GameMap::initial()
{
    clearMap();
    for (int i = 1; i <= 2; i++)
    {
        getRandomNumber();
    }
    printHelp();
    printMap();
}

void GameMap::printMap() const
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
        printf("|\n");
    }
    for (int j = 0; j < width; j++)
    {
        printf("+-----");
    }
    printf("+\n");
}

void GameMap::printMapWithoutWall() const
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

int GameMap::getRemain() const
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

void GameMap::roundAdd(int t)
{
    round += t;
}

void GameMap::getRandomNumber()
{
    time_t t;
    srand((unsigned)time(&t));
    int x = rand() % getRemain();
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

vector<int> GameMap::getRandomNumberPlace()
{
    time_t t;
    vector<int> ans;
    srand((unsigned)time(&t));
    int x = rand() % getRemain();
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            if (a[i][j] == 0)
            {
                if (x == 0)
                {
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
                x--;
            }
        }
    }
    return ans;
}

int GameMap::go(int x)
{
    int y;
    flag=0;
    switch (x)
    {
    case 2:
        y = goup();
        if (flag)
        {
            getRandomNumber();
            roundAdd(1);
        }
        return y;
        break;
    case 3:
        y = goleft();
        if (flag)
        {
            getRandomNumber();
            roundAdd(1);
        }
        return y;
        break;
    case 4:
        y = goright();
        if (flag)
        {
            getRandomNumber();
            roundAdd(1);
        }
        return y;
        break;
    case 5:
        y = godown();
        if (flag)
        {
            getRandomNumber();
            roundAdd(1);
        }
        return y;
        break;
    default:
        return 0;
        break;
    }
}

int GameMap::goWithoutRefresh(int x)
{
    int y;
    switch (x)
    {
    case 2:
        y = goup();
        return y;
        break;
    case 3:
        y = goleft();
        return y;
        break;
    case 4:
        y = goright();
        return y;
        break;
    case 5:
        y = godown();
        return y;
        break;
    default:
        return 0;
        break;
    }
}

int GameMap::goup()
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
    return x;
}

int GameMap::goleft()
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
    return x;
}

int GameMap::goright()
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
    return x;
}

int GameMap::godown()
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
    return x;
}

bool GameMap::victory() const
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

bool GameMap::defeat() const
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

int GameMap::testFourDir()
{
    GameMap copys[4];
    int result[4];
    for (int k = 0; k < 4; k++)
    {
        copys[k] = GameMap(height, width, wins);
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                copys[k].a[i][j] = a[i][j];
            }
        }
        copys[k].flag = 0;
        copys[k].go(k + 2);
        result[k] = copys[k].flag;
    }
    if (result[0])
        legalWords+='w';
    if (result[1])
        legalWords+='a';
    if (result[2])
        legalWords+='s';
    if (result[3])
        legalWords+='z';
    return result[0] + result[1] + result[2] + result[3];
}

void GameMap::printHelp() const
{
    printf("\t[-t]\tLet the game end when there is a 64 block.\n");
    printf("\t[w]\tgo up\n");
    printf("\t[a]\tgo left\n");
    printf("\t[s]\tgo right\n");
    printf("\t[z]\tgo down\n");
    printf("\tYou need to press 'enter'.\t\n");
}
