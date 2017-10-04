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
typedef  pair<int, int> iPair;
vector< pair<int, iPair> > edges;
vector< pair<int, iPair> >::iterator it;

int cost[MAX_INDEX][MAX_INDEX];
int rnk[MAX_INDEX];
int par[MAX_INDEX];

int findRep(int u)
{
    if (u != par[u])
        par[u] = findRep(par[u]);
    return par[u];
}

void makeSet(int x, int y)
{

    if (rnk[x] > rnk[y])
        par[y] = x;
    else
        par[x] = y;

    if (rnk[x] == rnk[y])
        rnk[y]++;
}

int Krushkal(int n)
{
    int mstWeight = 0;

    for(int i=0; i<n; i++)
    {
        par[i] = i;
        rnk[i] = 0;
    }
    sort(edges.begin(),edges.end());
    for (it=edges.begin(); it!=edges.end(); it++)
    {
        int u = it->second.first;
        int v = it->second.second;

        int set_u = findRep(u);
        int set_v = findRep(v);


        if (set_u != set_v)
        {

            cout << u << " - " << v << endl;


            mstWeight += it->first;


            makeSet(set_u, set_v);
        }
    }

    return mstWeight;
}

int main ()
{
    int edge,node,n1,n2,c,r,d;
    //freopen("inputKrush.txt","r",stdin);
    cin>>node>>edge;
    for(int i=0; i<edge; i++)
    {
        cin>>n1>>n2>>c;
        edges.push_back({c,{n1,n2}});
    }

    cout << "Edges of MST are \n";
    int mst_wt = Krushkal(node);

    cout << "\nWeight of MST is " << mst_wt;
    return 0;
}
