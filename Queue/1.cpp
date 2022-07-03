#include <bits/stdc++.h>
using namespace std;
//USING C++ CLASS
/*class Queue
{
private:
    int front;
    int rear;
    int size;
    int *Q;

public:
    Queue()
    {
        front = rear = -1;
        size = 10;
        Q = new int[size];
    }
    Queue(int size)
    {
        front = rear = -1;
        this->size = 10;
        Q = new int[this->size];
    }
    void enqueue(int x);
    int deque();
    void Display();

};
void Queue::enqueue(int x)
{
    if (rear ==size - 1)
        cout << "Queue is Full";
    else
    {
        rear++;
        Q[rear] = x;
    }
}*/
struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};
void create(struct Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = -1;
    // q->Q = (int *)malloc(q->size * sizeof(int));
    q->Q=new int[q->size];
}
void enqueue(struct Queue *q, int x)
{
    if (q->rear == q->size - 1)
        cout << "Queue is Full";
    else
    {
        q->rear++;
        q->Q[q->rear] = x;
    }
}
int Dequeue(struct Queue *q)
{
    int x = -1;
    if (q->rear == q->front)
        cout << "Queue is empty";
    else
    {
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}
void Display(struct Queue q)
{
    for (int i = q.front + 1; i <= q.rear; i++)
    {
        cout << q.Q[i] << " ";
    }
    cout << endl;
}
int main()
{
    struct Queue q;
    create(&q, 5);
    q.enqueue(10);// for class
    enqueue(&q, 5);
    enqueue(&q, 10);
    enqueue(&q, 55);
    enqueue(&q, 16);
    enqueue(&q, 55);
    Dequeue(&q);
    Display(q);

    return 0;
}