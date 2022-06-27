// inserting element in a sorted linked list
#include <iostream>
using namespace std;
struct Node{
    int data;
     Node *next;
}*first=NULL; 
void create(int a[],int n){
     Node *t,*last;
    first=new Node;
    first->data=a[0];
    first->next=NULL;
    last=first;
    for(int i=1;i<n;i++){
        t=new  Node;
        t->data=a[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
void insert(struct Node *p,int x){
    Node *q=NULL,*t;
     t=new Node;
    t->data=x;
    t->next=NULL;
    if(first==NULL)
    first=t;
    else
    {
       while(p&&x>p->data){
        q=p;
        p=p->next;
                 }
        if(p==first){
         t->next=first;
         first=t;
                    }
         else{
             t->next=q->next;
             q->next=t;
             }
    }
   
}
void display(struct Node *p)
{while(p!=NULL)
  {cout<<p->data<<" ";
    p=p->next;
  }
}
int main()
{ cout<<"enter no ";
 int n;
 cin>>n;
 int a[n];
  cout<<"Enter element in a sorted order";
 for(int i=0;i<n;i++){
     cin>>a[i];
 create(a,n);
 }cout<<"element to insert:";
 int e;
 cin>>e;
 Node *r;
 insert(first,e);
 display(first);
    return 0;
}

