#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define pb push_back

int n,m,a,b;
vector<int> graph[10010];
vector<int> ans;
vector<char> color(10010,'w');

bool isCyclic(int u)
{
    color[u]='g';
    
    for(int v : graph[u])
    {
        char c=color[v];
        if(c=='b') continue;
        if(c=='g') return true;
        if(c=='w' && isCyclic(v)) return true; 
    }

    color[u]='b';
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
        if(color[i]=='w' && isCyclic(i))
        {
            cout<<"Sandro fails.";
            goto kindaki;
        }
    }
    for(int i : ans) cout<<i<<" ";
    kindaki:;
    return 0;
}