#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node *left;
    Node *right; 
};
class Node* createNode(int x)
{
Node *n=new Node;
n->data=x;
n->left=NULL;
n->right=NULL;
return n;
}
int main(){
Node *p=createNode(2);
Node *p1=createNode(3);
Node *p2=createNode(4);
p->left=p1;
p->right=p2;
return 0;
}