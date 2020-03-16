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
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(!pRoot2) return false;
        if(!pRoot1) return false;
        return IsSubtree(pRoot1, pRoot2) || HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
    }

private:
    bool IsSubtree(TreeNode* root1, TreeNode* root2){
        if(!root2) return true;
        if(!root1) return false;
        return root1->val == root2->val && IsSubtree(root1->left, root2->left) && IsSubtree(root1->right, root2->right);
    }
};