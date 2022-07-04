#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
using namespace std;
class Node{
     public:
    int data;
    Node *left;
    Node *right;
   
    Node(int val)
    {
        data=val;
       left=NULL;
       right=NULL;
    }
};
void sumreplacement(Node *root)
{
    if(root==NULL)
    return;
    sumreplacement(root->left);
    sumreplacement(root->right);
    if(root->left!=NULL)
    {
        root->data+=root->left->data;
    }
    if(root->right!=NULL)
    {
        root->data+=root->right->data;
    }
}
void preorder(Node *root)
{ if(root==NULL) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
  Node *root=new Node(1);
 root->left=new Node(2);
 root->right=new Node(3);
 root->left->left=new Node(4);
 root->left->right=new Node(5);
 root->right->left=new Node(6);
root->right->right=new Node(7);
/*
             1
            /  \
           2    3
          / \  / \
          4 5  6  7

*/
preorder(root);
cout<<endl;
sumreplacement(root);
preorder(root);
return 0;
}