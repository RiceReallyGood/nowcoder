#include <cmath>
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
    bool IsBalanced_Solution(TreeNode* pRoot) {
        return BalancesTreeHeight(pRoot) != -1;
    }

private:
    int BalancesTreeHeight(TreeNode* pRoot){
        if(!pRoot) return 0;
        int lefth = BalancesTreeHeight(pRoot->left);
        int righth = BalancesTreeHeight(pRoot->right);
        if(lefth == -1 || righth == -1 || std::abs(lefth - righth) > 1)
            return -1;
        return std::max(lefth, righth) + 1;
    }
};