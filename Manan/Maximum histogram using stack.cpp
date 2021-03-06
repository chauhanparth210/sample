#include<bits/stdc++.h>
using namespace std;

int max_histogram(vector<int> a)
{
    stack<int> s;
    int i=0,area=0,max_area=-1;
    while(i<a.size())
    {
        if(s.empty() || a[i]>=a[s.top()])
        {
            s.push(i);
            i++;
        }
        else if(a[i]<a[s.top()])
        {
            int d=s.top();
            s.pop();
            if(s.empty())
            {
                area=a[d]*i;
            }
            else
            {
                area=a[d]*(i-s.top()-1);
            }
            if(area>max_area)
                max_area=area;
        }
    }
    while(!s.empty())
    {
        int d=s.top();
        s.pop();
        if(s.empty())
        {
            area=a[d]*i;
        }
        else
        {
            area=a[d]*(i-s.top()-1);
        }
        if(area>max_area)
            max_area=area;
    }
    return max_area;
}
int main()
{
    vector<int> a;
    a.push_back(6);
    a.push_back(2);
    a.push_back(5);
    a.push_back(4);
    a.push_back(5);
    a.push_back(1);
    a.push_back(6);

    int ans=max_histogram(a);
    cout<<"Histogram array : ";
    for(int i=0;i<a.size();i++)
        cout<<a[i]<<" ";
    cout<<endl;
    cout<<"Maximum area obtained : "<<ans<<endl;
}
