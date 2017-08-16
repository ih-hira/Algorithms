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
int dis[MAX_INDEX];
bool spSet[MAX_INDEX];
int par[MAX_INDEX];
void print_path(int s,int v)
{
    if(s==v)
        cout<<s<<" ";
    else if(par[v]==-inf)
    {
        cout<<v<<endl;
        cout<<"No Path Exist"<<endl;
    }
    else
    {
        print_path(s,par[v]);
        cout<<v<<" ";
    }
}
bool bellmanFord(int s,int node)
{
    for(int v=0;v<node;v++)
    {
        dis[v] = inf;
        //spSet[v] = false;
        par[v] = inf;
    }

    dis[s] = 0;
    par[s] = -inf;
    priority_queue<int> Q;
    Q.push(s);
    while(!Q.empty())
    {
        int u = Q.top();
        Q.pop();
        for(int i=0;i<adj[u].size();i++)
        {
            int v = adj[u][i];
            if(dis[u]+cost[u][v]<dis[v])
            {
                dis[v] = dis[u]+cost[u][v];
                par[v] = u;
                Q.push(v);
            }
        }
        for(int i=0;i<adj[u].size();i++)
        {
            int v = adj[u][i];
            if(dis[u]+cost[u][v]<dis[v])
            {
                return false;
            }
        }
    }
    return true;
}
int main ()
{
    int edge,node,n1,n2,c,r,d;
    //freopen("inputBellman.txt","r",stdin);
    cin>>node>>edge;
    for(int i=0;i<edge;i++)
    {
        cin>>n1>>n2>>c;
        adj[n1].push_back(n2);
        //adj[n2].push_back(n1);
        cost[n1][n2] = c;
    }
    cin>>r>>d;

    if(bellmanFord(0,node))print_path(r,d);

    else printf("Graph is cyclic\n");

    return 0;
}

