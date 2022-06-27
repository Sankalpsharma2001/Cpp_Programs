#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pb push_back
#define ff first
#define ss second
#define FAST ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;
void shortest(vector<int> adj[],int src,int dis[],int v)
{
    
    queue<int> q;
    dis[src]=0;
    q.push(src);
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        for(auto it:adj[node])
        {
            if(dis[node]+1<dis[it])
            {
                dis[it]=dis[node]+1;
                q.push(it);
            }
        }
    }
   
} 
int main()
{
FAST;
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

int v,e;
cin>>v>>e;
vector<int> adj[v];
for(int i=0;i<e;i++)
{
    int a,b;
    cin>>a>>b;
    adj[a].pb(b);
    adj[b].pb(a);
}
int src=0,dest=3;
int dis[v];
for(int i=0;i<v;i++) dis[i]=INT_MAX;
shortest(adj,src,dis,v);
 for(int i=0;i<v;i++)
    cout<<dis[i]<<" ";

return 0;
}