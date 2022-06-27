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

void reverse_list(){
    Node *current=first,*prev=NULL,*next=NULL;
    while(current!=NULL){
    // Store next
next = current->next;
// Reverse current node's pointer
current->next = prev;
// Move pointers one position ahead
prev = current;
current = next;}
first=prev;
}

void Reverse(){
    Node *p=first,*q=NULL,*r=NULL;
    while(p!=NULL){
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;
}
void Recursive_reverse(Node *q,Node *p){
    if(p!=NULL)
    {
        Recursive_reverse(p,p->next);
        p->next=q;
    }
    else
    first=q;
}
/*void Reverse1(struct Node *p)
{
int *A,i=0;
struct Node *q=p;

A=(int *)malloc(sizeof(int)*count(p));
while(q!=NULL)
{
A[i]=q->data;
q=q->next;
i++;
}
q=p;
i--;
while(q!=NULL)
{
q->data=A[i];
q=q->next;
i--;}
    
}*/
void display(struct Node *p)
{while(p!=NULL)
  {cout<<p->data<<" ";
    p=p->next;
  }
}

int main()
{ int n;
cin>>n;
int a[n];
for(int i=0;i<n;i++)
cin>>a[i];
create(a,n);
//reverse_list();
Reverse();
//Recursive_reverse(NULL,first);
cout<<endl<<"After reverse"<<endl;
display(first);
    return 0;
}


