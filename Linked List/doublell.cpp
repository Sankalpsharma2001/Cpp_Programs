#include <iostream>
using namespace std;
struct Node{
    Node *pre;
    int data;
    Node *next;
}*first=NULL;
void create(int a[],int n){
    struct Node *t,*last;
    first=new Node;
    first->data=a[0];
    first->pre=first->next=NULL;
    last=first;
    for(int i=1;i<n;i++)
    { t=new Node;
      t->data=a[i];
      t->next=last->next;
      t->pre=last;
      last->next=t;
      last=t;
    }
}
int length(struct Node *p){
    int count=0;
    while(p){
        count++;
        p=p->next;
    }
    return count;
}
void insert(Node *p,int value,int index){
    Node *t;
  if(index>length(p)||index<0)
  return;
    if(index==0)
    { t=new Node;
     t->pre=NULL;
      t->data=value;
      t->next=first;
      first->pre=t;
        first=t;
    }
    else{
        Node *p=first;
        t=new Node;
        t->data=value;
        for(int i=0;i<index-1;i++)
        { 
            p=p->next;
        }
        t->next=p->next;
        t->pre=p;
        if(p->next!=NULL)
        {
        p->next->pre=t;}
       p->next=t;
        
    }
}
void Delete1(struct Node *p,int index)
{

int x=-1,i;
if(index < 0 || index > length(p))
return ;
if(index==0)
{
first=first->next;
if(first)first->pre=NULL;
x=p->data;
free(p);
}
else
{
for(i=0;i<index;i++)
p=p->next;
p->pre->next=p->next;
if(p->next)
p->next->pre=p->pre;
x=p->data;
free(p);
}
}
void Delete(Node *p,int index){ // by using p only we can also do
 p=first;
 Node *q=NULL;
  if(index>=length(p)||index<0)
  return;
 if(index==0)
 { q=p;
     p=p->next;
       first=p;
       first->pre=NULL;
       delete q;
 }
 else
 {
     for(int i=0;i<index;i++)
     {
         q=p;
         p=p->next;
     }
     q->next=p->next;
     if(p->next!=NULL)
     p->next->pre=q;
     delete p;
 }
}
void Reverse(Node *p){
    p=first;
    Node *temp;
    while(p){
     temp=p->next;
     p->next=p->pre;
     p->pre=temp;
     p=p->pre;
     if(p!=NULL&&p->next==NULL) 
     {
         first=p;
     }
    }
    
}
void display(Node *p){
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
}
int main()
{
    int a[]={1,2,4,6,5};
    create(a,5);
   // insert(first,3,4);
    //Delete(first,0);
    Delete1(first,0);
   // Reverse(first);
    display(first);
    cout<<endl<<"The length of doubly linked list-"<<length(first);
    return 0;
}


