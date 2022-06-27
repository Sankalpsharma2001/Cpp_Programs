#include <iostream>
using namespace std;
struct Node{
    int data;
    struct Node *next;
}*first=NULL; 
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
struct Node * delete_firstelement(struct Node * first){
   struct Node *ptr=first;
    first=first->next;
    delete ptr;
    return first;
}
struct Node *delete_atindex(struct Node * first,int index){
    struct Node *p=first;
    Node *q=first->next;
for(int i=0;i<index-1&&index<5;i++){
        p=p->next;
        q=q->next;
    }
   if(index<5){ 
    p->next=q->next;
    delete q;
    return first;}
    return first;
}
struct Node *delete_end(struct Node *first){
    struct Node *p=first;
    struct Node *q=first->next;
    while(q->next!=NULL){
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    delete q;
    return first;
}
struct Node *delete_atgivenvalue(struct Node *first,int value){
    Node *p=first;
    Node *q=first->next;
    while(q->data!=value&&q->next!=NULL){
        p=p->next;
        q=q->next;
    }
    if(q->data==value){
    p->next=q->next;
    delete q;
    return first;}
    else 
    return first;
}
int Delete(struct Node *p,int index)
{
struct Node *q=NULL;
int x=-1,i;
if(index < 1)
return -1;
if(index==1)
{
q=first;
x=first->data;
first=first->next;
free(q);
return x;
}
else
{
for(i=0;i<index-1;i++)
{
q=p;
p=p->next;
}
q->next=p->next;
x=p->data;
delete p;
return x;

}

}
void display(struct Node *p){
    while(p!=NULL)
    {cout<<p->data;
    p=p->next;
    }
}
int main(){
    int a[5]={1,2,3,4,5};
    create(a,5);
    cout<<"Original Linked list-";
     display(first);cout<<endl;
  //  delete_firstelement(first);
  //delete_atindex(first,2);
  //delete_end(first);
  //delete_atgivenvalue(first,4);
 Delete(first,2);
     display(first);
    return 0;
}

