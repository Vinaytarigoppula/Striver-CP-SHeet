// https://cses.fi/problemset/task/1674
#include <bits/stdc++.h>
using namespace std;
vector<int> dp[200001];
int m[200001];
int helper(int node)
{
    int cnt=0;
    for(int i:dp[node])
    {
        cnt+=1+helper(i);
    }
    return m[node]=cnt;
}
int main(){
    int n;
    cin>>n;
    for(int i=2;i<=n;i++)
    {
        int boss;
        cin>>boss;
        dp[boss].push_back(i);
    }
    helper(1);
    for(int i=1;i<=n;i++)
    {
        cout<<m[i]<<" ";
    }
}