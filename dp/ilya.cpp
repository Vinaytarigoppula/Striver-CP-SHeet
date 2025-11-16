#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin>>s;
    int m;
    cin>>m;
    int dp[100001];
    for(int i=1;i<s.size();i++)
    {
        if(s[i]==s[i-1]) dp[i]=dp[i-1]+1;
        else dp[i]=dp[i-1];
    }
    for(int i=0;i<m;i++)
    {
        int l,r;
        cin>>l>>r;
        cout<<dp[r-1]-dp[l-1]<<endl;
    }
}