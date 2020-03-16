#include <algorithm>

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
    void Mirror(TreeNode *pRoot) {
        if(pRoot){
            Mirror(pRoot->left);
            Mirror(pRoot->right);
            std::swap(pRoot->left, pRoot->right);
        }
    }
};