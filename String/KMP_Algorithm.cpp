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
 
ll mypow(ll a, ll b) {
ll res = 1;
while (b > 0) {
if (b & 1)
res = res * a;
a = a * a;
b >>= 1;
}
return res;
}
ll mypow(ll a, ll b, ll m) {
a %= m;
ll res = 1;
while (b > 0) {
if (b & 1)
res = res * a % m;
a = a * a % m;
b >>= 1;
}
return res;
}
const  ll mod = 1e9 + 7;
const  ll  inf = 1e16;
const  ll N = 2e5 + 10;
vector<int> prefix_function(string s)
{
    vector<int> lps(s.size(),0);
    lps[0]=0;
    int len=0,i=1;
    while(i<s.size())
    {
       if(s[i]==s[len])
       {
        lps[i]=len+1;
        len++,i++;
       }
       else
       {
        if(len!=0)
        {
            len=lps[len-1];
        }
        else
        {
            lps[i]=0;
            i++;
        }
       }
    }
    // for(int i=1;i<s.size();i++)
    // {
    //     int j=pre[i-1];
    //     while(j>0 and s[i]!=s[j])
    //     j=pre[j-1];
    //     if(s[i]==s[j])
    //     j++;
    //     pre[i]=j;
    // }
    return lps;
} 
int main()
{
IOS();
FAST;
ll t;
cin>>t;
while(t--)
{
 string a,b;
 cin>>a>>b;
 vector<int> pif=prefix_function(a);
//  for(int i=0;i<pif.size();i++) cout<<pif[i]<<" ";
//  for(int i=0;i<pif.size();i++)
//  cout<<pif[i]<<" ";
 int pos=-1;
 int i=0,j=0;
 while(j<b.size())
 {
     if(b[j]==a[i])
     {
         i++;
         j++;
     }
     else
     {
         if(i!=0)
         i=pif[i-1];
         else
         j++;
     }
     if(i==a.size())
     {
         pos=j-a.size();
         break;
     }

 }
 cout<<pos<<endl;
}
return 0;
}