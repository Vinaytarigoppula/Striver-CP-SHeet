#include <bits/stdc++.h>
using namespace std;
bool cmp(vector<int> &x,vector<int> &y)
{
    return x[1]<y[1];
}
int  main(){
    int n;
    cin>>n;
    vector<vector<long long>> arr(n,vector<long long>(3)); 
    for(int i=0;i<n;i++)
    {
        cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
    }
    sort(arr.begin(),arr.end(),[&](auto &x,auto &y)
    {
        return x[1]<y[1];    
    });
    vector<int> end(n);
    for(int i=0;i<n;i++)
    {
        end[i]=arr[i][1];
    }
    vector<long long> dp(n);
    dp[0]=arr[0][2];
    for(int i=1;i<n;i++)
    {
        long long profit=arr[i][2];
        int j=lower_bound(end.begin(),end.end(),arr[i][0])-end.begin()-1;
        if(j>=0) profit+=dp[j];
        dp[i]=max(dp[i-1],profit);
    }
    cout<<dp[n-1];


}
