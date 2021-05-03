#include <iostream>
using namespace std;

int main()
{
    int a[10] = {9,5,1,2,3,4,7,8,0,6};
    for(int i=0;i<10;i++)
    {
        int valueToInsert = a[i];
        int j = i;
        while(j>0 && valueToInsert<a[j-1])
        {
            a[j] = a[j-1];
            j--;
        }
        a[j] = valueToInsert;
    }
    for(int i=0;i<10;i++) cout<<a[i]<<" ";
    return 0;
}
