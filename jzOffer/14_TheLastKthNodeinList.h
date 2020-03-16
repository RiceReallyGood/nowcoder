struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
		val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        ListNode* fast = pListHead;
        for(int i = 0; i < k; i++) {
            if(!fast) return nullptr;
            fast = fast->next;
        }
        ListNode* slow = pListHead;
        while(fast){
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};