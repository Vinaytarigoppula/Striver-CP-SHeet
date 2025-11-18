#include <bits/stdc++.h>
using namespace std;
vector<long long> dp;
long long helper(int prev,vector<int>& arr)
{
    
    if(dp[prev+1]!=-1) return dp[prev+1];
    long long take=0;
    if(prev==-1)
    {
        for(int i=0;i<arr.size();i++)
        {
            take=max(take,1+helper(i+1,arr));
        }
    }
    else{
        for(int i=prev*2;i<=arr.size();i+=prev)
        {
            if(arr[i-1]>arr[prev-1]) take=max(take,1+helper(i,arr));
        }
    }
    return dp[prev+1]=take;
}
int main(){
    int t;
    cin>>t;
    while(t-->0)
    {
        int n;
        cin>>n;
        dp.assign(n+2,-1);
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        long long ans=helper(-1,arr);
        cout<<ans<<endl;
    }
}