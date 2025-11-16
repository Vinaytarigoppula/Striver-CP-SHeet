#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    int sum=0,cnt=0,maxi=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==0) sum++;
        else 
        {
            cnt++;
            sum--;
        }
        if(sum>maxi) maxi=sum;
        if(sum<0) sum=0;

    }
    cout<<maxi+cnt<<endl;
}