#include<bits\stdc++.h>
using namespace std;

#define ff first
#define ss second


int main()
{
    int n;
    cin >> n;
    int head;
    cin >> head;

    vector<int>v(n);
    for(int i=0;i<n;i++)
    {
        cin >> v[i];
    }
    vector<int>visited(n);

    int total_seek_time=0;

    for(int i=0;i<n;i++)
    {
        int in=-1;
        int mn=INT_MAX;
        for(int j=0;j<n;j++)
        {
            if(!visited[j])
            {
                int x=abs(head-v[j]);
                if(x<mn)
                {
                    in=j;
                    mn=x;
                }
            }
        }
        total_seek_time+=mn;
        head=v[in];
        visited[in]=1;

    }
    cout << "total seektime " << total_seek_time << endl;

}
