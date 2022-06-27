//not link both
#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
using namespace std;
struct Node{
    int data;
    struct Node *next;
}*first=NULL,*second=NULL; 
void create(int a[],int n){
    int i;
    struct Node *t,*last;
    first=new struct Node;
    first->data=a[0];
    first->next=NULL;
    last=first;
    for(int i=1;i<n;i++){
        t=new struct Node;
        t->data=a[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
void create1(int a[],int n){
    int i;
    struct Node *t,*last;
    second=new struct Node;
    second->data=a[0];
    second->next=NULL;
    last=second;
    for(int i=1;i<n;i++){
        t=new struct Node;
        t->data=a[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
int length(struct Node *head)
{
    int len=0;
    while(head)
    {
        len++;
        head=head->next;
    }
return len;
}

struct Node* findmerge(struct Node *head1,struct Node *head2)
{//Method 1
 int m=length(head1);
 int n=length(head2);
 struct Node *b=head2,*a=head1;
 for(int i=0;i<m;i++)
 {b=head2;
     for(int j=0;j<n;j++)
     {
        if(a==b) return a;
        b=b->next;
     }
     a=a->next;

 }
 return NULL;
}
int intersectPoint(Node* head1, Node* head2)
{
    //method 2
  
   /* if(head1==NULL || head2==NULL)
{
return -1;
}
Node *a=head1;
Node *b=head2;
while(a!=b)
{
a=a==NULL?head2:a->next;
b=b==NULL?head1:b->next;
}
return a->data;*/

//method 3
/*int n = 0, m = 0;
Node *h1 = head1, *h2 = head2;
while(h1 != NULL){
n++;
h1 = h1->next;
}
while(h2 != NULL){
m++;
h2 = h2->next;
}

h1 = head1;
h2 = head2;

if(n > m){
int k = n-m;
while(k--){
h1 = h1->next;
}
}
else if(n < m){
int k = m-n;
while(k--){
h2 = h2->next;
}
}


while(h1 != NULL && h2 != NULL){
if(h1 == h2){
return (h1->data);
}
h1 = h1->next;
h2 = h2->next;
}
return -1;*/
}
int main()
{ 
ios_base::sync_with_stdio(false);
cin.tie(NULL);
 int a[5]={8,2,3,4,5};
    create(a,5);
   int b[4]={1,9,4,5};
   create1(b,4);
 struct Node *ans=findmerge(first,second);
 cout<<ans;
return 0;
}