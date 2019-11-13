#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter n (2^1+2^2+----+2^n): ";
    cin>>n;
    int ans = pow(2,n+1) - 1;
    cout<<"Sum is: ";
    cout<<ans<<endl;
}

