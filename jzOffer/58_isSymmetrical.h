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
    bool isSymmetrical(TreeNode* pRoot) {
        if(!pRoot) return true;
        return isMirror(pRoot->left, pRoot->right);
    }

private:
    bool isMirror(TreeNode* root1, TreeNode* root2){
        if(!root1 || !root2) return root1 == root2;
        return root1->val == root2->val && isMirror(root1->right, root2->left) && isMirror(root1->left, root2->right);
    }
};