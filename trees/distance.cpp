#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<vector<int>> dp;
vector<bool> vis;
int n,k;
int ans=0;
void dfs(int node,int par)
{
    dp[node][0]=1;
    
    for(int v:adj[node])
    {
        if(v==par) continue;
        dfs(v,node);
        for(int i=0;i<k;i++)
        {
            ans+=1LL*(dp[node][i]*dp[v][k-i-1]);
        }
        for(int i=0;i<k;i++)
        {
            dp[node][i+1]+=dp[v][i];
        }
    }
}
int main(){
    cin>>n>>k;
    adj.assign(n+1,vector<int>());
    vis.assign(n+1,false);
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        
        adj[b].push_back(a);
    }
    dp.assign(n+1,vector<int>(k+1,0));
    dfs(1,-1);
    cout<<ans;

}