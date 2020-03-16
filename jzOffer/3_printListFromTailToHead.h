#include <vector>
using namespace std;

struct ListNode {
      int val;
      struct ListNode *next;
      ListNode(int x) :
            val(x), next(nullptr) {
      }
};

class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> ret;
        while(head){
            ret.push_back(head->val);
            head = head->next;
        }
        //reverse
        for(int i = 0, j = int(ret.size()) - 1; i < j; i++, j--)
            swap(ret[i], ret[j]);
        return ret;
    }
};