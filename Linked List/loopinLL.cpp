#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
} *first = NULL;
void create(int a[], int n)
{
    Node *t, *last;
    first = new Node;
    first->data = a[0];
    first->next = NULL;
    last = first;
    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = a[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
void createloop(Node *head, int k)
{
    Node *p = head;
    Node *temp = p;
    int i = 0;
    while (i < k)
    {
        temp = temp->next;
        i++;
    }
    while (p != NULL)
    {
        p = p->next;
    }
    p->next = temp;
}
int countNodes(Node *ptr)
{
    int count = 0;
    while (ptr != NULL)
    {
        ptr = ptr->next;
        count++;
    }
    return count;
}
void removeLoop(Node *head)
{
    if (!head)
        return;

    //using two pointers and moving one pointer(slow) by one node and
    //another pointer(fast) by two nodes in each iteration.
    Node *fast = head->next;
    Node *slow = head;

    while (fast != slow)
    {
        //if the node pointed by first pointer(fast) or the node
        //next to it is null, then loop is not present.
        if (!fast || !fast->next)
            return;
        fast = fast->next->next;
        slow = slow->next;
    }
    //both pointers now point to the same node in the loop.

    int size = 1;
    fast = fast->next;

    //we start iterating the loop with first pointer and continue till
    //both pointers point to same node again.
    while (fast != slow)
    {
        //incrementing the counter which stores length of loop.
        size++;
        fast = fast->next;
    }

    //updating the pointers again to starting node.
    slow = head;
    fast = head;

    //moving pointer (fast) by (size-1) nodes.
    for (int i = 0; i < size - 1; i++)
        fast = fast->next;

    //now we keep iterating with both pointers till fast reaches a node such
    //that the next node is pointed by slow. At this situation slow is at
    //the node where loop starts and first at last node so we simply
    //update the link part of first.
    while (fast->next != slow)
    {
        fast = fast->next;
        slow = slow->next;
    }
    //storing null in link part of the last node.
    fast->next = NULL;
}
void display(struct Node *p, int TN)
{
    int c = 0;
    while (c < TN)
    {
        c++;
        cout << p->data << " ";
        p = p->next;
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    create(a, n);
    int totalnodes = countNodes(first);
    display(first, totalnodes);
    cout << "Enter number to link :";
    int k;
    cin >> k;
    createloop(first, k);
    display(first, totalnodes);
    return 0;
}
