#include <unordered_map>
using namespace std;

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(nullptr), random(nullptr) {
    }
};

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(!pHead) return nullptr;
        unordered_map<RandomListNode*, RandomListNode*> nodemap;
        RandomListNode* node = pHead, *newnode = new RandomListNode(pHead->label);
        nodemap[node] = newnode;
        while(node->next){
            newnode->next = new RandomListNode(node->next->label);
            nodemap[node->next] = newnode->next;
            node = node->next;
            newnode = newnode->next;
        }

        node = pHead, newnode = nodemap[node];
        while(node){
            newnode->random = nodemap[node->random];
            node = node->next;
            newnode = newnode->next;
        }
        return nodemap[pHead];
    }
};