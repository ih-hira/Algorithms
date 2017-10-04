#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
int price[10],wt[10];
int knapsack01(int n,int c)
{
    int T[n+1][c+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=c;j++)//j is weight 1,2,3...
        {
            if(i==0||j==0) T[i][j]=0;

            else if(j<wt[i]) T[i][j]=T[i-1][j];

            else
            {
                T[i][j] = max((price[i]+T[i-1][j-wt[i]]),T[i-1][j]);
            }
        }
    }
    return T[n][c];
}
int main()
{
    int capacity,numberofitem;

    cin>>capacity>>numberofitem;

    for(int i=1;i<=numberofitem;i++)
        cin>>price[i]>>wt[i];
    printf("%d\n",knapsack01(numberofitem,capacity));
}
