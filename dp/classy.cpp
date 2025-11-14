#include <bits/stdc++.h>
using namespace std;
string s;
vector<vector<vector<long long>>> dp;
long long helper(int pos,bool bound,int cnt)
{
    if(pos==s.size()) return 1;
    int key=bound?1:0;
    if(dp[pos][key][cnt]!=-1) return dp[pos][key][cnt];
    int maxi=-1;
    if(bound) maxi=s[pos]-'0';
    else maxi=9;
    long long ans=0;
    for(int i=0;i<=maxi;i++)
    {
        int updatecnt=cnt+(i>0?1:0);
        if(updatecnt<=3)
        {
            ans+=helper(pos+1, bound & (i==s[pos]-'0'),updatecnt);
        }
    }
    dp[pos][key][cnt]=ans;
    return ans;
}
int main()
{
    int t;
    cin>>t;
    int k=t;
    vector<long long> ans;
    while(t-->0)
    {
        long long l,r;    
        cin>>l>>r;
        s=to_string(r);
        dp.assign(20 , vector<vector<long long>>(2, vector<long long>(4,-1)));
        long long ans1 = helper(0,true,0);
        s=to_string(l-1);
        dp.assign(20 , vector<vector<long long>>(2, vector<long long>(4,-1)));
        long long ans2=helper(0,true,0);
        ans.push_back(abs(ans1-ans2));
    }
    int ind=0;
    while(k-->0)
    {
        cout<<ans[ind]<<endl;
        ind++;
    }
}