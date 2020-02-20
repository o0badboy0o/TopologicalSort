#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
const int N=1e5+10;
const int mod=1e9+7;

int n,m,p,q,a,b,ans=0;
vector<int> graph[N];
vector<int> top;
vector<int> indegree(N,0);
vector<int> dp(N,0);
queue<int> qu;

void topoSort()
{
    for(int i=1;i<=n;i++)
    {
        if(indegree[i]==0)
        {
            qu.push(i);
        }
    }

    while(!qu.empty())
    {
        int u=qu.front();
        qu.pop();
        top.pb(u);

        for(int v : graph[u])
        {
            indegree[v]--;
            if(indegree[v]==0) qu.push(v);
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false),cin.tie(NULL);

    cin>>n>>m;
    cin>>p>>q;
    dp[q]=1;

    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        graph[a].pb(b);
        indegree[b]++;    
    }
    
    topoSort();

    for(auto i=top.rbegin();i!=top.rend();i++)
    {
        int u=*i;
        for(int v : graph[u])
        {
            dp[u]+=dp[v];
            dp[u]%=mod;
        }
    }

    cout<<dp[p];
    return 0;
}