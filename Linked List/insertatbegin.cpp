#include <iostream>

using namespace std;
struct Node
{int data;
Node *next;
};
struct Node* head; 
void insertbegin(int x)
{
        Node *temp=new Node();
        temp->data=x;
        temp->next=NULL;
        if(head!=NULL) temp->next=head;
        head=temp;
}
void print(){
    struct Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
        
    }
}
int main()
{head=NULL;
 int n,x;
 cin>>n;
 for(int i=0;i<n;i++)
 { cin>>x;
  insertbegin(x);
     
 }print();
    return 0;

}



