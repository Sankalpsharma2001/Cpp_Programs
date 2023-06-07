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
void IOS()
{
 ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
   #ifndef ONLINE_JUDGE 
  #endif
}
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
const double PI=3.1415926535897932384626433832795;
const  ll mod = 1e9 + 7;
const  ll  inf = 1e16;
const  ll N = 2e5 + 10;
bool check(int n,int a[])
{
    int c=0;
    for(int i=0;i<n;i++)
   {
    if(a[i]==9)
    c++;
   }
   return c==n;

}
void nextpalindrome(int n,int num[])
{
       int mid = n / 2;
 
   bool leftsmaller = false;
 
    int i = mid - 1;
 
    int j = (n % 2) ? mid + 1 : mid;
 
    while (i >= 0 && num[i] == num[j])
        {i--, j++;}
 
    if (i < 0 || num[i] < num[j])
        leftsmaller = true;
 
    while (i >= 0)
    {
        num[j] = num[i];
        j++;
        i--;
    }
 
    if (leftsmaller == true)
    {
        int carry = 1;
        i = mid - 1;
 
        if (n % 2 == 1)
        {
            num[mid] += carry;
            carry = num[mid] / 10;
            num[mid] %= 10;
            j = mid + 1;
        }
        else
            j = mid;
 
        while (i >= 0)
        {
            num[i] += carry;
            carry = num[i] / 10;
            num[i] %= 10;
             
            num[j++] = num[i--];
        }
    }
}

 void solve() 
{
    int n;
    cin>>n;
    int num[n];
    for(int i=0;i<n;i++)
    cin>>num[i];
 
 
 if(check(n,num))
 {
    cout<<"1 ";
    for(int i=0;i<n-1;i++)
    cout<<"0 ";
    cout<<"1 ";
  }
 else
 {
   nextpalindrome(n,num);
   for(int i=0;i<n;i++)
   cout<<num[i]<<" ";

 }

}
int main()
{
IOS();
FAST;
ll t;
cin>>t;
while(t--)
{
// cout << "Case #" << t << ": ";
solve();
cout<<endl;
}
return 0;
}