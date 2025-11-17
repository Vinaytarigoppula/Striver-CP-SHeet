//https://codeforces.com/problemset/problem/1042/B
#include <bits/stdc++.h>
using namespace std;
int dp[100001][8];
int helper(int i,vector<int> &cost,vector<int> &s,int cnt)
{
    if(cnt==7) return 0;
    if(i>=cost.size()) return INT_MAX;
    if(dp[i][cnt]!=-1) return dp[i][cnt];
    int take=0,nottake=0;
    int next=helper(i+1,cost,s,cnt | s[i]);
    if(next==INT_MAX) take=INT_MAX;
    else take=next+cost[i];
    nottake=helper(i+1,cost,s,cnt);
    return dp[i][cnt]=min(take,nottake);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    vector<int> cost(n);
    vector<int> s(n);
    for(int i=0;i<n;i++)
    {
        string temp;
        int co;
        cin>>co>>temp;
        cost[i]=co;
        int or_op=0;
        for(int j=0;j<temp.size();j++)
        {
            if(temp[j]=='A') or_op|=1;
            if(temp[j]=='B') or_op|=2;
            if(temp[j]=='C') or_op|=4;
        }
        s[i]=or_op;
    }
    int ans=helper(0,cost,s,0);
    if(ans>=INT_MAX) cout<<-1;
    else cout<<ans;
}