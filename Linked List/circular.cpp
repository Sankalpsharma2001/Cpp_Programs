#include <iostream>
using namespace std;
struct Node {
    int data;
    Node *next;
}*head;
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
void display(Node *h){
    do{
     cout<<h->data<<" ";
     h=h->next;
    }while(h!=head);
}
void rdisplay(Node *h){
    static int flag=0;
    if(h!=head||flag==0){
        flag=1;
        cout<<h->data<<" ";
        rdisplay(h->next);
    }
    flag=0;
}
int main() {
    int a[]={1,2,3,4,5};
    create(a,5);
    display(head);
    cout<<endl;
    rdisplay(head);
    return 0;
}

