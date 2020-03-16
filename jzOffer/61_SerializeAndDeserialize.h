#include <string>
#include <cstring>
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
    char* Serialize(TreeNode *root) {    
        string s;
        PreOrderTraversal(root, s);
        char *ret = new char[s.length() + 1];
        strcpy(ret, s.data());
        return ret;
    }
    TreeNode* Deserialize(char *str) {
        string s(str);
        int index = 0;
        return Constructor(s, index);
    }

private:
    void PreOrderTraversal(TreeNode *root, string& s){
        if(!root)
            s += "#,";
        else{
            s += to_string(root->val) + ',';
            PreOrderTraversal(root->left, s);
            PreOrderTraversal(root->right, s);
        }
    }

    TreeNode* Constructor(const string& str, int& index){
        if(str[index] == '#'){
            index += 2;
            return nullptr;
        }
        int nextindex = index;
        while(str[nextindex] != ',') nextindex++;
        TreeNode* root = new TreeNode(stoi(str.substr(index, nextindex - index)));
        index = nextindex + 1;
        root->left = Constructor(str, index);
        root->right = Constructor(str, index);
        return root;
    }
};