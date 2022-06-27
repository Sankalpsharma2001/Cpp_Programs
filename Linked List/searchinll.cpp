#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
   struct node *next;
}*first=NULL;
void create(int a[],int n){
struct node *t=NULL,*last;
first=new node;
first->data=a[0];
first->next=NULL;
last=first;
for(int i=1;i<n;i++)
 { t=new node;
    t->data=a[i];
    t->next=NULL;
    last->next=t;
    last=t;
 }
}
struct node *search(struct node *p,int key){
    struct node *temp=p;
    while(temp!=NULL)
    { 
        if(key==temp->data)
      return temp;
        temp=temp->next;
    }
    return NULL;
}
void Display(struct node *p)
{
while(p!=NULL)
{
cout<<p->data;
p=p->next;
}
}
int Max( node *p){
    int max=INT_MIN;
    while(p)
    {
        if(p->data>max)
        max=p->data;
        p=p->next;
    }
    return max;
}

int main()
{int a[]={1,58,64,23,47,12,4};
struct node *temp;
   create(a,7);
   //Display(first);
   //cout<<Max(first);
 temp=search(first,47);
  if(temp!=0)
  cout<<"Key is found";
  else 
  cout<<"Key not found";
    return 0;
}


