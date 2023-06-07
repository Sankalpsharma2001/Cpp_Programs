//Maximum length of longest increasing contiguous subarray after deleting exactly one element from array
/*https://www.geeksforgeeks.org/maximum-length-of-longest-increasing-contiguous-subarray-after-deleting
-exactly-one-element-from-array/*/
#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pb push_back
#define ff first
#define ss second
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
using namespace std;
 
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
int n;
cin>>n;
vl a(n);
for(int i=0;i<n;i++)cin>>a[i];
vector<int> front(n,1),back(n,1);
for(int i=1;i<n;i++)
{
    if(a[i]>a[i-1])
    front[i]=front[i-1]+1;
}

for(int i=n-2;i>=0;i--)
{
    if(a[i]<a[i+1])
    back[i]=back[i+1]+1;
}

int f=0;
for(int i=0;i<n;i++)
f=max(f,front[i]);
int b=0;
for(int i=0;i<n;i++)
b=max(b,back[i]);
int ans=max(f,b);
for(int i=0;i<n-2;i++)
{
    if(a[i]<a[i+2])
    ans=max(ans,front[i]+back[i+2]);
}
cout<<ans<<endl;
return 0;
}
