#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    Node *links[26];
    bool flag = false;
    bool containkey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }
    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }
    Node *get(char ch)
    {
        return links[ch - 'a'];
    }
    void setEnd()
    {
        flag = true;
    }
    bool isEnd()
    {
        return flag;
    }
};
class Trie
{
private:
    Node *root;

public:
    /** Initialize your data structure here. */
    Trie()
    {
        root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containkey(word[i]))
            {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containkey(word[i]))
                return false;
            node = node->get(word[i]);
        }
        return node->isEnd();
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        Node *node = root;
        for (int i = 0; i < prefix.size(); i++)
        {
            if (!node->containkey(prefix[i]))
            {
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }
};

int main()
{
    int tt;
    cin >> tt;
     Trie t;
    while (tt--)
    {
        int var;
        string s;
        cin >> var >> s;
        if (var == 1)
        {
            t.insert(s);
        }
        else if(var==2)
        {
            if (t.search(s))
                cout << "true\n";
            else
                cout << "false\n";
        }
        else
        {
           if(t.startsWith(s))
           cout<<"true\n";
           else
           cout<<"false\n";
        }
    }
}