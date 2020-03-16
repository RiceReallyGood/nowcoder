struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
		val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead){
        ListNode *fast = pHead, *slow = pHead;
        do{
            if(fast && fast->next) fast = fast->next->next;
            else return nullptr;

            slow = slow->next;
        }while(fast != slow);
        fast = pHead;
        while(fast != slow){
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};