#include <bits/stdc++.h>
using namespace std;
int k;
int ans=0;
int mini=INT_MAX;
int helper(int i,vector<int> arr)
{

    int sum=0;
    for(int j=i;j<i+k;j++)
    {
        sum+=arr[j];
    }
    if(mini>sum)
    {
        ans=i;
    }ll
}
int main(){
    int n;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    
}