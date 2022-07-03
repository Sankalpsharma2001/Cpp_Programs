#include<bits/stdc++.h>
using namespace std;
//  Using class
class Queue{
    private:
    int size;
    int front;
    int rear;
    int *Q;
    public:
    Queue()
    { front=rear=-1;
    size=10;
    Q=new int[size];

    }
     Queue(int size)
    {
        front = rear = -1;
        this->size = 10;
        Q = new int[this->size];
    }
    void enqueuef(int data);
    void enqueueb(int data);
    int dequeuef();
    int dequeueb();
    void display();

};
void Queue::enqueueb(int data)
{
  if(rear==size-1)
  {cout<<"Queue is FULL from back";}
  else
  {
      rear++;
      Q[rear]=data;
  }
}
void Queue::enqueuef(int data)
{
    if(front==-1)
    cout<<"From start Queue is full ";
    else
    {
     Q[front]=data;
       front--;
    }
}
int Queue::dequeuef()
{  int x=-1;
    if(front==rear)
    cout<<"Queue is empty";
    else
    {
        front++;
        x=Q[front];
    }
    return x;
}
int Queue::dequeueb()
{
    int x=-1;
    if(rear==front)
    cout<<"Queue is empty ";
    else
    {
        x=Q[rear];
       rear--;
    }
    return x;
}

void Queue::display()
{
    for(int i=front+1;i<=rear;i++)
    cout<<Q[i]<<" ";
}
/*struct Queue{
    int size;
    int front;
    int rear;
    int *Q;
};
void create(struct Queue *q,int size)
{
    q->size=size;
    q->rear=q->front=-1;
    q->Q=new int[size];

}
void enqueueb(struct Queue *q,int data)
{
  if(q->rear==q->size-1)
  {cout<<"Queue is FULL from back";}
  else
  {
      q->rear++;
      q->Q[q->rear]=data;
  }
}
void enqueuef(struct Queue *q,int data)
{
    if(q->front==-1)
    cout<<"From start Queue is full ";
    else
    {
     q->Q[q->front]=data;
       q->front--;
    }
}
int dequeuef(struct Queue *q)
{  int x=-1;
    if(q->front==q->rear)
    cout<<"Queue is empty";
    else
    {
        q->front++;
        x=q->Q[q->front];
    }
    return x;
}
int dequeueb(struct Queue *q)
{
    int x=-1;
    if(q->rear==q->size-1)
    cout<<"Queue is full from back ";
    else
    {
        x=q->Q[q->rear];
       q->rear--;
    }
    return x;
}
void display(Queue q)
{
    for(int i=q.front+1;i<=q.rear;i++)
    cout<<q.Q[i]<<" ";
}*/
int main()
{ class Queue q1;
 q1.enqueueb(1);
 q1.enqueueb(2);
  q1.enqueueb(3);
    q1.enqueueb(5);
   q1.enqueueb(6);
    q1.enqueueb(7);
  q1.dequeuef();
  q1.dequeuef();
  q1.dequeuef();
  q1.enqueuef(4);
  q1.enqueuef(8);
  q1.enqueuef(9);
  q1.dequeueb();
 q1.display();
    /*struct Queue q;
  create(&q,10);
  enqueueb(&q,1);
   enqueueb(&q,2);
    enqueueb(&q,3);
    enqueueb(&q,5);
   enqueueb(&q,6);
    enqueueb(&q,7);
  dequeuef(&q);
  dequeuef(&q);
  dequeuef(&q);
  enqueuef(&q,4);
  enqueuef(&q,8);
  enqueuef(&q,9);
  dequeueb(&q);
  display(q);*/
     /*deque<int> mydeque;
mydeque.push_back(5);
mydeque.push_back(8);
mydeque.push_back(9);
mydeque.push_back(2);
mydeque.pop_front();
mydeque.push_front(6);
mydeque.push_front(16);
mydeque.pop_back();
for(auto it=mydeque.begin();it!=mydeque.end();++it)
cout<<*it<<" ";*/
    return 0;

}