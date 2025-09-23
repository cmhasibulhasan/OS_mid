#include<bits\stdc++.h>
using namespace std;

#define ff first
#define ss second


int main()
{
    int n;
    cin >> n;

    vector< pair<int,pair<string,int>>>v;
    for(int i=0;i<n;i++)
    {
        int a,b;
        string s;
        cin >> s >> a >> b;
        v.push_back( { a, {s,b }   }  );


    }

    vector<int>ct(n),tat(n),wt(n),visited(n);
    int total=0;
    int time=0;
    string gantt="0|";
    while(total<n)
    {
        int in=-1;
        int mx=INT_MAX;

        for(int i=0;i<n;i++)
        {
            if(v[i].ff<=time && !visited[i])
            {
                if(v[i].ss.ss<mx )
                {
                    in=i;
                    mx=v[i].ss.ss;
                }else if(v[i].ss.ss==mx && v[i].ff<v[in].ff)
                {
                    in=i;

                    cout << "WOW " << endl;
                }
            }
        }

        if(in==-1)
        {
            time++;
        }else
        {
            time+=v[in].ss.ss;
            ct[in]=time;
            tat[in]=ct[in]-v[in].ff;
            wt[in]=tat[in]-v[in].ss.ss;
            total++;
            visited[in]=1;
            gantt+= v[in].ss.ff + "|" + to_string(time) + "|";
            cout << v[in].ss.ff << "\t" << v[in].ff << "\t" << v[in].ss.ss  << "\t" << ct[in]  << "\t" <<  tat[in]  << "\t" << wt[in] << endl;
        }
    }
    cout <<  endl << gantt << endl;


}
