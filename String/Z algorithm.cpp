#include<bits/stdc++.h>
using namespace std;
// GCC Optimizations
#pragma GCC optimize("Ofast,03")
#pragma GCC target("fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
 
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
#define input(a) for(auto &x:a) cin>>x;
#define print(a) for(auto &x:a) cout<<x<<' ';cout<<'\n';
template<class T> using min_pq = priority_queue<T, vector<T>, greater<T>>;
template<class T> using max_pq = priority_queue<T, vector<T>>;
using namespace std::chrono;

#define f(i,x,n) for(ll i=x;i<n;i++)
void IOS()
{
 ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
   #ifndef ONLINE_JUDGE 
  #endif
}
#define FAST ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

const  ll mod = 1e9 + 7;
const  ll  inf = 1e16;
const  ll N = 2e5 + 10;


vector<int> calculateZ(string &s)
{
    int n = s.size();
    vector<int> z(n);
    z[0] = 0;
   int left=0,right=0;
    for(int k=1;k<s.size();k++)
    {
      if(k>right)
      {
        left=right=k;
        while(right<s.size() && s[right]==s[right-left])
        {
          right++;
        }
        z[k]=right-left;
        right--;
      }
      else
      {
        // we are operating inside box 
        int k1=k-left;
        // if value does not stretches till right bound then just copy it 
        if(z[k1]<right-k+1)
        {
          z[k]=z[k1];
        }
        else
        {
          left=k;
          while(right<s.size() && s[right]==s[right-left])
          {right++;
          }
          z[k]=right-left;
          right--;
        }
      } 
    } 
    return z;   

}
void solve()
{
  string pat,txt;
  cin>>pat>>txt;
  string s=pat+'$'+txt;
  vector<int> z=calculateZ(s);
  vector<int> ans;
  for(int i=0;i<z.size();i++)
  {
    if(z[i]==pat.size())
    {
      ans.push_back(i-pat.size()-1 +1 );
    }
  }
  print(ans);
}

int main()
{
   IOS();
   FAST;
    auto start1 = high_resolution_clock::now();
  solve();
 auto stop1 = high_resolution_clock::now();
 auto duration = duration_cast<microseconds>(stop1 - start1);
  
 int tm=(double)duration.count()/1000;
 cerr << "Time: " << tm << " ms" << endl;
 return 0;
}