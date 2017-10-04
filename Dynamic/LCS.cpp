#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
string x,y;
int L[100][100];
string printLCS(int m,int n)
{
    string lcs;
    int i=m,j=n;
    while(i>0 && j>0)
    {
        if(x[i-1]==y[j-1])
        {
            lcs+=x[i-1];
            i--;
            j--;
        }
        else if(L[i-1][j]>L[i][j-1])
        {
            i--;
        }
        else
            j--;
    }
    reverse(lcs.begin(),lcs.end());
    return lcs;
}
int lcs(int lenX,int lenY)
{
    int i,j;
    for(i=0;i<=lenX;i++)
    {
        for(j=0;j<=lenY;j++)
        {
            if(i==0||j==0) L[i][j] = 0;

            else if(x[i-1]==y[j-1]) L[i][j] = L[i-1][j-1]+1;

            else L[i][j] = max(L[i-1][j],L[i][j-1]);
        }
    }
    return L[lenX][lenY];
}
int main()
{
    cin>>x>>y;

    int lenX = x.length();
    int lenY = y.length();
    printf("Length : %d\n",lcs(lenX,lenY));
    cout<<printLCS(lenX,lenY);
    return 0;
}
