#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node()
    {
        data = 0;
        next = NULL;
    }
    node(int x)
    {
        data = x;
        next = NULL;
    }
    node(int x, node *ptr)
    {
        data = x;
        next = ptr;
    }
};
class linklist
{
public:
    node *head;
    linklist()
    {
        head = NULL;
    }
    void appendNode(node *n)
    {
        if (head == NULL)
        {
            head = n;
            return;
        }
        node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = n;
    }
    void prependNode(node *n)
    {
        if (head == NULL)
        {
            head = n;
            return;
        }
        n->next = head;
        head = n;
    }
    bool find(int key)
    {
        node *temp = head;
        while (temp != NULL)
        {
            if (temp->data == key)
                return true;
            temp = temp->next;
        }
        return false;
    }
    void add_after(int key, node *n)
    {
        if (find(key) == false)
        {
            cout << "Given key not found" << endl;
            return;
        }
        node *temp = head;
        while (temp->data != key)
            temp = temp->next;
        if (temp->next == NULL)
            temp->next = n;
        else
        {
            n->next = temp->next;
            temp->next = n;
        }
        cout << "Node added" << endl;
    }
    void print()
    {
        node *temp = head;
        if (temp == NULL)
            cout << "Empty linklist";
        else
        {
            while (temp != NULL)
            {
                cout << temp->data << "->";
                temp = temp->next;
            }
        }
        cout << endl;
    }
    void deleteNode(int key)
    {
        if (find(key) == false)
        {
            cout << "Node with given key not found" << endl;
            return;
        }
        if (head->data == key)
        {
            node *temp = head;
            head = head->next;
            delete (temp);
            cout << "Node deleted" << endl;
            return;
        }
        node *temp = head;
        while ((temp->next)->data != key)
            temp = temp->next;
        node *ptr = temp->next;
        temp->next = (temp->next)->next;
        delete (ptr);
        cout << "Node deleted" << endl;
    }
    void reverse()
    {
        node *curr = head, *prev = NULL;
        while (curr != NULL)
        {
            node *nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        head = prev;
    }
};
int main()
{
    linklist ll;
    int ch;
    do
    {
        cout << "Enter choice" << endl;
        cout << "0)To exit" << endl;
        cout << "1)Append Node" << endl;
        cout << "2)Prepend Node" << endl;
        cout << "3)Check whether a node exists or not" << endl;
        cout << "4)Add Node after a given key" << endl;
        cout << "5)Delete a node" << endl;
        cout << "6)Reverse the linklist" << endl;
        cout << "7)Print linklist" << endl;
        cin >> ch;
        switch (ch)
        {
        case 0:
            break;
        case 1:
        {
            cout << "Enter data of new node" << endl;
            int x;
            cin >> x;
            node *n = new node(x);
            ll.appendNode(n);
            cout << "Node appended" << endl;
            break;
        }
        case 2:
        {
            cout << "Enter data of new node" << endl;
            int x;
            cin >> x;
            node *n = new node(x);
            ll.prependNode(n);
            cout << "Node prepended" << endl;
            break;
        }
        case 3:
        {
            cout << "Enter key" << endl;
            int x;
            cin >> x;
            cout << (ll.find(x) ? "Node found" : "Node not found") << endl;
            break;
        }
        case 4:
        {
            cout << "Enter key" << endl;
            int key;
            cin >> key;
            cout << "Enter data of node" << endl;
            int x;
            cin >> x;
            node *n = new node(x);
            ll.add_after(key, n);
            break;
        }
        case 5:
        {
            cout << "Enter key" << endl;
            int key;
            cin >> key;
            ll.deleteNode(key);
            break;
        }
        case 6:
        {
            ll.reverse();
            break;
        }
        case 7:
        {
            ll.print();
            break;
        }
        }
    } while (ch != 0);
}