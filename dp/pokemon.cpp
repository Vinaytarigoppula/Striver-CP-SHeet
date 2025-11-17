//https://codeforces.com/problemset/problem/1420/C1
#include <bits/stdc++.h>
using namespace std;
vector<vector<long long>> dp;
long long helper(int i,vector<long long>& arr,int cnt)
{
    if(i>=arr.size()) return 0;
    if(dp[i][cnt]!=-1) return dp[i][cnt];
    long long take=0;
    if(cnt==0) take=arr[i]+helper(i+1,arr,1-cnt);
    else take=-arr[i]+helper(i+1,arr,1-cnt);
    long long nottake=helper(i+1,arr,cnt);
    return dp[i][cnt]=max(take,nottake); 
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t-->0)
    {
        long long n,q;
        cin>>n>>q;
        dp.assign(n+1,vector<long long>(2,-1));
        vector<long long> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        long long pow=helper(0,arr,0);
        cout<<pow<<endl;
    }
}