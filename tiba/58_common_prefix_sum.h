#include <vector>
#include <string>
#include <cstring>
using namespace std;

class Solution {
public:
    long long solve(int n, vector<string>& s) {
        this->root = new TrieNode();
        for(int i = 0; i < s.size(); i++)
            insert(s[i]);
        
        long long res = 0;
        for(int i = 0; i < 26; i++)
            res += dfs(root->next[i]);
        return res;
    }

private:
    class TrieNode{
    public:
        TrieNode() : count(1), next(26, nullptr) {}

        int count;
        vector<TrieNode*> next;
    };

    TrieNode* root;

    void insert(const string& s){
        TrieNode* node = root;
        for(int i = 0; i < s.length(); i++){
            if(node->next[s[i] - 'a'] == nullptr)
                node->next[s[i] - 'a'] = new TrieNode;
            else
                (node->next[s[i] - 'a'])->count++;
            
            node = node->next[s[i] - 'a'];
        }
    }

    long long dfs(TrieNode* node){
        if(node == nullptr || node->count == 1) return 0;
        long long res = 0;
        for(int i = 0; i < 26; i++){
            res += dfs(node->next[i]);
        }
        res += (long long)(node->count) * (long long)(node->count - 1) / 2ll;
        return res;
    }

    void destroyTrie(TrieNode* node){
        if(node == nullptr) return;

        for(int i = 0; i < 26; i++)
            destroyTrie(node->next[i]);
        
        delete node;
    }
};

class Solution {
public:
    long long solve(int n, vector<string>& s) {
        this->root = new TrieNode();
        long long res = 0;
        for(int i = 0; i < s.size(); i++){
            TrieNode* node = root;
            for(int j = 0; j < s[i].length(); j++){
                int idx = s[i][j] - 'a';
                if(node->next[idx] == nullptr)
                    node->next[idx] = new TrieNode();
                else{
                    res += node->next[idx]->count;
                    node->next[idx]->count++;
                }
                node = node->next[idx];
            }
        }
        destroyTrie(root);
        return res;
    }

private:
    class TrieNode{
    public:
        TrieNode() : count(1){
            memset(next, 0, 26 * sizeof(TrieNode*));
        }

        int count;
        TrieNode* next[26];
    };

    TrieNode* root;

    void destroyTrie(TrieNode* node){
        if(node == nullptr) return;

        for(int i = 0; i < 26; i++)
            destroyTrie(node->next[i]);
        
        delete node;
    }
};