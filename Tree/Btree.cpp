#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
using namespace std;
class Node
{ public:
    int data;
    Node *left,*right;
    Node(int k)
    {
        data=k;
        left=right=NULL;
    }
};
class BTree{
public:
 
 Node *root;
 vi v;
 void Inorder(Node *);
 void Preorder(Node *);
 void Postorder(Node *);
 void LevelOrder(Node *);
 int Height(Node *);
 void Diameter(Node *);
 void RoottoLeaf(Node *);
 Node* MirrorTree(Node *);
};
Node* BTree::MirrorTree(Node* root)
{
    
    if (root == NULL)
        return root;
    Node* t = root->left;
    root->left = root->right;
    root->right = t;
 
    if (root->left)
        MirrorTree(root->left);
    if (root->right)
        MirrorTree(root->right);
   
  return root;
}
void BTree::Inorder(Node *root)
{
if(root==NULL)
return;
Inorder(root->left);
cout<<root->data<<" ";
Inorder(root->right);
}
void BTree::Preorder(Node *head)
{
    if(head==NULL)
    return;
    cout<<head->data<<" ";
    Preorder(head->left);
    Preorder(head->right);
}
void BTree::Postorder(Node *head)
{
    if(head==NULL)
    return;
   
    Preorder(head->left);
    Preorder(head->right);
     cout<<head->data<<" ";
}
void BTree::LevelOrder(Node *head)
{
    queue<Node *>q;
    q.push(head);
    while(!q.empty())
    {
       int sum=0;
        int c=q.size();
        for(int i=0;i<c;i++)
        { Node *t=q.front();
        cout<<t->data<<" ";
        sum+=t->data;
        q.pop();
        if(t->left)
        q.push(t->left);
        if(t->right)
        q.push(t->right);

        }
       cout<<"Sum :"<<sum<<endl;
    }
    
}
int BTree::Height(Node *head)
{if(head==NULL) return 0;
int lh=Height(head->left);
int rh=Height(head->right);
return max(lh,rh)+1;

}
void BTree::RoottoLeaf(Node *head)
{
    if(head==NULL) return;
    v.push_back(head->data);
    if(head->left==NULL&&head->right==NULL)
    {
        int sum=0;
        for(auto p:v)
        {
            sum+=p;
            cout<<p<<" ";
        }
        cout<<"--------"<<sum<<endl;
    }
    RoottoLeaf(head->left);
    RoottoLeaf(head->right);
    auto it=v.end();
    --it;
    v.erase(it);
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
BTree t;
t.root=new Node(10);
t.root->left=new Node(20);
t.root->right=new Node(30);
t.root->left->left=new Node(40);
t.root->left->right=new Node(50);
t.root->right->left=new Node(60);
t.root->right->right=new Node(70);
cout<<"Pre Order"<<endl;
t.Preorder(t.root);
cout<<endl;
t.LevelOrder(t.root);
cout<<"Post Order"<<endl;
t.Postorder(t.root);
cout<<endl;
cout<<"Height:";
int h=t.Height(t.root);
cout<<h<<endl;
t.RoottoLeaf(t.root);
cout<<"Mirror image of tree in inorder:";
t.MirrorTree(t.root);
t.Inorder(t.root);
return 0;
}