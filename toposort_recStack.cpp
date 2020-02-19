#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define pb push_back

int n,m,a,b;
vector<int> graph[10010];
vector<int> ans;
vector<bool> vis(10010,false);
vector<bool> ver(10010,false);

bool isCyclic(int u)
{
    vis[u]=true;
    ver[u]=true;
    
    for(int v : graph[u])
    {
        if(ver[v]) return true;
        if(!vis[v] && isCyclic(v)) return true;
    }

    ver[u]=false;
    ans.insert(ans.begin(),u);
    return false;
}

int32_t main()
{
    ios_base::sync_with_stdio(false),cin.tie(NULL);
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        graph[a].pb(b);
    }

    for(int i=1;i<=n;i++)
    {
        sort(graph[i].rbegin(),graph[i].rend());
    }

    for(int i=n;i>=1;i--)
    {
        if(!vis[i] && isCyclic(i))
        {
            cout<<"Sandro fails.";
            goto kindaki;
        }
    }
    for(int i : ans) cout<<i<<" ";
    kindaki:;
    return 0;
}