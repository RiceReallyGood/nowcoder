struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
		val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        ListNode* p1 = nullptr, *p2 = pHead, *p3 = nullptr;
        while(p2){
            p3 = p2->next;
            p2->next = p1;
            p1 = p2;
            p2 = p3;
        }
        return p1;
    }
};