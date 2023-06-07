#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
char str[6]="India";
char s[8]="country";
char ans[20];
char *p1,*p2,*pans;
p1=str;
p2=s;
pans=ans;
while(*p1)
{
    *pans=*p1;
    pans++;
    p1++;

}

*pans=' ';
pans++;
while(*p2)
{
    *pans=*p2;
    pans++;
    p2++;

}
*pans='\0';
cout<<ans;
return 0;
}