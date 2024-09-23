//Prefix Tree

#include<iostream>
#include<vector>
#include<string>

using namespace std;

struct TrieNode{
    TrieNode* child[26];
    bool wordEnd;
    TrieNode(){
        wordEnd = false;
        for(int i = 0; i < 26; i++)
        {
            child[i] = nullptr;
        }
    }
};

void insertKey(TrieNode* root, const string& key){
    TrieNode* curr = root;
    for(char c: key){
        if(curr -> child[c - 'a'] == nullptr){
            TrieNode* newNode = new TrieNode();
            curr -> child[c - 'a'] = newNode;
        }
        curr = curr -> child[c - 'a'];
    }
    curr -> wordEnd = true;
}

bool searchKey(TrieNode* root, string& key){
    TrieNode* curr = root;
    for(char c: key)
    {
        if(curr -> child[c - 'a'] == nullptr)
        {
            return false;
        }
        curr = curr -> child[c - 'a'];
    }
    return true;
}

int main(){
    TrieNode* root = new TrieNode();
    vector<string> arr = {"and", "ant", "do", "geek", "dad", "ball"};
    for(auto it: arr)
    {
        insertKey(root, it);
    }

    vector<string>searchKeys = {"do", "gee", "bat"};
    for(string s: searchKeys)
    {
        if(searchKey(root, s))
        {
            cout <<"Present:"<<" "<< s <<"\n";
        }
        else{
            cout <<"Not Present:"<<" "<< s << "\n";
        }
    }
    return 0;
}