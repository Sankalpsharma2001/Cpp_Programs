//Intsertion in a circular linked list
#include <iostream>
using namespace std;
struct Node{
    int data;
    Node *next;
}*head=NULL;
void create(int a[],int n){
    Node *t,*last;
    head=new Node;
    head->data=a[0];
    head->next=head;
    last=head;
    for(int i=1;i<n;i++)
    {
        t=new Node;
        t->data=a[i];
        t->next=last->next;
        last->next=t;
        last=t;
    }
}

void insert(int x,int pos){
    Node *p,*t;
    if(pos==0)
    {
        t=new Node;
        t->data=x;
        if(head==NULL)
        {
            head=t;
            head->next=head;
        }
        else
        {
            p=head;
            while(p->next!=NULL)
            {
                p=p->next;
            }
            p->next=t;
            t->next=head;
            head=t;
        }
        
    }
    else
    {
        p=head;
        for(int i=0;i<pos-1;i++)
        {
            p=p->next;
        }
        t=new Node;
        t->data=x;
        t->next=p->next;
        p->next=t;
    }
}
int Delete(struct Node *p,int pos){
    Node *q;
    int x;
    if(pos==0)
    { p=head;
        while(p->next!=head)
        {
            p=p->next;
        }
        x=head->data;
        if(p==head)
        {
            delete head;
            head=NULL;
        }
        else
        {
            p->next=head->next;
            delete head;
            head=p->next;
            
        }
        
    }
    else
    {
        p=head;
        for(int i=0;i<pos-1;i++){
            p=p->next;
        }
        q=p->next;
        x=q->data;
        free(q);
    }
    return x;
}
void display(Node *h){
    do{if(h==0) h=h->next;
     cout<<h->data<<" ";
     h=h->next;
    }while(h!=head);
}

int main()
{//int data,position;
  //cin>>data>>position;
    int a[]={1,2,3,4,5};
  create(a,5);
 // insert(data,position);
  Delete(head,1);
    display(head);
    return 0;
}

