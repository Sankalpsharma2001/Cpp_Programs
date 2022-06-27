#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
using namespace std;
struct Node
{
    float coeff;
    int expo;
    Node *next;
};
Node *Insert(Node *head, int co, int ex)
{
    Node *t = (struct Node*)malloc(sizeof(struct Node));
    t->coeff = co;
    t->expo = ex;
    t->next = NULL;
    if (head == NULL || ex > head->expo)
    {
        t->next = head;
        head = t;
    }
    else
    {
        Node *temp = head;
        while (head->next != NULL && temp->next->expo > ex)
        {
            temp = temp->next;
        }
        t->next = temp->next;
        temp->next = t;
    }
    return head;
}
Node *create(Node *head)
{
    int i;
    float coeff;
    int expo;

    int n;
    cout << "Enter the number of terms:";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the coefficient term " << i + 1 << ": ";
        cin >> coeff;
        cout << "Enter the exponent for term " << i + 1 << " ";
        cin >> expo;
        head = Insert(head, coeff, expo);
    }
    return head;
}

void print(Node *head)
{
    if (head == NULL)
        cout << "NO Polynomial\n";
    else
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->coeff << "x^" << temp->expo;
            temp = temp->next;
            if (temp != NULL)
                cout << "+";
            else
            {
                cout << "\n";
            }
        }
    }
}
int main()
{
    struct Node *head = NULL;
    cout << "Enter the polynomial:\n";
    head = create(head);
    print(head);
    return 0;
}

/*void printpol(int pol[],int sz)
{  for(int i=0;i<sz;i++){
    cout<<pol[i];
    if(i!=0)
    cout<<"x^"<<i;
    if(i!=sz-1)
    cout<<"+";
}
}
int *add(int a[],int b[],int x,int y)
{
    int *sum=new int[max(x,y)];
    for(int i=0;i<x;i++)
    sum[i]=a[i];
    for(int i=0;i<y;i++)
    sum[i]+=b[i];
    return sum;
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int a[]={4,3,5};
int b[]={8,3,2,4};
int x=sizeof(a)/sizeof(a[0]);
int y=sizeof(b)/sizeof(b[0]);
cout<<"First polynomial is:";
printpol(a,x);
cout<<"\nsecond polynomial is:";
printpol(b,y);
int *sum=add(a,b,x,y);
cout<<"\nPolynomial after addition:";
printpol(sum,max(x,y));

return 0;
}*/