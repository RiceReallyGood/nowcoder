
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(nullptr), right(nullptr), next(nullptr) {
        
    }
};

class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode){
        if(!pNode) return nullptr;
        if(pNode->right){
            pNode = pNode->right;
            while(pNode->left)
                pNode = pNode->left;
        }
        else{
            while(pNode->next && pNode->next->right == pNode)
                pNode = pNode->next;
            pNode = pNode->next;
        }
        return pNode;
    }
};