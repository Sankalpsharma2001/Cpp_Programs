// https://codeforces.com/edu/course/2/lesson/4/2/practice/contest/273278/problem/B
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
#define f(i,x,n) for(ll i=x;i<n;i++)
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
vector<int> a(N),seg(4*N);
void build(int node,int st,int end)
{
    if(st==end)
    {
        seg[node]=a[st];
        return;
    }
    int mid=(st+end)/2;
    build(2*node+1,st,mid);
    build(2*node+2,mid+1,end);
    seg[node]=seg[2*node+1]+seg[2*node+2];

}
void update(int node,int st,int end,int idx)
{
    if(st==end)
    {
        if(a[st]==0)
        {
            a[st]=1;
            seg[node]=1;
        }
        else
        {
            a[st]=0;
            seg[node]=0;
        }
        return;
    }
    int mid=(st+end)/2;
    if(idx<=mid)
    {
        update(2*node+1,st,mid,idx);
    }
    else
    {
        update(2*node+2,mid+1,end,idx);
    }
    seg[node]=seg[2*node+1]+seg[2*node+2];
}
int query(int node,int st,int end,int k)
{
    if(st==end)
    {
        return st;
    }
    int mid=(st+end)/2;
    if(k<seg[2*node+1])
    {
        return query(2*node+1,st,mid,k);
    }
    else
    {
     return query(2*node+2,mid+1,end,k-seg[2*node+1]);
    }
}
int main()
{
IOS();
FAST;
ll n,m;
cin>>n>>m;
for(int i=0;i<n;i++)
{
    int x;
    cin>>x;
    a[i]=x;
}
build(0,0,n-1);
for(int i=0;i<m;i++)
{
    int type;
    cin>>type;
    if(type==1)
    {
      int idx;
      cin>>idx;
      update(0,0,n-1,idx);
    }
    else
    {
       int k;
       cin>>k;
       cout<<query(0,0,n-1,k)<<endl;
    }
}
return 0;
}