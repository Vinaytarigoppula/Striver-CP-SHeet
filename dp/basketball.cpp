#include <bits/stdc++.h>
using namespace std;
vector<vector<long long>> dp;
long long helper(long long i,long long cnt,vector<long long>& a,vector<long long>& b)
{
    
    if(i>=a.size()) return 0;
    if(dp[i][cnt]!=-1) return dp[i][cnt];
    long long take=0,nottake=0;
    if(cnt==0)
    {
        take=a[i]+helper(i+1,1,a,b);
        nottake=helper(i+1,0,a,b);
    }
    else{
        take=b[i]+helper(i+1,0,a,b);
        nottake=helper(i+1,1,a,b);
    }
    return dp[i][cnt]=max(take,nottake);

}   
int main(){
    long long n;
    cin>>n;
    dp.assign(n+1,vector<long long>(2,-1));
    vector<long long> a(n);
    vector<long long> b(n);
    for(long long i=0;i<n;i++) cin>>a[i];
    for(long long i=0;i<n;i++) cin>>b[i];
    long long ans1=helper(0,0,a,b);
    long long ans2=helper(0,1,a,b);
    cout<<max(ans1,ans2);
}