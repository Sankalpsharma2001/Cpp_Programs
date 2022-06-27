//Q3.Write a Program to implement Binary Search using Linked List
//Write a program in c/c++ to insert 10 elements in a linked list.
#include<bits/stdc++.h>
using namespace std;
struct Node{
int data;
Node *next;
};
class LinkedList{
Node *head,*tail;
public:
LinkedList()
{
    head=NULL;
    tail=NULL;
}
void insert(int x);
void display();
Node* binarysearch(int value);
Node* middle(Node* start, Node* last);
};
Node* LinkedList::middle(Node* start, Node* last)
{
    if (start == NULL)
        return NULL;
 
    struct Node* slow = start;
    struct Node* fast = start -> next;
 
    while (fast != last)
    {
        fast = fast -> next;
        if (fast != last)
        {
            slow = slow -> next;
            fast = fast -> next;
        }
    }
 
    return slow;
}
 
Node* LinkedList::binarysearch(int value)
{
   
     Node* start = head;
     Node* last = NULL;
 
    do
    {
        
        Node* mid = middle(start, last);
 
        
        if (mid == NULL)
            return NULL;
 
        if (mid -> data == value)
            return mid;
 
        
        else if (mid -> data < value)
            start = mid -> next;
 
       
        else
            last = mid;
 
    } while (last == NULL ||last != start);
 
   
    return NULL;

}
void LinkedList::insert(int x)
{
    Node *t=new Node;
    t->data=x;
    t->next=NULL;
    if(head==NULL)
    {
        head=t;
        tail=t;
    }
    else
    {
        tail->next=t;
        tail=tail->next;
    }
}
void LinkedList::display()
{ cout<<"The Linked List is:";
    Node *t=head;
    while(t)
    {  
        cout<<t->data<<" ";
        t=t->next;
    }
   
}
int main()
{LinkedList l;
cout<<"Enter number of element to insert:";
int n;cin>>n;
while(n--){
    cout<<"Enter element:";
    int x;
    cin>>x;
 l.insert(x);
}
l.display();
cout<<endl;
cout<<"Enter value to be found in a LinkedList:";
int val;
cin>>val;
 Node *t=l.binarysearch(val);
 if(t)
 cout<<"Element Found";
 else
 cout<<"Element Not Found";
 cout<<endl;

    return 0;
}