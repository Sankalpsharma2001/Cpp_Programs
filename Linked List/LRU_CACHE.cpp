#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node *next;
    node *pre;
    node()
    {
        next=NULL;
        pre=NULL;
    }
    node(int x)
    {
        this->data=x;
        next=NULL;
        pre=NULL;
    }
};
class LRUCache
{
 public:
 int capacity=3;
 node *head,*rear;
 int cursize;
 LRUCache()
 {
     cursize=0;
     head=NULL;
     rear=NULL;
 }
 void cap(int x)
 {
    capacity=x;
 }
 unordered_map<int,node *> mp;
 void refer(int x)
 {   //miss case
     if(mp.find(x)==mp.end()) //not present
     {
        if(cursize==capacity)//cache is full
        { //page replacement
            node *temp=rear;
            rear=rear->pre;
            temp->pre=NULL;
            rear->next=NULL;
            mp.erase(temp->data);
            delete temp;
            node *temp2=new node;
            temp2->data=x;
            temp2->next=head;
            head->pre=temp2;
            head=temp2;
            mp.insert({x,temp2});
        }
        else
        {
          //miss and cache is not full
          node *temp2=new node;
          temp2->data=x;
          if(cursize==0)
          {
              head=temp2;
              rear=temp2;
          }
          else{
          temp2->next=head;
          head->pre=temp2;
          head=temp2;
          }
         
          mp.insert({x,temp2});
           cursize++;
        }
     }
     else
     {
         //hit case
         // to take the node to first place
         if(cursize==1)
         return;
         node *loc=mp[x];
         if(loc==head) return;
         node *locnext=loc->next;
         node *locpre=loc->pre;
         if(loc==rear)
         {
             loc->next=head;
             loc->pre=NULL;
             head->pre=loc;
             head=loc;
             locpre->next=locnext;  //locpre->next=NULL;
             rear=locpre;
         }
         else
         {
             loc->next=head;
             loc->pre=NULL;
             head->pre=loc;
             head=loc;
            
             locpre->next=locnext;
             locnext->pre=locpre;
         }
     }
     cout<<endl;
     cout<<"Current size is: "<<cursize<<endl;
     for(auto p:mp)
     {
         cout<<p.first<<" -----> "<<p.second<<endl;

     }
     cout<<endl;
     
 }
 void display()
     {
         node *temp=head;
         while(temp)
         {
             cout<<temp->data<<" ";
             temp=temp->next;
         }
         cout<<endl;
     }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LRUCache l;
    l.cap(3);
    l.refer(1);
    l.display();
     l.refer(2);
     l.display();
     l.refer(1);
     l.display();
      l.refer(3);
      l.display();
       l.refer(4);
       l.display();
    return 0;
}
//using list stl
// #include <bits/stdc++.h>
// using namespace std;

// class LRUCache {
// 	// store keys of cache
// 	list<int> dq;

// 	// store references of key in cache
// 	unordered_map<int, list<int>::iterator> ma;
// 	int csize; // maximum capacity of cache

// public:
// 	LRUCache(int);
// 	void refer(int);
// 	void display();
// };

// // Declare the size
// LRUCache::LRUCache(int n)
// {
// 	csize = n;
// }

// // Refers key x with in the LRU cache
// void LRUCache::refer(int x)
// {
// 	// not present in cache
// 	if (ma.find(x) == ma.end()) {
// 		// cache is full
// 		if (dq.size() == csize) {
// 			// delete least recently used element
// 			int last = dq.back();

// 			// Pops the last element
// 			dq.pop_back();

// 			// Erase the last
// 			ma.erase(last);
// 		}
// 	}

// 	// present in cache
// 	else
// 		dq.erase(ma[x]);

// 	// update reference
// 	dq.push_front(x);
// 	ma[x] = dq.begin();
// }

// // Function to display contents of cache
// void LRUCache::display()
// {

// 	// Iterate in the deque and print
// 	// all the elements in it
// 	for (auto it = dq.begin(); it != dq.end();
// 		it++)
// 		cout << (*it) << " ";

// 	cout << endl;
// }

// int main()
// {
// 	LRUCache ca(4);

// 	ca.refer(1);
// 	ca.refer(2);
// 	ca.refer(3);
// 	ca.refer(1);
// 	ca.refer(4);
// 	ca.refer(5);
// 	ca.display();

// 	return 0;
// }
