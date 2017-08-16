#include <iostream>
using namespace std;
int main ()
{
    int n;
    cout<<"Enter number of elements:"<<endl;
    cin>>n;
    int arr[n+1];
    cout<<"Enter elements:"<<endl;
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    for(int j=n;j>=2;j--)
    {
        int t=1;
        for(int k=2;k<=j;k++)
        {
            if(arr[t]>arr[k])
            {
                t=k;
            }
        }
        swap(arr[j],arr[t]);
    }
    cout<<"Sorted Array:"<<endl;
    for(int i=1;i<=n;i++)
        cout<<arr[i]<<" ";
    return 0;
}
