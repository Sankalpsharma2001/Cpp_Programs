#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define FAST ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;
#define d 256
void search(string s1,string s2,int q)
{
    int m=s2.length();
    int n=s1.length();
    int p=0; //hash value for pattern
    int t=0,h=1,i,j;
 for( i=0;i<m-1;i++)
 {
     h=(h*d)%q;

 }
 for( i=0;i<m;i++)
 {
     t=(d*t+s1[i])%q;
     p=(d*p+s2[i])%q;
 }
 for( i=0;i<n-m;i++)
 {
     if(p==t)
     {
         bool flag=true;
         for( j=0;j<m;j++)
         {
             if(s1[i+j]!=s2[j])
             {
                 flag=false;
                 break;

             }
         }
         if(j==m)
         cout<<"Pattern is found at index:"<<i<<endl;
     }
     if(i<n-m)
     {
         t=(d*(t-s1[i]*h)+s1[i+m])%q;
         if(t<0)
         t=t+q;
     }
 }
} 
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout<<"Enter text:";
string s1,s2;
cin>>s1;
cout<<"Enter pattern to search:";
cin>>s2;
int q=101;
search(s1,s2,q);

return 0;
}