#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

class TrieNode{
    public:
        char data;
        TrieNode* children[26];
        bool isEnd;
        int childCount;

        TrieNode(char data){
            this->data = data;
            this->childCount = 0;
            for(int i = 0; i < 26; i++){
                children[i] = NULL;
            }
            isEnd = false;
        }
};

class Trie{
    public:
        TrieNode* root;
        Trie(){
            root = new TrieNode('\0');
        }

        void insertUtil(TrieNode* root, string word){
            if(word.size()==0){
                root->isEnd = true;
                return;
            }

            int index = word[0] - 'a';
            TrieNode* child;

            if(root->children[index]!= NULL){
                child=root->children[index];
            }
            else{
                child = new TrieNode(word[0]);
                root->childCount++;
                root->children[index] = child;
            }

            insertUtil(child,word.substr(1));
        }

        void insert(string word){
            insertUtil(root, word);
        }

        void solve(string word, string &ans){
            for (int i = 0; i < word.size(); i++)
            {
                char ch=word[i];
                if(root->childCount==1){
                    ans+=ch;
                    int index=ch-'a';
                    root=root->children[index];
                }
                else{
                    break;
                }

                if(root->isEnd){
                    break;
                }
            }
        }
};

string longestCommonPrefix(vector<string> &strs)
{
    string ans="";
    Trie *t= new Trie();
    int index;
    int minsize=INT_MAX;
    for(int i=0;i<strs.size();i++){
        t->insert(strs[i]);
        if(strs[i].size()<minsize){
            minsize=strs[i].size();
            index=i;
        } 
    }
    t->solve(strs[index],ans);
    return ans;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
