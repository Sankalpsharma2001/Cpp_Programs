#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    Node *links[26];
    int cntend=0;
    int cntpre=0;
    bool contain(char ch)
    {
        return links[ch-'a']!=NULL;
    }
    Node *get(char ch)
    {
        return links[ch-'a'];
    }
    void put(char ch,Node *node)
    {
        links[ch-'a']=node;
    }
    void increaseend()
    {
        cntend++;
    }
    void increasepre()
    {
        cntpre++;
    }
    void deleteend()
    {
        cntend--;
    }
    void reducepre()
    {
        cntpre--;
    }
    int getend()
    {
        return cntend;
    }
    int getpre()
    {
        return cntpre;
    }
};
class Trie{
 Node *root;
    public:

    Trie(){
        // Write your code here.
    root=new Node();
    }

    void insert(string &word){
        // Write your code here.
        Node *node=root;
        for(int i=0;i<word.size();i++)
        {
            if(!node->contain(word[i]))
            {
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
            node->increasepre();
        }
        node->increaseend();
    }

    int countWordsEqualTo(string &word){
        // Write your code here.
        Node *node=root;
        for(int i=0;i<word.size();i++)
        {
            if(node->contain(word[i]))
            {
                node=node->get(word[i]);
            }
            else
                return 0;
        }
        return node->getend();

    }

    int countWordsStartingWith(string &word){
        // Write your code here.
         Node *node=root;
        for(int i=0;i<word.size();i++)
        {
            if(node->contain(word[i]))
            {
                node=node->get(word[i]);
            }
            else
                return 0;
        }
        return node->getpre();
    }

    void erase(string &word){
        // Write your code here.
         Node *node=root;
        for(int i=0;i<word.size();i++)
        {
            if(node->contain(word[i]))
            {
                node=node->get(word[i]);
                node->reducepre();
            }
            else
                return ;
        }
        node->deleteend();
    }
};


int main()
{
    int tt;
    cin >> tt;
     Trie t;
    while (tt--)
    { 
       string a,b;
       cin>>a>>b;
       if(a=="insert")
       {
          t.insert(b);
       }
       else if(a=="countWordsEqualTo")
       {
         int x=t.countWordsEqualTo(b);
         cout<<x<<endl;
       }
       else if(a=="countWordsStartingWith")
       {
            cout<<t.countWordsStartingWith(b)<<endl;
       }
       else if(a=="erase")
       {
          t.erase(b);
       } 
    }
}