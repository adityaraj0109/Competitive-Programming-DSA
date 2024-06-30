#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isEnd;

    TrieNode(char data)
    {
        this->data = data;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isEnd = false;
    }
};

class Trie
{
public:
    TrieNode *root;
    Trie()
    {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode *root, string word)
    {
        if (word.size() == 0)
        {
            root->isEnd = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode *child;

        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insertUtil(child, word.substr(1));
    }

    void insert(string word)
    {
        insertUtil(root, word);
    }

    void printSuggestions(TrieNode *curr, vector<string> &temp, string prefix)
    {
        if (curr->isEnd)
        {
            temp.push_back(prefix);
        }
        for (char i = 'a'; i <= 'z'; i++)
        {
            TrieNode *child = curr->children[i - 'a'];
            if (child != NULL)
            {
                prefix.push_back(i);
                printSuggestions(child, temp, prefix);
                prefix.pop_back();
            }
        }
    }

    vector<vector<string>> solution(string s)
    {
        vector<vector<string>> ans;
        TrieNode *prev = root;
        string prefix = "";
        int j;
        for (int i = 0; i < s.size(); i++)
        {
            int index = s[i] - 'a';
            prefix += s[i];
            TrieNode *curr = prev->children[index];
            vector<string> temp;
            if (curr == NULL)
            {
                j = i;
                temp.push_back("0");
                ans.push_back(temp);
                break;
            }
            printSuggestions(curr, temp, prefix);
            ans.push_back(temp);
            prev = curr;
        }
        for (int i = j + 1; i < s.size(); i++)
        {
            vector<string> temp;
            temp.push_back("0");
            ans.push_back(temp);
        }
        return ans;
    }
};

vector<vector<string>> displayContacts(int n, string contact[], string s)
{
    Trie *t = new Trie();
    for (int i = 0; i < n; i++)
    {
        t->insert(contact[i]);
    }
    return t->solution(s);
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
