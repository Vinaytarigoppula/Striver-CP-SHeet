#include <bits/stdc++.h>
using namespace std;
string k="QAQ";
int helper(int i,int j,string s,int cnt)
{
    if(cnt==3) return 1;
    if(i>=s.size()) return 0;
    int take=0;
    if(s[i]==k[j]) take=helper(i+1,j+1,s,cnt+1);
    int nottake=helper(i+1,j,s,cnt);
    return take+nottake;
}
int main(){
    string s;
    cin>>s;
    cout<<helper(0,0,s,0);
}