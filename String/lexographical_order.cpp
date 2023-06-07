#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
using namespace std;
void lexico(int x,int n)
{
    if(x>n)
    return;
    if(x==n)
    {
        cout<<x<<endl;
        return;
    }
    if(x!=0)
    {
        cout<<x<<endl;
    }
    for(int i=(x==0)?1:0;i<=9;i++)
    {
        lexico(10*x+i,n);
    }
}
int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
int n;
cin>>n;
lexico(0,n);
/*vector<string> s;
for(int i=1;i<=n;i++)
{
    s.push_back(to_string(i));
}
sort(s.begin(),s.end());
vector<int> ans;
for(int i=0;i<n;i++)
ans.push_back(stoi(s[i]));
for(int i=0;i<n;i++)
cout<<s[i]<<" ";*/
return 0;
}