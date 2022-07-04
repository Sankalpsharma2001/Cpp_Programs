#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
using namespace std;
/*class node{
    int data;
    node* left;
    node* right;
    node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
}*/

class Node 
{
    public:
    int data;
    Node *left;
    Node *right;
    Node* create(int data);
};
class Node* create(int data)
{
    class Node *n=new Node;
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}
void inorder(class Node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}
int isBST(class Node *root)
{
    static class Node *prev=NULL;
    if(root!=NULL)
    {
        if(!isBST(root->left))
        {
            return 0;
        }
        if(prev!=NULL&&root->data<=prev->data)
        return 0;
        prev=root;
        return isBST(root->right);
    }
    else
    {
        return 1;
    }
}
bool isBST(Node *root,Node *min,Node *max)
{//min is from left subtree 
// max from right
    if(root==NULL)
    return true;
    if(min!=NULL&&root->data<=min->data)
    return false;
      if(max!=NULL&&root->data>=max->data)
      return false;
      bool leftvalid=isBST(root->left,min,root);
      bool rightvalid=isBST(root->right,root,max);
      return leftvalid and rightvalid;
}
Node *Rsearch(Node *t,int key)
{
    if(t==NULL)
    return NULL;
    if(key==t->data)
    return t;
   else if(t->data>key)
   return Rsearch(t->left,key);
   else
   return Rsearch(t->right,key);
}
Node *Search(Node *t,int key)
{
    
    while(t)
    {
        if(key==t->data)
        return t;
        else if(t->data>key)
        t=t->left;
        else 
        t=t->right;
    }
    return NULL;
}
void Insert(Node *t,int key)
{
    Node *r=NULL,*d;
    while(t!=NULL)
    {
        r=t;
        if(key==t->data)
        return;
        else if(key<t->data)
        t=t->left;
        else
        {
        t=t->right;
        }
        
    }
      d=create(key);
     if(d->data<r->data) r->left=d;
     else r->right=d;

}
Node *RInsert(Node *t,int key)
{
    Node *r=NULL;
    if(t==NULL)
    {
        r=create(key);   
        r->left=r->right=NULL;
        return r;
    }
    if(key<t->data)
    t->left=RInsert(t->left,key);
    else if(key>t->data)
    t->right=RInsert(t->right,key);
    return r;
}
int Height(Node *t)
{ int x,y;
if(t==NULL) return 0;
x=Height(t->left);
y=Height(t->right);
return x>y?x+1:y+1;
}
Node *Inpre(Node *t)
{
    if(t&&t->right!=NULL)
    t=t->right;
    return t;
}
Node *Insuc(Node *t)
{
    if(t&&t->left)
    t=t->left;
    return t;
}
Node *Delete(Node *root,int x)
{ Node *q,*t=root;
    if(t==NULL)
    return NULL;
    if(t->left==NULL&&t->right==NULL)
    {
        if(t==root)
        root=NULL;
       delete(root);
       return NULL;
    }
    if(x<t->data)
    t->left=Delete(t->left,x);
    else if(x>t->data)
    t->right=Delete(t->right,x);
    else
    {
        if(Height(t->left)>Height(t->right))
        {q=Inpre(t->left);
        t->data=q->data;
        t->left=Delete(t->left,q->data);

        }
        else
        {
            q=Insuc(t->right);
            t->data=q->data;
            t->right=Delete(t->right,q->data);
        }
        
    }
    return t;
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
/*class node* root=new Node(1);
root->left=new node(2);
root->right=new node(3);
root->left->left=new node(4);
root->left->right-new node(5);*/
/*
    1
  /   \
  2    3
 /  \
  4 5
*/

 class Node *p=create(5);
class Node *p1=create(2);
class Node *p2=create(8);
class Node *p3=create(1);
class Node *p4=create(3);
class Node *p5=create(7);
class Node *p6=create(10);
 /*                     5
                       / \
                      2   8
                     / \  / \
                     1 3  7  10
  */
p->left=p1;
p->right=p2;
p1->left=p3;
p1->right=p4;
p2->left=p5;
p2->right=p6;
if(isBST(p,NULL,NULL))
cout<<"IT IS BST";
else
cout<<"NOT BST";
//inorder(p);
//cout<<endl;
//cout<<isBST(p);
Node *t=Search(p,6);
//if(t) cout<<"Found"<<endl;
//else cout<<"Not found"<<endl;
//Insert(p,12);
//RInsert(p,4);
Delete(p,5);
inorder(p);
return 0;
}