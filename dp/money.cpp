#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    int sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        sum+=arr[i];
    }
    vector<bool> dp(sum+1);
    dp[0]=true;
    int cnt=0;
    for(int i:arr)
    {
        for(int j=sum;j>=i;j--)
        {
            if(dp[j-i])
            {
                dp[j]=true;
                
            }
        }
    }

    for(int i=1;i<=sum;i++) if(dp[i]) cnt++;
    cout<<cnt<<endl;
    for(int i=1;i<=sum;i++)
    {
        if(dp[i]) 
        {
            cout<<i<<" ";
        }
    }
}