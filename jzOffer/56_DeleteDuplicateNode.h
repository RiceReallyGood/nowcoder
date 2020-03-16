struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
		val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead){
        ListNode* dumhead = new ListNode(0);
        ListNode* prevnode = dumhead;
        while(pHead != nullptr){
            if(pHead->next && pHead->next->val == pHead->val){
                while(pHead->next && pHead->next->val == pHead->val)
                    pHead = pHead->next;
            }
            else{
                prevnode->next = pHead;
                prevnode = prevnode->next;
            }
            pHead = pHead->next;
        }
        prevnode->next = nullptr;
        return dumhead->next;
    }
};