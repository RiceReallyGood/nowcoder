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
    TreeNode* KthNode(TreeNode* pRoot, int k){
        return Recurse(pRoot, k);
    }

private:
    TreeNode* Recurse(TreeNode* root, int& k){
        if(!root) return nullptr;
        TreeNode* candidate = Recurse(root->left, k);
        if(candidate) return candidate;
        if((--k) == 0) return root;
        return Recurse(root->right, k);
    }
};