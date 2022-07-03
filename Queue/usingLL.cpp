#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
} *front = NULL, *rear = NULL;
void enqueue(int x)
{
    struct Node *t;
    t = new Node;
   
        t->data = x;
        t->next = NULL;
        if (front == NULL)
            front = rear = t;
        else
        {
            rear->next = t;
            rear = t;
        }
    
}
int dequeue()
{
    struct Node *t;

    int x = -1;
    if (front == NULL)
        cout << "Queue is empty" << endl;
    else
    {
        x = front->data;
        t = front;
        front = front->next;
        delete t;
    }
    return x;
}
void Display()
{
    struct Node *p = front;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
}
int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    Display();
    return 0;
}