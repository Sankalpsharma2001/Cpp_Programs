#include <bits/stdc++.h>
using namespace std;
#define ll long long 
ll a[100005],seg[4*100005];
ll sod(ll x)
{
    ll c=0;
    while(x>0)
    {
        c+=(x%10);
        x/=10;
    }
    return c;
}
void buildtree(ll ind,ll low,ll high)
{
    if(low==high)
    {
        seg[ind]=a[low];
        return;

    }
    ll mid=low+(high-low)/2;
    buildtree(2*ind+1,low,mid);
    buildtree(2*ind+2,mid+1,high);
    seg[ind]=(sod(seg[2*ind+1])+sod(seg[2*ind+2]));
}
ll query(int ind,int low,int high,int l,int r)
{
 if(low>=l and high<=r)
 {
    return seg[ind];
 }
 if(high<l || low>r)
 return 0;
 ll mid=low+(high-low)/2;
 ll left=query(2*ind+1,low,mid,l,r);
 ll right=query(2*ind+2,mid+1,high,l,r);
return (left+right);
}
void update(int node,int st,int end,int idx,int val)
{
   
    if(st==end)
    {
        a[st]=val;
        seg[node]=val;
        return;
    }
    int mid=st+(end-st)/2;
    if(idx<=mid)
    {
        update(2*node+1,st,mid,idx,val);
    }
    else
    {
        update(2*node+2,mid+1,end,idx,val);
    }
    seg[node]=(sod(seg[2*node+1])+sod(seg[2*node+2]));
}
void update1(int node,int st,int end,int idx,int dif)
{
  if(idx<st || idx>end)
  return;
  seg[node]=seg[node]+dif;
  if(st<end)
  {
    int mid=st+(end-st)/2;
    update1(2*node+1,st,mid,idx,dif);
    update1(2*node+2,mid+1,end,idx,dif);
  }
}
void updateval(int n,int idx,int val)
{
    int dif=val-a[idx];
    a[idx]=val;
    update1(0,0,n-1,idx,dif);
}
int main()
{ 
    ll n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    cin>>a[i];
    buildtree(0,0,n-1);
    while(m--)
    {
        int type;
        cin>>type;
        if(type==1)
        {
          ll i,v;
          cin>>i>>v;
        //   update(0,0,n-1,i,v);
          updateval(n,i,v);
        }
        else
        {
            ll l,r;
            cin>>l>>r;
           cout<<query(0,0,n-1,l,r-1)<<endl;
        }
    }
    return 0;

}