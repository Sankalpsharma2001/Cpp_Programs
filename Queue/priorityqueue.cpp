#include<bits/stdc++.h>
using namespace std;
int main()
{ priority_queue<int> pq;
 pq.push(1);
 pq.push(5);
 pq.push(17);
 pq.push(10);
 pq.push(9);
 while(!pq.empty())
 {
     cout<<pq.top()<<" ";
     pq.pop();
 }
    return 0;
}