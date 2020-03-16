#include <unordered_set>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
		val(x), next(nullptr) {}
};

class Solution {  //O(n) space
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        unordered_set<ListNode*> nodes;
        while(pHead1){
            nodes.insert(pHead1);
            pHead1 = pHead1->next;
        }

        while(pHead2){
            if(nodes.find(pHead2) != nodes.end())
                return pHead2;
            pHead2 = pHead2->next;
        }

        return pHead2;
    }
};

class Solution {  //O(1) space
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        ListNode *p1 = pHead1, *p2 = pHead2;
        int len1 = 0, len2 = 0;
        while(p1){
            len1++;
            p1 = p1->next;
        }

        while(p2){
            len2++;
            p2 = p2->next;
        }

        p1 = pHead1, p2 = pHead2;
        if(len1 > len2){
            for(int i = 0; i < len1 - len2; i++)
                p1 = p1->next;
        }
        else{
            for(int i = 0; i < len2 - len1; i++)
                p2 = p2->next;
        }

        while(p1){
            if(p1 == p2)
                return p1;
            p1 = p1->next;
            p2 = p2->next;
        }
        return nullptr;
    }
};