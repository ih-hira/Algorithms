#include <vector>
#include <queue>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
#define MAX 10000
#define white 0
#define black 1
#define gray 2
#define inf 999999
vector<int>adj[MAX];
int color[MAX];
int dis[MAX];
int par[MAX];
int f[MAX];
int time =0;
void DFS_Visit(int u)
{
    color[u] = gray;
    dis[u] = time++;
    for(int v=0;v<adj[u].size();v++)
    {
        if(color[adj[u][v]]==white)
        {
            par[adj[u][v]] = u;
            DFS_Visit(adj[u][v]);
        }
    }
    color[u] = black;
    f[u]=time++;
    printf("%d\t",u);
}
void DFS(int v)
{
    for(int u=0;u<v;u++)
    {
        color[u] = white;
        par[u] = -1;
    }
    time=0;
    for(int u=0;u<v;u++)
    {
        if(color[u]==white)
        {
            DFS_Visit(u);
        }
    }
}
int main ()
{
    int node,edge;
    int n1,n2;
    //freopen("inputDfsAlgo.txt","r",stdin);
    scanf("%d %d",&node,&edge);
    for(int i=0;i<edge;i++)
    {
        cin>>n1>>n2;
        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
    }
    DFS(node);
    return 0;
}
