#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,x;
    cin>>n>>x;
    vector<vector<int>> dp(n+1,vector<int>(x+1,0));
    vector<int> book(n);
    vector<int> pages(n);
    
    for(int i=0;i<n;i++) cin>>book[i];
    for(int i=0;i<n;i++) cin>>pages[i];
    for(int i=1;i<=n;i++)
    {
        for(int price=0;price<=x;price++)
        {
            int skip=0,take=0;
            if(price>=book[i-1]) take=dp[i-1][price-book[i-1]]+pages[i-1];
            skip=dp[i-1][price];
            dp[i][price]=max(skip,take);
        }
    }
    cout<<dp[n][x];
}