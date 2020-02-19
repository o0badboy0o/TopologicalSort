#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define int long long int

int n,m,a,b,vVis;
vector<int> graph[10010];
set<int> q;
vector<int> indegree(10010,0);
vector<int> ans;

bool topSort()
{
    for(int i=1;i<=n;i++)
    {
        if(indegree[i]==0) q.insert(i);
    }

    while(q.size())
    {
        int u=*q.begin();
        q.erase(q.begin());
        ans.pb(u);

        for(int v : graph[u])
        {
            indegree[v]--;
            if(indegree[v]==0) q.insert(v);
        }
        vVis++;
    }

    return (vVis==n) ? 1 : 0 ;
}

int32_t main()
{
    ios_base::sync_with_stdio(false),cin.tie(NULL);

    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        graph[a].pb(b);
        indegree[b]++;
    }

    if(topSort())
    {
        for(int i : ans) cout<<i<<" ";
    }
    else cout<<"Sandro fails.";

    return 0;
}