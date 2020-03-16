#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        int N = pre.size();
        unordered_map<int, int> index;
        for(int i = 0; i < N; i++) index[vin[i]] = i;
        return recurse(pre, 0, N - 1, index, 0, N - 1);
    }

private:
    TreeNode* recurse(vector<int>& pre, int prei, int prej, unordered_map<int, int>& index, int ini, int inj){
        if(prei > prej) return nullptr;
        TreeNode* root = new TreeNode(pre[prei]);
        root->left = recurse(pre, prei + 1, prei + index[root->val] - ini, index, ini, index[root->val] - 1);
        root->right = recurse(pre, prei + index[root->val] - ini + 1, prej, index, index[root->val] + 1, inj);
        return root;
    }
};