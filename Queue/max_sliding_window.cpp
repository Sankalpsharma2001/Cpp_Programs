#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n;
cin>>n;
vector<int> nums(n);
for(int i=0;i<n;i++)
cin>>nums[i];
int k;
cin>>k;
       vector<int> ans;
        deque<int> q(k);
        for(int i=0;i<k;i++)
        {
            while(!q.empty()&&nums[i]>=nums[q.back()])
            {
                q.pop_back();
            }
            q.push_back(i);
        }
        ans.push_back(nums[q.front()]);
        for(int i=k;i<nums.size();i++)
        { 
            if(q.front()<=i-k)
                q.pop_front();
                
         while(!q.empty()&&nums[i]>=nums[q.back()])
            {
                q.pop_back();
            }   
            q.push_back(i);
            ans.push_back(nums[q.front()]);
        }
  for(int i=0;i<ans.size();i++)
  cout<<ans[i]<<" ";
    

return 0;
}