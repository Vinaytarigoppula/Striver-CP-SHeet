//https://codeforces.com/problemset/problem/189/A
#include <bits/stdc++.h>
using namespace std;
int a,b,c;
int dp[4001];
int helper(int n)
{
    if( n==0) return 0;
    if(n<=0) return -1e9;
    if(dp[n]!=-1) return dp[n];
    int take=1+(max(helper(n-a),max(helper(n-b),helper(n-c))));
    return dp[n]=take;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n>>a>>b>>c;
    memset(dp,-1,sizeof(dp));
    int ans=helper(n);
    if(ans<=-1e9) cout<<-1;
    else cout<<ans;
}