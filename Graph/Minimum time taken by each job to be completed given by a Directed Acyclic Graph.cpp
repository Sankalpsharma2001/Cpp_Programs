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
int main()
{
ll n,e;
cin>>n>>e;
vector<int> adj[n+1];
for(int i=0;i<e;i++)
{
    ll a,b;
    cin>>a>>b;
    adj[a].pb(b);
}
vector<int> indegree(n+1,0);
for(int i=1;i<=n;i++)
{
    for(auto x:adj[i])
    {
        indegree[x]++;
    }
}
queue<int> q;
vector<int> ans(n+1,0);
for(int i=1;i<=n;i++)
{
    if(indegree[i]==0)
    {q.push(i);
    ans[i]=1;}
}
while(!q.empty())
{
    int sz=q.size();
    while(sz--)
    {
        auto f=q.front();
        q.pop();
        for(auto it:adj[f])
        {
            indegree[it]--;
            if(indegree[it]==0)
             {q.push(it);
             ans[it]=ans[f]+1;
             }

        }
    }
}
for(int i=1;i<=n;i++)
{
cout<<ans[i]<<" ";x`
 
}
return 0;
}