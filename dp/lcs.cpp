#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    vector<int> a(n);
    vector<int> b(m);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];
    int maxi=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1]+1;
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
            maxi=max(maxi,dp[i][j]);
        }
    }
    cout<<dp[n][m]<<endl;
    int i=n,j=m;
    vector<int> ans;
    while(i>0 && j>0)
    {
        if(a[i-1]==b[j-1])
        {
            ans.push_back(a[i-1]);
            i--;
            j--;
        }
        else
        {
            if(dp[i-1][j]>dp[i][j-1])
            {   
                i--;
            }
            else
            {
                j--;
            }
        }
    }
    reverse(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
    
}