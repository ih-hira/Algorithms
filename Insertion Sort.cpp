#include <iostream>
#include <climits>
#include <cstdio>
using namespace std;
int main ()
{
    int n,c=0;
    cout<<"Enter Number of Elements:"<<endl;
    cin>>n;
    int array[n+2];
    cout<<"Enter Elements:"<<endl;
    for(int i=1;i<=n;i++)
        cin>>array[i];
    array[0]=INT_MIN;
    for(int j=2;j<=n;j++)
    {
        int i=j-1;
        int t = array[j];
        while(t<array[i])
        {
            array[i+1]=array[i];
            i--;
        }
        array[i+1]=t;
    }
    cout<<"Sorted Array:"<<endl;
    for(int i=1;i<=n;i++)
        cout<<array[i]<<" ";
    return 0;
}
