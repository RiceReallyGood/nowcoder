#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(nullptr), right(nullptr) {
	}
};

class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int>> ret;
        queue<TreeNode*> q;
        if(pRoot) q.push(pRoot);
        int level = 0;
        while(!q.empty()){
            ret.push_back(vector<int>());
            int levelsize = q.size();
            for(int i = 0; i < levelsize; i++){
                TreeNode* node = q.front();
                q.pop();
                ret[level].push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            level++;
        }
        return ret;
    }
};