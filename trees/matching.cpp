#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<vector<int>> dp;
int n;
void dfs(int node,int par)
{
    vector<int> childdp;
    for(int v:adj[node])
    {
        if(v==par) continue;
        dfs(v,node);
        childdp.push_back(max(dp[v][0],dp[v][1]));
    }
    vector<int> prefix=childdp,suffix=childdp;
    for(int i=1;i<childdp.size();i++)
    {
        prefix[i]+=prefix[i-1];
    }
    for(int i=childdp.size()-2;i>=0;i--)
    {
        suffix[i]+=suffix[i+1];
    }
    if(childdp.empty()) return;
    dp[node][0]=suffix[0];
    int idx=0;
    for(int v:adj[node])
    {
        if(v==par) continue;
        int leftsum=idx==0?0:prefix[idx-1];
        int rightsum=idx==suffix.size()-1?0:suffix[idx+1];
        dp[node][1]=max(dp[node][1],1+leftsum+rightsum+dp[v][0]);
        idx++;
    }
}
int main(){
    cin>>n;
    adj.assign(n+1,vector<int>());
    dp.assign(n+1,vector<int>(2,0));
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,-1);
    cout<<max(dp[1][0],dp[1][1]);
}