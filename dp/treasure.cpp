#include <bits/stdc++.h>
using namespace std;
map<pair<int,int>, int> dp; 
int last;
int helper(int prev,int jump,unordered_map<int,int>& mpp)
{
    if(prev>last) return 0;
    if(dp.count({prev, jump})) return dp[{prev, jump}];
    int ans=0;
    if(mpp.count(prev)>0) ans=mpp[prev];
    if(jump <= 0) return dp[{prev,jump}] = ans;   // required!
    int t1=helper(prev+jump-1,(jump-1),mpp);
    int t2=helper(prev+jump,(jump),mpp);
    int t3=helper(prev+jump+1,(jump+1),mpp);
    return dp[{prev,jump}] = ans + max(t1, max(t2, t3));
}
int main()
{
    int n,d;
    cin>>n>>d;
    unordered_map<int,int> mpp;
    for(int i=0;i<n;i++)
    {
        int k;
        cin>>k;
        mpp[k]++;
        last=max(last,k);
    }
    int ans=helper(d,d,mpp);
    cout<<ans;
}