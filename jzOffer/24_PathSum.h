#include <vector>
#include <algorithm>
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
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int>> ret;
        vector<int> path;
        if(!root) return ret;
        Recurse(root, expectNumber, path, ret);
        sort(ret.begin(), ret.end(), [](const vector<int>& v1, const vector<int>& v2){
            return v1.size() > v2.size();
        });
        return ret;
    }

private:
    void Recurse(TreeNode* node, int target, vector<int>& path, vector<vector<int>>& validpaths){
        path.push_back(node->val);
        target -= node->val;
        if(!node->left && !node->right){
            if(target == 0)
                validpaths.push_back(path);
            path.pop_back();
            return;
        }
        if(node->left)
            Recurse(node->left, target, path, validpaths);
        if(node->right)
            Recurse(node->right, target, path, validpaths);
        path.pop_back();
    }
};