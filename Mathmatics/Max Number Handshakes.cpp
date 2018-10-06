#include <cstdio>
#include <iostream>
using namespace std;
int maxHandshake(int n)
{
    return (n*(n-1))/2;
}
int main ()
{
    int n;
    cin>>n;
    cout<< maxHandshake(n) <<endl;
    return 0;
}
