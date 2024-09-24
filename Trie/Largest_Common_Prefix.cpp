// 3043. Find the Length of the Longest Common Prefix
// https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/

#include<bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    TrieNode* child[10];
    TrieNode()
    {
        for(int i = 0; i < 10; i++)
        {
            child[i] = nullptr;
        }
    }
};

class Trie{
public: 
    TrieNode* root;
    Trie()
    {
        root = new TrieNode();
    }
    void insertNumber(int n)
    {
        TrieNode* curr = root;
        string s = to_string(n);
        for(auto it: s)
        {
            int idx = it - '0';
            if(curr -> child[idx] == nullptr)
            {
                curr -> child[idx] = new TrieNode();
            }
            curr = curr -> child[idx];
        }
    }
    int findLongestPrefix(int n)
    {
        int len = 0;
        TrieNode* curr = root;
        string s = to_string(n);
        for(auto it: s)
        {
            int idx = it - '0';
            if(curr -> child[idx])
            {
                len++;
                curr = curr -> child[idx];
            }
            else{
                break;
            }
        }
        return len;
    }
};

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int ans = 0;
        Trie root;
        for(auto &it: arr1)
        {   
            root.insertNumber(it);
        }
        for(auto &it: arr2)
        {
            ans = max(ans, root.findLongestPrefix(it));
        }
        return ans;
    }
};

int main()
{
    Solution* sol = new Solution();
    vector<int>arr1 = {1, 10, 100};
    vector<int>arr2 = {1000};
    cout << sol -> longestCommonPrefix(arr1, arr2) <<"\n" ;
}