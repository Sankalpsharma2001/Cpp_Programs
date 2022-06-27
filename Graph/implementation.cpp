#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pb push_back
#define ff first
#define ss second
#define FAST ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define endl "\n" 
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
using namespace std;
class Graph{
    public:
    int v;
    unordered_map<string,vector<string>> adj;
    Graph(int ver)
    {
    this->v=ver;
    }
    void Addedge(string x,string y)
    {
        adj[x].pb(y);
        adj[y].pb(x);
    }
    void print()
    {
        for(auto p:adj)
        {
            cout<<p.ff<<" --->";
            for(auto q:p.ss)
            cout<<q<<" ";
            cout<<endl;
        }
    }
}; 
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int v,e;
cin>>v>>e;
Graph G(v);
for(int i=0;i<e;i++)
{
    string s,s1;
    cin>>s>>s1;
    G.Addedge(s,s1);
}
G.print();
return 0;
}