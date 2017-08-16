#include <iostream>
#include <algorithm>
using namespace std;
int main ()
{
    int array[100],n;
    cout<<"Enter Number of Elements:"<<endl;
    cin>>n;
    cout<<"Enter Elements:"<<endl;
    for(int i=1;i<=n;i++)
        cin>>array[i];
    int k = n;
    while(k!=0)
    {
        int t=0;
        for(int j=1;j<=k-1;j++)
        {
            int temp;
            if(array[j]<array[j+1])
            {
                swap(array[j],array[j+1]);
                t=j;
            }
        }
        k=t;
    }
    for(int i=1;i<=n;i++)
        cout<<array[i]<<" ";
    return 0;
}
