#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t-->0)
    {
        int n;
        cin>>n;
        vector<int> arr(n);
        vector<int> ans(n);
        
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        int cream=0;
        for(int i=n-1;i>=0;i--)
        {
            cream=max(cream,arr[i]);
            if(cream>0) ans[i]=1;
            cream--;
        }
        for(int i:ans)
        {
            cout<<i<<" ";
        }
        cout<<endl;
        
    }
}