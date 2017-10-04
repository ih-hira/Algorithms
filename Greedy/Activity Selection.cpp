#include <iostream>
#include <algorithm>
using namespace std;
struct myStruct
{
    int start_time,end_time;
} event[50];
bool cmp(myStruct A,myStruct B)
{
    if(A.end_time==B.end_time)
        return A.start_time<B.start_time;
    return A.end_time<B.end_time;
}
int main ()
{
    int n;
    cout<<"Enter number of activity: ";
    cin>>n;
    cout<<"Enter start and end time of all activity:"<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>event[i].start_time>>event[i].end_time;
    }
    sort(event,event+n,cmp);

    int maxEvent=0,prev_end=-1;
    for(int j=0; j<n; j++)
    {
        if(event[j].start_time>=prev_end)
        {
            maxEvent++;
            prev_end=event[j].end_time;
        }
    }
    cout<<"Maximum number of activities : "<<maxEvent<<endl;
    return 0;
}
