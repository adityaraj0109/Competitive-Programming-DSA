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
    bool isTerminal;

    TrieNode(char data)
    {
        this->data = data;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

TrieNode *root;
Trie()
{
    root = new TrieNode('\0');
}

void insertUtil(TrieNode *root, string word)
{
    if (word.size() == 0)
    {
        root->isTerminal = true;
        return;
    }

    int index = word[0] - 'a';
    TrieNode *child;

    // when the char is already present
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

bool searchUtil(TrieNode *root, string word)
{
    if (word.length() == 0)
    {
        return root->isTerminal;
    }

    int index = word[0] - 'a';
    TrieNode *child;

    // when the char is already present
    if (root->children[index] != NULL)
    {
        child = root->children[index];
    }
    else
    {
        return false;
    }

    return searchUtil(child, word.substr(1));
}

bool search(string word)
{
    return searchUtil(root, word);
}

bool searchPrefix(TrieNode *root, string word)
{
    if (word.length() == 0)
    {
        return true;
    }

    int index = word[0] - 'a';
    TrieNode *child;

    // when the char is already present
    if (root->children[index] != NULL)
    {
        child = root->children[index];
    }
    else
    {
        return false;
    }

    return searchPrefix(child, word.substr(1));
}

bool startsWith(string prefix)
{
    return searchPrefix(root, prefix);
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
