#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
int n,m;
vector<int> cats;
vector<int> isleaf;
vector<bool> vis;
int ans=0;

void dfs(int node,int par,int cnt)
{
    if(cats[node-1]==1) cnt+=1;
    else cnt=0;
    if(cnt==m+1) return;
    bool leaf =true;
    vis[node]=true;
    for(int it:adj[node])
    {
        if(!vis[it])
        {
            leaf=false;
            dfs(it,node,cnt);
        }
    }
    if(leaf) ans++;
    return;
}
int main(){
    cin>>n>>m;
    cats.assign(n,0);
    isleaf.assign(n,0);
    vis.assign(n,false);
    for(int i=0;i<n;i++) cin>>cats[i];
    adj.assign(n+1,vector<int>());
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vis.assign(n,false);
    dfs(1,-1,0);
    cout<<ans;
}