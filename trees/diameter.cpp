#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<int> dp;
int diameter=0;
int n;
int dfs(int node,int par)
{
    int ans=0,max1=0,max2=0;
    for(int v:adj[node])
    {
        if(v==par) continue;
        int h=1+dfs(v,node);
        if(h>max1)
        {
            max2=max1;
            max1=h;
        }
        else if(h>max2)
        {
            max2=h;
        }
    }
    dp[node]=max1;
    diameter=max(diameter,max1+max2);
    return dp[node];
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
    cout<<diameter;
}