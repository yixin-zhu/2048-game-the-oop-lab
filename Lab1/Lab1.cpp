#include <bits/stdc++.h>
using namespace std;
#define MAXN 4
#define GENERATE "n"
#define BUFFLEN 1024

void printMap(int a[][MAXN])
{
    for(int i = 0; i < MAXN; i++)
    {
        printf("+-----+-----+-----+-----+\n");
        for(int j = 0; j < MAXN; j++)
        {
            printf("|  ");
            printf(a[i][j]>0?"2  ":"   ");
        }
        printf("|");
        printf("\n");
    }
    printf("+-----+-----+-----+-----+\n");
}

int getRandomNumber()
{
    static int randomlist[MAXN*MAXN];
    static int num=MAXN*MAXN;
    static int ini=0;
    if(!ini)
    {
        for(int j=0; j<MAXN*MAXN; j++)
        {
            randomlist[j]=(j);
        }
        ini++;
    }
    time_t t;
    srand((unsigned) time(&t));
    int x=rand()%num;
    int y=randomlist[x];
    if(y!=randomlist[num-1])
        randomlist[x]=randomlist[num-1];
    num--;
    return y;
}

void changeMap(int (&a)[MAXN][MAXN],int x)
{
    a[x/MAXN][x%MAXN]=1;
}

int main()
{
    char buff[10001];
    int currentMap[MAXN][MAXN]= {0};
    int x,ans=0;
    printMap(currentMap);
    while(fgets(buff,BUFFLEN,stdin))
    {
        ans++;
        buff[strlen(buff)-1] = '\0';
        int branch=0;
        if(!strcmp(buff,GENERATE))
            branch=1;
        switch (branch)
        {
        case 1:
            system("cls");
            x=getRandomNumber();
            changeMap(currentMap,x);
            printMap(currentMap);
            break;
        default:
            ;
            break;
        }
        if(ans==MAXN*MAXN)
            break;
    }
    return 0;
}
