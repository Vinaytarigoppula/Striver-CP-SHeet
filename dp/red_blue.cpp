#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int>> dp;
int helper(int i,int j,vector<int>& a,vector<int>& b)
{
    if(dp[i][j]!=-1) return dp[i][j];
    int s1=0,s2=0;
    int maxi=0;
    if(i<a.size() && j<b.size())
    {
        s1=a[i]+helper(i+1,j,a,b);
        s2=b[j]+helper(i,j+1,a,b);
    }
    else if(i>=n && j<m) s2=b[j]+helper(i,j+1,a,b);
    else if(i<n && j>=m) s1=a[i]+helper(i+1,j,a,b);
    maxi=max(s1,max(s2,maxi));
    return dp[i][j]=maxi;
}
int main(){
    int t;
    cin>>t;
    while(t-->0)
    {
        cin>>n;
        vector<int> r(n);
        for(int i=0;i<n;i++) cin>>r[i];
        cin>>m;
        dp.assign(n+1,vector<int>(m+1,-1));
        vector<int> b(m);
        for(int i=0;i<m;i++) cin>>b[i];
        vector<int> ans(n+m);

        int k=helper(0,0,r,b);
        cout<<k<<endl;
    }   
}