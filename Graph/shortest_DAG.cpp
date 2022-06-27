#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pb push_back
#define ff first
#define ss second
#define FAST ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;
void findtopo(int node,int vis[],stack<int> &st,vector<pair<int,int>> adj[])
{
vis[node]=1;
for(auto it:adj[node])
{
    if(!vis[it.first])
    {
findtopo(it.first,vis,st,adj);
    }
}
st.push(node);
}
void shortest(int src,int v,vector<pair<int,int>> adj[])
{
    int vis[v]={0};
    stack<int> st;
    for(int i=0;i<v;i++)
    {
        if(!vis[i])
        findtopo(i,vis,st,adj);
    }
    int dis[v];
    for(int i=0;i<v;i++) dis[i]=1e9;
    dis[src]=0;
    while(!st.empty())
    {
        int node=st.top();
        st.pop();
        if(dis[node]!=1e9)
        {
        for(auto it:adj[node])
        {
            if(dis[node]+it.second<dis[it.first])
            dis[it.first]=dis[node]+it.second;
        }
        }
    }
    for(int i=0;i<v;i++)
    {
        (dis[i]==1e9)?cout<<"INF "<<" ":cout<<dis[i]<<" ";
    }
} 
int main()
{
FAST;
ll t;
cin>>t;
while(t--)
{
    int v,e;
    cin>>v>>e;
    vector<pair<int,int>> adj[v];
    for(int i=0;i<v;i++)
    {
        int a,b,w;
        cin>>a>>b>>w;
     adj[a].pb({b,w});
    }
shortest(0,v,adj);
}
return 0;
}