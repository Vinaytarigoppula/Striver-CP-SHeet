#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,x;
    cin>>n>>x;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    int N=1<<n;
    vector<pair<int,long long>> dp(N,{1e9,1e9});

    dp[0]={1,0};
    for(int i=0;i<N;i++)
    {
        pair<int,long long> pre=dp[i];
        for(int j=0;j<n;j++)
        {
            if(i & (1<<j)) continue;
            int newmask=i | (1<<j);
            pair<int,long long> newstate;
            if(pre.second+arr[j]<=x)
            {
                newstate={pre.first,pre.second+arr[j]};
            }
            else
            {
                newstate={pre.first+1,arr[j]};
            }
            if(newstate<dp[newmask])
            {
                dp[newmask]=newstate;
            }
        }
    }
    
        cout<<dp[N-1].first<<endl;
}