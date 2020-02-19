#include<bits/stdc++.h>
using namespace std;

#define pb push_back

int n,aVis;
string s;
vector<string> names;
unordered_map<char,vector<char>> graph;
vector<char> ans;

unordered_map<char,int> indegree={
    {'a',0},
    {'b',0},
    {'c',0},
    {'d',0},
    {'e',0},
    {'f',0},
    {'g',0},
    {'h',0},
    {'i',0},
    {'j',0},
    {'k',0},
    {'l',0},
    {'m',0},
    {'n',0},
    {'o',0},
    {'p',0},
    {'q',0},
    {'r',0},
    {'s',0},
    {'t',0},
    {'u',0},
    {'v',0},
    {'w',0},
    {'x',0},
    {'y',0},
    {'z',0}
};

bool topSort()
{
    set<char> q;

    for(char c='a';c<='z';c++)
    {
        if(indegree[c]==0)
        {
            q.insert(c);
        }
    }

    while(q.size())
    {
        char c=*q.begin();
        q.erase(q.begin());
        ans.pb(c);

        for(char d : graph[c])
        {
            indegree[d]--;
            if(indegree[d]==0) q.insert(d);
        }

        aVis++;
    }

    return (aVis==26) ? true : false ;
}

int main()
{
    ios_base::sync_with_stdio(false),cin.tie(NULL);

    cin>>n;
    set<pair<char,char>> pairs;
     for(int i=0;i<n;i++)
    {
        cin>>s;
        names.pb(s);
    }
    for(int i=0;i<names.size()-1;i++)
    {
        string one=names[i];
        string two=names[i+1];
        
        int len=min(one.size(),two.size());
        int j;
        for(j=0;j<len;j++)
        {
            if(one[j]!=two[j]) break;
        }

        if(j!=len)
        {
            pairs.insert({one[j],two[j]});
        }
        else
        {
            if(one.size()>two.size())
            {
                cout<<"Impossible";
                return 0;
            }
        }
    }

    for(auto p : pairs)
    {
        graph[p.first].pb(p.second);
        indegree[p.second]++;
    }

    if(topSort())
    {
        for(char c : ans) cout<<c;
    }
    else cout<<"Impossible";

    return 0;
}