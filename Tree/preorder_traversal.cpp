#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node *left;
    Node *right;
    Node* create(int data);
};

class Node* create(int data)
{ class Node *n;
 n=new Node;
 n->data=data;
 n->left=NULL;
 n->right=NULL;
return n;
}
void preorder(class Node *root)
{if(root!=NULL)
{
    cout<<root->data;
    preorder(root->left);
    preorder(root->right);
}

}
int main(){
class Node *p=create(4);
class Node *p1=create(1);
class Node *p2=create(2);
class Node *p3=create(5);
class Node *p4=create(6);
  /*                    4
                       / \
                       1  2
                      / \
                      5  6
  */
p->left=p1;
p->right=p2;
p1->left=p3;
p1->right=p4;
preorder(p);
return 0;
}