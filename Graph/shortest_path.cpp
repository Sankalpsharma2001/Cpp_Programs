#include<bits/stdc++.h>
using namespace std;
void bfs(vector<int> adj[],int n,int src)
{
  queue<int> q;
  vector<bool> vis(n+1);
  vector<int> dis(n+1);
  vector<int> par(n+1);
  for(int i=0;i<n;i++)
  {
      dis[i]=INT_MAX;
      par[i]=-1;
      vis[i]=false;
  }
  dis[src]=0;
  vis[src]=true;
  
  q.push(src);
  while(!q.empty())
  {
      auto p=q.front();
      q.pop();
      for(auto c:adj[p])
      {
          if(!vis[c])
          {vis[c]=true;
              if(dis[c]<dis[p]+1)
              {
            
            dis[c]=dis[p]+1;
            q.push(c);
            par[c]=p;
              }
          }
      }
  }
vector<int> path;
int s=7;
path.push_back(s);
while(par[s]!=-1)
{  path.push_back(par[s]);
    s=par[s];
}
for(int i=path.size()-1;i>=0;i--)
cout<<path[i]<<" ";
cout<<endl<<dis[7]<<endl;
}

int main()
{ int n,e;
cin>>n>>e;
    vector<int> adj[n+1];
    for(int i=0;i<e;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int src=5;
    bfs(adj,n,src);
    return 0;
}