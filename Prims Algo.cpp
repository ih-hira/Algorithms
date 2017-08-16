#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <cmath>
#include <climits>
#include <iterator>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
using namespace std;
#define MIN INT_MIN
#define MAX INT_MAX
#define MAX_INDEX 100
#define const double PI = acos(-1.0)
#define inf 1<<31-1  //0x80000000-1 = 0x7fffffff = 2147483647
vector<int>adj[MAX_INDEX];
int cost[MAX_INDEX][MAX_INDEX];
int weight[MAX_INDEX];
int par[MAX_INDEX];
bool mstSet[MAX_INDEX];

int findMinNode(int w,int n)
{
    for(int i=0; i<n; i++)
    {
        if(!mstSet[i] && weight[i]==w) return i;
    }
}

void printMST(int n)
{
    printf("Edge   Weight\n");
    for (int i = 0; i < n; i++)
        if(par[i]!=-inf) printf("%d - %d    %d \n", par[i], i, cost[i][par[i]]);
}

void Prims(int r,int node)
{
    for(int v=0; v<node; v++)
    {
        weight[v] = inf;
        par[v] = -inf;
    }
    weight[r] = 0;
    par[r] = -inf;
    priority_queue< int,vector<int>,greater<int> > Q;
    Q.push(weight[r]);
    while(!Q.empty())
    {
        int u = findMinNode(Q.top(),node);
        mstSet[u] = true;
        Q.pop();
        for(int i=0; i<adj[u].size(); i++)
        {
            int v = adj[u][i];
            if(!mstSet[v] && cost[u][v]<weight[v])
            {
                weight[v] = cost[u][v];
                par[v] = u;
                Q.push(weight[v]);
            }
        }
    }
}

int main ()
{
    int edge,node,n1,n2,c,root;
    //freopen("inputPrims.txt","r",stdin);
    cin>>node>>edge;
    for(int i=0; i<edge; i++)
    {
        cin>>n1>>n2>>c;
        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
        cost[n1][n2] = c;
        cost[n2][n1] = c;
    }
    cin>>root;
    Prims(root,node);
    printMST(node);
    return 0;

}
