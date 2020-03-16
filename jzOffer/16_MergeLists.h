struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
		val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        ListNode* dumhead = new ListNode(0);
        ListNode* lastnode = dumhead;
        while(pHead1 && pHead2){
            if(pHead1->val < pHead2->val){
                lastnode->next = pHead1;
                pHead1 = pHead1->next;
            }
            else{
                lastnode->next = pHead2;
                pHead2 = pHead2->next;
            }
            lastnode = lastnode->next;
        }
        if(pHead1) lastnode->next = pHead1;
        else lastnode->next = pHead2;
        lastnode = dumhead->next;
        delete dumhead;
        return lastnode;
    }
};