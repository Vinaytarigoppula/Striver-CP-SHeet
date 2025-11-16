#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;
    cin>>n>>k;
    vector<int> th(n),t(n);
    for(int i=0;i<n;i++) cin>>th[i];
    for(int i=0;i<n;i++) cin>>t[i];
    vector<int> pref(n+1, 0);
    pref[0]=0;
    vector<int> sleep(n);
    for(int i=0;i<n;i++)
    {
        if(t[i]==0) sleep[i]=th[i];
        else sleep[i]=0; 
    }
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(t[i]==1) cnt+=th[i];
    }
    for(int i=1;i<=n;i++)
    {
        pref[i]=pref[i-1]+sleep[i-1];
    }
    int best=0;
    for(int i=0;i+k<=n;i++)
    {
        int window=pref[i+k]-pref[i];
        best=max(best,window);
    }
    cout<<cnt+best<<endl;
}