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
 map<int,int> mp;
 map<int,vector<int> > m; 
 void LeftView(Node *);
 void RightView(Node *);
 void TopView(Node *,int hd);
 void BottomView(Node *,int hd);
 void Spiral(Node *);
 void Diagonal(Node *,int hd);

};
void BTree::LeftView(Node *head)
{
    queue<Node *>q;
    q.push(head);
    while(!q.empty())
    {
      
        int c=q.size();
        for(int i=0;i<c;i++)
        { Node *t=q.front();
        if(i==0) cout<<t->data<<" ";
        q.pop();
        if(t->left)
        q.push(t->left);
        if(t->right)
        q.push(t->right);
        } 
    }   
}
// void solve(Node *root,int level,vector<int> &ans)
// {
//     if(!root)
//     return;
//     if(level==ans.size())
//     ans.push_back(root->data);
//     solve(root->left,level+1,ans);
//     solve(root->right,level+1,ans);
// }
// vector<int> leftView(Node *root)
// {
//    vector<int> ans;
//    solve(root,0,ans);
//    return ans;
// }

void BTree::RightView(Node *head)
{
    queue<Node *> q;
    q.push(head);
    while(!q.empty())
    {
        int c=q.size();
        for(int i=0;i<c;i++)
        {
            Node *t=q.front();
            if(i==c-1) cout<<t->data<<" ";
            q.pop();
            if(t->left)
            q.push(t->left);
            if(t->right)
            q.push(t->right);

        }
    }
}
// it will give wa in some cases as height matter when we traversing right root it give wrong
void BTree::TopView(Node *head,int hd)
{
if(head==NULL) return;
if(mp.count(hd)==0)
{
    mp[hd]=head->data;
}
 TopView(head->left,hd-1);
 TopView(head->right,hd+1);
}
// TOP VIEW  ---------------------------
    map<int,pair<int,int>> m;
    void help(Node *root,int idx,int h)
    { if(root==NULL) return;
        if(m.count(idx)==0)
        {
            m[idx]=make_pair(root->data,h);
        }
        else if(m[idx].second>h)
        {
            m[idx]=make_pair(root->data,h);
        }
        help(root->left,idx-1,h+1);
        help(root->right,idx+1,h+1);
    }
     for(auto it=m.begin();it!=m.end();it++)
        {
            ans.push_back(it->second.first);
        }
    //-------------------------------------  
void BTree::BottomView(Node *head,int hd)
{
if(head==NULL) return;
    mp[hd]=head->data;
 BottomView(head->left,hd-1);
BottomView(head->right,hd+1);
// When 50 is print  means left subtree data 
/* BottomView(head->right,hd+1);
 BottomView(head->left,hd-1);*/
}

 map<int,pair<int,int>> m;
  void solve(Node *root,int idx,int h)
  {
      if(!root) return;
      if(m.count(idx)==0 || m[idx].second<=h)
      m[idx]=make_pair(root->data,h);
      solve(root->left,idx-1,h+1);
      solve(root->right,idx+1,h+1);
  }
void BTree::Spiral(Node *head)
{
    queue<Node *> q;
    q.push(root);
    int level=0;
    vector<int> v;
    //if level odd then L TO R
    // if level even then R to L
    while(!q.empty())
    { 
        int c=q.size();
        for(int i=0;i<c;i++)
        { Node *t=q.front();
        v.push_back(t->data);
        q.pop();
        if(t->left)
        q.push(t->left);
        if(t->right)
        q.push(t->right);
              }
               if(level%2)
        {for(int i=0;i<v.size();i++) cout<<v[i]<<" ";}
        else
        {for(int i=v.size()-1;i>=0;i--) cout<<v[i]<<" ";}
         v.clear();
        level++;
    }
}
void BTree::Diagonal(Node *root,int hd)
{
     /* vector<int> v;
queue<Node*> q;
q.push(root);
while(!q.empty())
{
root = q.front();
q.pop();
while(root)
{
v.push_back(root -> data);
if(root -> left)
q.push(root -> left);
root = root -> right;
}
}*/
    if(root==NULL)
    return;   
    m[hd].push_back(root->data);
    Diagonal(root->left,hd+1);
    Diagonal(root->right,hd);
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
     /*
                  10
                  / \
                 20  30
                / \   / \
              40  50  60 70
     
     
     */

cout<<"Left View"<<endl;
t.LeftView(t.root);
cout<<endl;

cout<<"Right View"<<endl;
t.RightView(t.root);
cout<<endl;

cout<<"Top View"<<endl;
t.TopView(t.root,0);
for(auto x:(t.mp))
cout<<x.second<<" ";
cout<<endl;

cout<<"Bottom View"<<endl;
t.BottomView(t.root,0);
for(auto a:(t.mp))
cout<<a.second<<" ";
cout<<endl;

cout<<"Print in spiral ";
t.Spiral(t.root);
cout<<endl;

cout<<"Print element in Diagonal format:"<<endl;
t.Diagonal(t.root,0);
for(auto b:(t.m))
{ vector<int> v=b.second;
 for(auto it:v)
 cout<<it<<" ";
 cout<<endl;
}
cout<<endl;


return 0;
}