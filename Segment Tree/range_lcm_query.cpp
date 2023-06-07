#include <bits/stdc++.h>
using namespace std;
#define ll long long 
ll a[100005],seg[4*100005];
int lcm(int a,int b)
{
    return (a*b)/__gcd(a,b);
}
void buildTree(int node,int low,int high)
{
    if(low==high)
    {
        seg[node]=a[low];
        return;
    }
    int mid=low+(high-low)/2;
    buildTree(2*node+1,low,mid);
    buildTree(2*node+2,mid+1,high);
    int left=seg[2*node+1];
    int right=seg[2*node+2];
    seg[node]=lcm(left,right);
}
int query(int node,int low,int high,int st,int end)
{
  if(low>=st and high<=end)
  {
    return seg[node];
  }
  if(low>end || high<st)
  {
    return 1;
  }
  int mid=low+(high-low)/2;
  int left=query(2*node+1,low,mid,st,end);
  int right=query(2*node+2,mid+1,high,st,end);
  return lcm(left,right);
}
int main()
{ 
    ll n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    cin>>a[i];
    buildTree(0,0,n-1);
    while(m--)
    {
        int st,end;
        cin>>st>>end;
        cout<<query(0,0,n-1,st,end)<<endl;
    }
    return 0;
}