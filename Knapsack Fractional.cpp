#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct items
{
    double p,w;
}arr_n[100];

bool cmp(items a,items b)
{
    double r1 = a.p/a.w;
    double r2 = b.p/b.w;
    return r1>r2;
}

double fractionalKnapsack(double cap,int n)
{
    double curCap = 0,finalValue = 0;

    for(int i=0;i<n;i++)
    {
        if(curCap+arr_n[i].w<=cap)
        {
            curCap+=arr_n[i].w;
            finalValue+=arr_n[i].p;
        }
        else
        {
            double remain = cap - curCap;
            finalValue+=arr_n[i].p*(remain/arr_n[i].w);
            break;
        }
    }
    return finalValue;
}
int main()
{
    double cap;
    int n;
    printf("Enter total capacity: ");
    cin>>cap;
    printf("Enter number of items: ");
    cin>>n;
    printf("Enter value and weight:\n");
    for(int i=0;i<n;i++)
    {
        cin>>arr_n[i].p;
        cin>>arr_n[i].w;
    }
    sort(arr_n,arr_n+n,cmp);

    cout<<"Maximum value we can obtain : "<<fractionalKnapsack(cap,n)<<endl;
    return 0;
}
