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

int Max(Node *p){
    int max=INT_MIN;
    while(p)
    {
        if(p->data>max)
        max=p->data;
        p=p->next;
    }
    return max;
}
int Min_no(Node *p){
    int min=INT_MAX;
    while(p)
    {
        if(p->data<min)
        min=p->data;
        p=p->next;
    }
    return min;
}


int main()
{ cout<<"enter no ";
 int n;
 cin>>n;
 int a[n];
  cout<<"Enter element:";
 for(int i=0;i<n;i++){
     cin>>a[i];
 create(a,n);
 }
 cout<<"Maximum Number is:"<<Max(first)<<endl;
 cout<<"Minimum Number is:"<<Min_no(first); 
 

    return 0;
}
