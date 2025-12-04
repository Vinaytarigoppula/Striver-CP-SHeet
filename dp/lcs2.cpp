#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    vector<int> dp(n+1,1);
    for(int i=0;i<n;i++) cin>>arr[i];
    int maxi=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[j]<arr[i]) dp[i]=max(dp[i],dp[j]+1);
        }
        maxi=max(maxi,dp[i]);
    }
    cout<<maxi;
}