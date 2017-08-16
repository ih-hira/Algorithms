#include <iostream>
#include <algorithm>
#define MAX 10000000
using namespace std;
int x[MAX];
void QuickSort(int f, int l)
{
    int i,j;
    if(f<l)
    {
        i= f+1;
        while(x[i]<x[f]) i++;
        j=l;
        while(x[j]>x[f]) j--;
        while(i<j)
        {
            swap(x[i],x[j]);
            while(x[i]<x[f]) i++;
            while(x[j]>x[f]) j--;
        }
        swap(x[j],x[f]);
        QuickSort(f,j-1);
        QuickSort(j+1,l);
    }
}
int main ()
{
    int n;
    cout<<"Enter Number of Elements: "<<endl;
        cin>>n;
    cout<<"Enter Elements: "<<endl;
    for(int i=1;i<=n;i++)
        cin>>x[i];
    QuickSort(1,n);
    cout<<"Sorted Array: "<<endl;
    for(int i=1;i<=n;i++)
        cout<<x[i]<<" ";
    return 0;
}
