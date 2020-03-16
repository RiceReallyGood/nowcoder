#include <vector>
#include <stack>
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
        if(!pRoot) return vector<vector<int>>();
        stack<TreeNode*> s1, s2;
        s1.push(pRoot);
        vector<vector<int>> ret;
        while(!s1.empty()){
            vector<int> temp;
            while(!s1.empty()){
                TreeNode* node = s1.top();
                s1.pop();
                temp.push_back(node->val);
                if(node->left)
                    s2.push(node->left);
                if(node->right)
                    s2.push(node->right);
            }
            ret.push_back(temp);
            if(s2.empty()) break;
            temp.clear();
            while(!s2.empty()){
                TreeNode* node = s2.top();
                s2.pop();
                temp.push_back(node->val);
                if(node->right)
                    s1.push(node->right);
                if(node->left)
                    s1.push(node->left);
            }
            ret.push_back(temp);
        }
        return ret;
    } 
};