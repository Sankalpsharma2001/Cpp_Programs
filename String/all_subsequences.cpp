#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int, int>
#define pll pair<ll, ll>
#define vpi vector<pi>
#define vpll vector<pll>
#define sz(x) ((int)(x).size())
#define prec(n) fixed<<setprecision(n)
#define maxpq priority_queue<int>
#define minpq priority_queue<int, vector<int>, greater<int>>
#define  uniq(a) a.resize(unique(a.begin(), a.end()) - a.begin());
#define all(x)      (x).begin(), (x).end()
#define inp(x) for(ll&i:x) cin>>i;
void IOS()
{
 ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
   #ifndef ONLINE_JUDGE 
  #endif
}
#define FAST ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
string solve(string s,int x,int n)
{
    string sub="";
    for(int i=0;i<n;i++)
    {
        if(x&(1<<i))
        sub+=s[i];
    }
    return sub;
} 
void print(string input,string output)
{
    if(input.empty())
    {cout<<output<<endl;
    return;}
    
    // output is passed with including
    // the Ist character of
    // Input string
    //cout<<input<<" "<<output<<" "<<endl;
    print(input.substr(1),output+input[0]);
      // output is passed without
    // including the Ist character
    // of Input string
    print(input.substr(1), output);
}
int main()
{
IOS();
FAST;
ll t;
cin>>t;
while(t--)
{
 string s;
 cin>>s;
 string output="";
 string input=s;

 print(input,output);
//METHOD OF USING BINARY 
//  map<int,set<string>> m;
//  int n=s.size();
//  int total=(pow(2,n)-1);
//  for(int i=1;i<=total;i++)
//  {
//      string sub=solve(s,i,n);
//      m[sub.size()].insert(sub);
//  }
//  for(auto x:m)
//  {
//      cout<<"String of length "<<x.ff<<" is:";
//       for(auto y:x.ss)
//       cout<<y<<" ";
//       cout<<endl;
//  }
}
return 0;
}