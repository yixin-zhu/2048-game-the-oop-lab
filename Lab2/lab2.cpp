#include <bits/stdc++.h>
using namespace std;
#define MAXN 4
#define GENERATE "n"
#define UP "w"
#define LEFT "a"
#define RIGHT "s"
#define DOWN "z"
#define EASY "-t"
#define BUFFLEN 1024

void printHelp()
{
    printf("\t[-t]\t将胜利条件改为出现一个64的方块\n");
    printf("\t[w]\t向上\n");
    printf("\t[a]\t向左\n");
    printf("\t[s]\t向右\n");
    printf("\t[z]\t向下\n");
    printf("\t需要回车哦！\t\n");
}

class bigMap
{
private:

public:
    int width;
    int height;
    int wins;
    int flag;
    int a[MAXN][MAXN];
    void clearmap(void);
    void setwidth(int wid);
    void setheight(int hei);
    void setwins(int win);
    void printmap(void);
    int getremain(void);
    void getRandomNumber(void);
    void goup(void);
    void goleft(void);
    void goright(void);
    void godown(void);
    bool victory(void);
    bool defeat(void);
};

void bigMap::clearmap()
{
    for (int i = 0; i < MAXN; i++)
    {
        for (int j = 0; j < MAXN; j++)
        {
            a[i][j] = 0;
        }
    }
}

void bigMap::setwidth(int wid)
{
    width = wid;
}

void bigMap::setheight(int hei)
{
    height = hei;
}

void bigMap::setwins(int win)
{
    wins = win;
}

void bigMap::printmap()
{
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            printf("+-----");
        }
        printf("+\n");
        for(int j = 0; j < width; j++)
        {
            printf("|");
            if(a[i][j]>0)
                printf("%5d",a[i][j]);
            else
                printf("     ");
        }
        printf("|");
        printf("\n");
    }
    for(int j=0; j<width; j++)
    {
        printf("+-----");
    }
    printf("+\n");
}

int bigMap::getremain()
{
    int ans=0;
    for (int i = 0; i < MAXN; i++)
    {
        for (int j = 0; j < MAXN; j++)
        {
            if(a[i][j] == 0)
                ans++;
        }
    }
    return ans;
}


void bigMap::getRandomNumber()
{
    time_t t;
    srand((unsigned) time(&t));
    int x=rand()%getremain();
    for (int i = 0; i < MAXN; i++)
    {
        for (int j = 0; j < MAXN; j++)
        {

            if(a[i][j] == 0)
            {
                if(x==0)
                {
                    a[i][j] = 2;
                    return;
                }
                x--;

            }
        }
    }
}

void bigMap::goup()
{
    int w,j,k;
    for (w=0; w<width; w++)
    {
        for (k=0,j=1; j<height; j++)
        {
            if (a[j][w] > 0)
            {
                if (a[k][w] == a[j][w])
                {
                    a[k][w]*=2;
                    a[j][w]=0;
                    k++;
                    flag=1;
                }
                else if (a[k][w]==0)
                {
                    a[k][w]=a[j][w];
                    a[j][w]= 0;
                    flag=1;
                }
                else
                {
                    a[k+1][w]=a[j][w];
                    if (j!=k+1)
                    {
                        a[j][w]=0;
                        flag=1;
                    }
                    k++;
                }
            }
        }
    }
}

void bigMap::goleft()
{
    int w,j,k;
    for (w=0; w<height; w++)
    {
        for (k=0,j=1; j<width; j++)
        {
            if (a[w][j] > 0)
            {
                if (a[w][k] == a[w][j])
                {
                    a[w][k]*=2;
                    a[w][j]=0;
                    k++;
                    flag=1;
                }
                else if (a[w][k]==0)
                {
                    a[w][k]=a[w][j];
                    a[w][j]= 0;
                    flag=1;
                }
                else
                {
                    a[w][k+1]=a[w][j];
                    if (j!=k+1)
                    {
                        a[w][j] = 0;
                        flag=1;
                    }
                    k++;
                }
            }
        }
    }
}

void bigMap::goright()
{
    int w,j,k;
    for (w=0; w<height; w++)
    {
        for (k=width-1,j=width-2; j>=0; j--)
        {
            if (a[w][j] > 0)
            {
                if (a[w][k] == a[w][j])
                {
                    a[w][k]*=2;
                    a[w][j]=0;
                    k--;
                    flag=1;
                }
                else if (a[w][k]==0)
                {
                    a[w][k]=a[w][j];
                    a[w][j]= 0;
                    flag=1;
                }
                else
                {
                    a[w][k-1]=a[w][j];
                    if (j!=k-1)
                    {
                        a[w][j] = 0;
                        flag=1;
                    }
                    k--;
                }
            }
        }
    }
}

void bigMap::godown()
{
    int w,j,k;
    for (w=0; w<width; w++)
    {
        for (k=height-1,j=height-2; j>=0; j--)
        {
            if (a[j][w]>0)
            {
                if (a[k][w] == a[j][w])
                {
                    a[k][w]*=2;
                    a[j][w]=0;
                    k--;
                    flag=1;
                }
                else if (a[k][w]==0)
                {
                    a[k][w]=a[j][w];
                    a[j][w]= 0;
                    flag=1;
                }
                else
                {
                    a[k-1][w]=a[j][w];
                    if (j!=k-1)
                    {
                        a[j][w] = 0;
                        flag=1;
                    }
                    k--;
                }
            }
        }
    }
}

bool bigMap::victory()
{
    for (int i = 0; i < MAXN; i++)
    {
        for (int j = 0; j < MAXN; j++)
        {
            if(a[i][j] == wins)
            {
                return true;
            }
        }
    }
    return false;
}

bool bigMap::defeat()
{
    for (int i = 0; i < MAXN; i++)
    {
        for (int j = 0; j < MAXN; j++)
        {
            if(a[i][j] == 0 )
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    char buff[10001];
    int x=0;
    bigMap mymap;
    mymap.setwidth(MAXN);
    mymap.setheight(MAXN);
    mymap.setwins(2048);
    mymap.clearmap();
    mymap.getRandomNumber();
    mymap.getRandomNumber();
    mymap.printmap();
    printHelp();
    while(fgets(buff,BUFFLEN,stdin))
    {
        mymap.flag=0;
        buff[strlen(buff)-1] = '\0';
        int branch=0;
        if(!strcmp(buff,EASY))
            branch=1;
        if(!strcmp(buff,UP))
            branch=2;
        if(!strcmp(buff,LEFT))
            branch=3;
        if(!strcmp(buff,RIGHT))
            branch=4;
        if(!strcmp(buff,DOWN))
            branch=5;
        switch (branch)
        {
        case 1:
            mymap.setwins(64);
            printf("胜利条件已修改为出现一个64的方块\n");
            break;
        case 2:
            system("cls");
            mymap.goup();
            if(mymap.flag)
                mymap.getRandomNumber();
            mymap.printmap();
            printHelp();
            break;
        case 3:
            system("cls");
            mymap.goleft();
            if(mymap.flag)
                mymap.getRandomNumber();
            mymap.printmap();
            printHelp();
            break;
        case 4:
            system("cls");
            mymap.goright();
            if(mymap.flag)
                mymap.getRandomNumber();
            mymap.printmap();
            printHelp();
            break;
        case 5:
            system("cls");
            mymap.godown();
            if(mymap.flag)
                mymap.getRandomNumber();
            mymap.printmap();
            printHelp();
            break;
        default:
            ;
            break;
        }
        if(mymap.victory()==true)
        {
            printf("Congratulations! You win the game!\n");
            break;
        }
        if(mymap.defeat()==true)
        {
            printf("Sorry! You lose the game!\n");
            break;
        }
    }
    return 0;
}
