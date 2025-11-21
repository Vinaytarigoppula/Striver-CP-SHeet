#include <bits/stdc++.h>
using namespace std;
string s;
long long m;
unordered_map<long long,long long> mpp;
map<vector<int>,map<long long,long long>> dp;
long long helper(vector<int> countk,bool zero,long long curr)
{
    long long total=0;
    for(long long i=0;i<10;i++) total+=countk[i];
    if(total==0) return curr==0?1:0;
    if(dp.count(countk)>0 && dp[countk].count(curr))
    {
        return dp[countk][curr];
    }
    long long ways=0;
    for(long long i=0;i<=9;i++)
    {
        if(countk[i]>0)
        {
            if(zero && i==0) continue;
            countk[i]--;
            long long newcurr=(curr*10 + i)%m;
            ways+=helper(countk,false,newcurr);
            countk[i]++;
        }
    }
    if(!zero)
    {
        dp[countk][curr]=ways;
    }
    return ways;
}
int main(){
    cin>>s>>m;
    vector<int> countk(10,0);
    for(long long i=0;i<s.size();i++) countk[s[i]-'0']++;
    long long ans=helper(countk,true,0);
    cout<<ans<<endl;

}