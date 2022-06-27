#include <iostream>
#include<bits/stdc++.h>

using namespace std;
vector<int> intime,outtime;
int timer=0;
void dfs(int src,vector<int> adj[],vector<int> &vis)
{   intime[src]=timer++;
	vis[src]=1;
	for(auto x:adj[src])
	{
		if(!vis[x])
		dfs(x,adj,vis);
	}
	outtime[src]=timer++;
}
bool check(int x,int y)
{
	if(intime[x]>intime[y] and outtime[x]<outtime[y])
	return true;
	return false;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	intime.resize(n+1);
	outtime.resize(n+1);
	vector<int> adj[n+1];
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	vector<int> vis(n+1,0);
	dfs(1,adj,vis);
	int q;
	cin>>q;
	for(int i=0;i<q;i++)
	{
		int m;
		cin>>m;
		int x,y;
		cin>>x>>y;
		if(!check(x,y) and !check(y,x))
        {
          cout<<"NO\n";
		  continue;
		}
		if(m==0)
		{
			if(check(y,x))
			cout<<"YES\n";
			else
			cout<<"NO\n";
		}
		else
		{
			if(check(x,y))
			cout<<"YES\n";
			else
			cout<<"NO\n";
		}
	}
	return 0;
}