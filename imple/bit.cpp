#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    int cnt=0;
    for(int i=0;i<t;i++)
    {
        string s;
        cin>>s;
        for(int j=0;j<s.size();j++)
        {
            if(s[j]=='x') continue;
            else if(s[j]=='+')
            {
                cnt++;
                break;
            }
            else if(s[j]=='-')
            {
                cnt--;
                break;
            }
        }
    }
    cout<<cnt;
}