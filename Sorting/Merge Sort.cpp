#include <iostream>
#include <cmath>
#include <climits>
#define MAX 10000000
using namespace std;
int A[MAX];
void Merge(int p,int q,int r)
{
    int n1 = q-p+1;
    int n2 = r-q;
    int L[n1+1];
    int R[n2+1];
    for(int i=1;i<=n1;i++) L[i] = A[p+i-1];
    for(int j=1;j<=n2;j++) R[j] = A[q+j];
    L[n1+1] = INT_MIN;
    R[n2+1] = INT_MIN;
    int i=1,j=1;
    for(int k=p;k<=r;k++)
    {
        if(L[i]>=R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
    }
}
void Merge_Sort(int p,int r)
{
    if(p<r)
    {
        int q = floor((p+r)/2);
        Merge_Sort(p,q);
        Merge_Sort(q+1,r);
        Merge(p,q,r);
    }
}
int main ()
{
    int n;
    cout<<"Enter Number of Element: "<<endl;
    cin>>n;
    cout<<"Enter elements: "<<endl;
    for(int i=1;i<=n;i++)
    {
        cin>>A[i];
    }
    Merge_Sort(1,n);
    cout<<"Sorted Array: "<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<A[i]<<" ";
    }
    return 0;
}
