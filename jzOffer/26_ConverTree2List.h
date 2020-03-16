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
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        TreeNode* front = nullptr, *back = nullptr;
        ConverTree2List(pRootOfTree, front, back);
        return front;
    }

private:
    void ConverTree2List(TreeNode* root, TreeNode*& front, TreeNode*& back){
        if(!root) return;
        TreeNode* leftfront = nullptr, *leftback = nullptr;
        ConverTree2List(root->left, leftfront, leftback);
        TreeNode* rightfront = nullptr, *rightback = nullptr;
        ConverTree2List(root->right, rightfront, rightback);
        root->left = leftback;
        if(leftback) leftback->right = root;
        root->right = rightfront;
        if(rightfront) rightfront->left = root;

        if(leftfront) front = leftfront;
        else front = root;

        if(rightback) back = rightback;
        else back = root;
    }
};