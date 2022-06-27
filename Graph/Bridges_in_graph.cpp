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
void IOS()
{
 ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
   #ifndef ONLINE_JUDGE 
  #endif
}
#define FAST ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

const  ll mod = 1e9 + 7;
const  ll  inf = 1e16;
const  ll N = 2e5 + 10;
void dfs(int node,int parent,vector<int> &vis,vector<int> &time,vector<int> &low,int &timer,vector<int> adj[]) 
{
    vis[node]=1;
    time[node]=low[node]=timer++;
    for(auto it:adj[node])
    {
        if(it==parent) continue;
        if(!vis[it])
        {
          dfs(it,node,vis,time,low,timer,adj);
          low[node]=min(low[node],low[it]);
          if(low[it]>time[node])
          {
              cout<<node<<" "<<it<<endl;
          }

        } 
        else
        low[node]=min(low[node],time[it]);
    }
}
int main()
{
IOS();
FAST;
ll n,m;
cin>>n>>m;
vector<int> adj[n+1];
for(int i=0;i<m;i++)
{
    int u,v;
    cin>>u>>v;
    adj[u].pb(v);
    adj[v].pb(u);
}
vector<int> time(n+1,-1);
vector<int> low(n+1,-1);
vector<int> vis(n+1,0);
int timer=0;
for(int i=1;i<=n;i++)
{
    if(!vis[i])
    {
        dfs(i,-1,vis,time,low,timer,adj);
    }
}
return 0;
}