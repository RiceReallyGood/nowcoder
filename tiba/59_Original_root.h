#include <vector>
#include <string>
#include <cstring>
using namespace std;

class Solution {
public:
    int solve(int n, vector<string>& s) {
        TrieNode* root = new TrieNode();

        for(int i = 0; i < s.size(); i++){
            TrieNode *node = root;
            bool foundprefix = false;
            for(int j = 0; j < s[i].length(); j++){
                if(node->isword){
                    foundprefix = true;
                    break;
                }
                if(node->next[s[i][j] - 'a'] == nullptr)
                    node->next[s[i][j] - 'a'] = new TrieNode();
                node = node->next[s[i][j] - 'a'];
            }

            if(!foundprefix){
                if(node->isword)
                    node->redundant = true;
                else
                    node->isword = true;
            }
        }

        int res = count(root);
        destroyTrie(root);
        return res;
    }

private:
    class TrieNode{
    public:
        TrieNode() : isword(false), redundant(false) {
            memset(next, 0, 26 * sizeof(TrieNode*));
        }
        bool isword;
        bool redundant;
        TrieNode* next[26];
    };

    int count(TrieNode* node){
        if(node == nullptr) return 0;
        if(node->isword)
            return node->redundant ? 0 : 1;
        
        int res = 0;
        for(int i = 0; i < 26; i++){
            res += count(node->next[i]);
        }
        return res;
    }

    void destroyTrie(TrieNode* node){
        if(node == nullptr) return;

        for(int i = 0; i < 26; i++)
            destroyTrie(node->next[i]);
        
        delete node;
    }
};