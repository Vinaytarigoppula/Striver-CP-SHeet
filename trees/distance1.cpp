#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<int> dp;
int n;
int dfs(int node,int par)
{
    int maxi=0;
    for(int v:adj[node])
    {
        if(v==par) continue;
        int h=1+dfs(v,node);
        if(h>maxi) maxi=h;
    }
    return dp[node]=maxi;
}
int main(){
    cin>>n;
    adj.assign(n+1,vector<int>());
    dp.assign(n+1,-1);
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,-1);
    for(int i=0;i<n;i++)
    {
        cout<<dp[i]<<" ";
    }
}