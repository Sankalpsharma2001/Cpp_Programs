#include<bits/stdc++.h>
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
int c=0;
void find(Node* root,int k,int &ans)
{ 
    if(!root) return;
    find(root->right,k,ans);
     c++;
     if(c==k)
     { ans=root->data;
        return;
     }
     find(root->left,k,ans);
}
void inorder(Node *root)
{ if(!root) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main()
{
  
    Node *root=new Node(20);
  root->left=new Node(8);
  root->right=new Node(22);
  root->left->left=new Node(4);
  root->left->right=new Node(12);
  root->left->right->left=new Node(10);
root->left->right->right=new Node(14);
// cout<<root->data<<" ";
 inorder(root);
 cout<<endl;
 int t;
 cin>>t;
 while(t--)
 { c=0;
int ans;
    int k;
    cin>>k;
    find(root,k,ans);
  cout<<ans<<endl;
 }  
    return 0;
}