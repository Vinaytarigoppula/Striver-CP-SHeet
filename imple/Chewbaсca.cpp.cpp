#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long num;
    cin>>num;
    string s=to_string(num);
    string res;
    int i=0;
    if(s[0]=='9')
    {
        res+=s[i];
         i++;
    }
    for(i;i<s.size();i++)
    {
        if(s[i]-'0'>=5)
        {
            res+=to_string((9-(s[i]-'0')));
        }
        else res+=s[i];
    }
    cout<<res;
}